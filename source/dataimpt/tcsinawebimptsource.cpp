#include "tcsinawebimptsource.h"

#include <QtCore/QUrl>

#include <QtGui/QApplication>

#include "../service/tcsvcpack.h"
#include "../stockinfo/tcstockinfopack.h"

tcSinaWebImportSource::tcSinaWebImportSource()
{
	mHttp = NULL;
}

QString tcSinaWebImportSource::GetDescription()
{
	return tr("sina stock (http://stock.sina.com.cn)");
}

bool tcSinaWebImportSource::HaveSettingDialog()
{
	return true;
}

void tcSinaWebImportSource::ShowSettingDialog(QWidget *pParent)
{
}

bool tcSinaWebImportSource::Import()
{
	mHttp = new QHttp();
	connect(mHttp, SIGNAL(done(bool)), this, SLOT(DoHttpDone(bool)));

	QString useproxy = tcCfgService::GetGlobalAttribute("UseProxy", "false");
	if (useproxy == "true") {
		/*
		QString proxyserver = tcCfgService::GetGlobalAttribute("ProxyServer", "");
		QString proxyport = tcCfgService::GetGlobalAttribute("ProxyPort", "80");
		QString proxyusername = tcCfgService::GetGlobalAttribute("ProxyUserName", "");
		QString proxypassword = tcCfgService::GetGlobalAttribute("ProxyPassword", "");
		*/
		QString proxyserver = "192.168.6.1";
		QString proxyport = "6437";
		QString proxyusername = "guxiaodong";
		QString proxypassword = "omron99";
		mHttp->setProxy(proxyserver, proxyport.toInt(), proxyusername, proxypassword);
	}

	QString urltemplate = tcCfgService::GetAttribute(this, "UrlTemplate", "http://stock.sina.com.cn/stock/quote/sha%1.html");
	int startpage = tcCfgService::GetAttribute(this, "StartPage", "0").toInt();
	int endpage = tcCfgService::GetAttribute(this, "EndPage", "16").toInt();
	int i;
	for (i=startpage; i<=endpage; i++) {
		if (! ProcessForOnePage(urltemplate.arg(i))) {
			return false;
		}
		emit OnUpdateProgress(i*100 / (endpage-startpage));
	}
	
	delete mHttp;
	mHttp = NULL;

	OnAppendMessage(tr("All done."), true);
	return true;
}

bool tcSinaWebImportSource::ProcessForOnePage(const QString &pPageUrl)
{
	emit OnAppendMessage(tr("Begin import from page: %1.").arg(pPageUrl), true);

	QUrl url(pPageUrl);
	mHttp->setHost(url.host(), url.port() != -1 ? url.port() : 80);
	if (! url.userName().isEmpty()) {
		mHttp->setUser(url.userName(), url.password());
	}
	
	mIsReceiving = true;
	mHttp->get(url.path());

	while (mIsReceiving) {
		qApp->processEvents();
	}
	if (mReceivedData.isEmpty()) {
		return false;
	}

	QRegExp rx("<tr bgcolor=(?:\\S+) align=center><a name=(\\S+)></a>(.+)(?=</tr>)");
	rx.setMinimal(true);
	int pos = 0;
	while ((pos = rx.indexIn(mReceivedData, pos)) != -1) {
		ProcessForOneStock(rx.cap(2));
		pos += rx.matchedLength();
	}
	return true;
}

void tcSinaWebImportSource::ProcessForOneStock(const QString &pText)
{
	/* process the text like this:
		<td class=td04 height=23>!!<a href="http://finance.sina.com.cn/realstock/sh600004.html" target=_blank>600004</a></td>
		<td class=td06>!!ÅãÅ~OAÅ‚u3!</td>
		<td class=td06>12.26</td>
		<td class=td06>12.110</td>
		<td class=td06>11.780</td>
		<td class=td06>12.330</td>
		<td class=td06>11.610</td>
		<td class=td06><font color=#ff0020>0.15(1.24%)</font></td>
		<td class=td06>5274438</td>
		<td class=td06>63744700</td>
		<td class=td06>!!2007-03-19</td>
		<td class=td05>!!14:44:37</td>
	*/
	QRegExp rx("<.+>([^<>]+)</.+>");
	rx.setMinimal(true);
	int pos = 0;
	int itemindex = 0;
	QString stockcode, stockname, currentprice, closeprice, openprice, maxprice, minprice, quantity, totalprice, datestr, timestr;
	while ((pos = rx.indexIn(pText, pos)) != -1) {
		switch (itemindex) {
		case 0:	//stock code
			stockcode = rx.cap(1);
			break;
		case 1:	//stock name
			stockname = rx.cap(1);
			break;
		case 2:	//current price
			currentprice = rx.cap(1);
			break;
		case 3:	//close price (yesterday)
			closeprice = rx.cap(1);
			break;
		case 4:	//open price
			openprice = rx.cap(1);
			break;
		case 5:	//max price
			maxprice = rx.cap(1);
			break;
		case 6:	//min price
			minprice = rx.cap(1);
			break;
		case 7:	//up/down rate
			break;
		case 8:	//quantity
			quantity = rx.cap(1);
			break;
		case 9:	//total price
			totalprice = rx.cap(1);
			break;
		case 10:	//date
			datestr = rx.cap(1);
			break;
		case 11:	//time
			timestr = rx.cap(1);
			break;
		default:
			break;
		}
		pos += rx.matchedLength();
		itemindex++;
	}

	emit OnAppendMessage(tr("Processing stock %1 ...").arg(stockcode), true);

	if (itemindex <12) {
		emit OnAppendMessage(tr("Error when extract data of stock."), false);
		return;
	}

	//get the stock object
	tcStockManager *stockmanager = tcObjService::GetStockManager();
	tcStock *stock = stockmanager->GetStockByCode(stockcode);
	if (stock == NULL) {
		emit OnAppendMessage(tr("The stock not exists."), false);
		return;
	}

	//set the data of yesterday
	QDate date = QDate::fromString(datestr.right(10), "yyyy-MM-dd");
	date = date.addDays(-1);
	if (date.dayOfWeek() == 6) {
		date = date.addDays(-1);
	}
	else if (date.dayOfWeek() == 7) {
		date = date.addDays(-2);
	}

	tcStockDailyData dailydata;
	if (! stock->ReadData(date, &dailydata)) {
		emit OnAppendMessage(tr("Error when get daily data of stock."), false);
		return;
	}
	dailydata.ClosePrice = long(closeprice.toFloat() * 100);
	if (! stock->WriteData(date, &dailydata)) {
		emit OnAppendMessage(tr("Error when set daily data of stock."), false);
		return;
	}

	//set the data of today
	date = QDate::fromString(datestr.right(10), "yyyy-MM-dd");
	if (! stock->ReadData(date, &dailydata)) {
		emit OnAppendMessage(tr("Error when get daily data of stock."), false);
		return;
	}
	dailydata.OpenPrice = long(openprice.toFloat() * 100);
	dailydata.ClosePrice = long(currentprice.toFloat() * 100);
	dailydata.MaxPrice = long(maxprice.toFloat() * 100);
	dailydata.MinPrice = long(minprice.toFloat() * 100);
	dailydata.TotalPrice = totalprice.toLong() / 1000;
	dailydata.Quantity = quantity.toLong() / 1000;
	if (! stock->WriteData(date, &dailydata)) {
		emit OnAppendMessage(tr("Error when set daily data of stock."), false);
		return;
	}
}

void tcSinaWebImportSource::DoHttpDone(bool pError)
{
	if (pError) {
		tcLogService::CreateLog(this, "Done Error: " + mHttp->errorString());
		emit OnAppendMessage("Error: " + mHttp->errorString(), false);
	}
	else {
		Q_ASSERT(mHttp);
		mReceivedData = mHttp->readAll();
		emit OnAppendMessage(tr("Received successful."), true);
	}
	mIsReceiving = false;
}

#include "moc_tcsinawebimptsource.cpp"
