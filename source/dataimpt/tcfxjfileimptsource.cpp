#include "tcfxjfileimptsource.h"

#include <QtGui/QApplication>

#include "../service/tcsvcpack.h"
#include "../stockinfo/tcstockinfopack.h"
#include "tcfxjfileimptsourcedlg.h"

#pragma pack(push, 1)
typedef struct {
	char header[4];
	char market[2];
	char stockcode[6];
	float data1;
	float data2;
	float data3;
	float data4;
	float data5;
	float data6;
	float openprice;
	float maxprice;
	float minprice;
	float closeprice;
	float quantity;
	float totalprice;
	float reserved;
} fxjdata;
#pragma pack(pop)

tcFxjFileImportSource::tcFxjFileImportSource()
{
}

QString tcFxjFileImportSource::GetDescription()
{
	return tr("DAD file of fxj (http://www.fxj.net.cn)");
}

bool tcFxjFileImportSource::HaveSettingDialog()
{
	return true;
}

void tcFxjFileImportSource::ShowSettingDialog(QWidget *pParent)
{
	tcFxjFileImportSourceOption option;
	GetOptions(option);

	tcFxjFileImportSourceDialog dlg(pParent);
	if (! dlg.SetSettings(option)) {
		tcLogService::CreateLog(this, "Error when set dialog settings.");
		return;
	}
	if (dlg.exec() != QDialog::Accepted) {
		return;
	}
	if (! dlg.GetSettings(option)) {
		tcLogService::CreateLog(this, "Error when get dialog settings.");
		return;
	}
	SetOptions(option);
}

bool tcFxjFileImportSource::ImportProcess()
{
	mIsCanceling = false;

	tcFxjFileImportSourceOption option;
	GetOptions(option);
	if (option.DownloadZipFile) {
		emit OnAppendMessage(tr("This function not implemented yet."), false);
		//TODO: implement this
	}
	else {
		QDir dir(option.DataFilePath);
		QStringList filelist = dir.entryList(QDir::Files | QDir::Readable, QDir::Name | QDir::IgnoreCase);
		int i;
		for (i=0; i<filelist.count(); i++) {
			QFileInfo fileinfo(dir.absoluteFilePath(filelist[i]));
			QDate date = QDate::fromString(fileinfo.baseName(), "yyyyMMdd");
			ProcessOneFile(date, fileinfo.absoluteFilePath());
			if (mIsCanceling) {
				emit OnAppendMessage(tr("Import procedure canceled by user."), false);
				break;
			}
			emit OnUpdateProgress(i * 100 / filelist.count());
			qApp->processEvents();
		}
	}

	OnUpdateProgress(100);

	OnAppendMessage(tr("All done."), true);
	return true;
}

void tcFxjFileImportSource::CancelImportProcess()
{
	mIsCanceling = true;
}

void tcFxjFileImportSource::GetOptions(tcFxjFileImportSourceOption &pOption)
{
	pOption.DownloadZipFile = (tcCfgService::GetAttribute(this, "DownloadZipFile", "true") == "true");
	pOption.ZipFileUrl = tcCfgService::GetAttribute(this, "ZipFileUrl", "http://down.fxj.net.cn/sjdownload/day/%1.zip");
	pOption.DataFilePath = tcCfgService::GetAttribute(this, "DataFilePath", "");
}

void tcFxjFileImportSource::SetOptions(const tcFxjFileImportSourceOption &pOption)
{
	tcCfgService::SetAttribute(this, "DownloadZipFile", pOption.DownloadZipFile ? "true" : "false");
	tcCfgService::SetAttribute(this, "ZipFileUrl", pOption.ZipFileUrl);
	tcCfgService::SetAttribute(this, "DataFilePath", pOption.DataFilePath);
}

bool tcFxjFileImportSource::ProcessOneFile(const QDate &pDate, const QString &pFileName)
{
	emit OnAppendMessage(tr("Processing file: %1.").arg(pFileName), true);

	QFile file(pFileName);
	if (! file.open(QIODevice::ReadOnly)) {
		emit OnAppendMessage(tr("Error when open data file."), false);
		return false;
	}
	char fileheader[16];
	if (file.read(fileheader, sizeof(fileheader)) != sizeof(fileheader)) {
		emit OnAppendMessage(tr("Error when read file header."), false);
		return false;
	}
	if ((fileheader[0] != char(0x8c)) || (fileheader[1] != char(0x19)) || (fileheader[2] != char(0xfc)) || (fileheader[3] != char(0x33))) {
		emit OnAppendMessage(tr("Wrong DAD file format."), false);
		return false;
	}

	fxjdata data;
	QString stockcode;
	while (! file.atEnd()) {
		if (mIsCanceling) {
			break;
		}
		qApp->processEvents();

		if (file.read((char*)&data, sizeof(data)) != sizeof(data)) {
			emit OnAppendMessage(tr("Error when read data."), false);
			return false;
		}
		stockcode = data.stockcode;
		emit OnAppendMessage(tr("Processing stock %1 ...").arg(stockcode), true);

		tcStockInfo stockinfo(stockcode);
		if (! stockinfo.IsAvailable()) {
			emit OnAppendMessage(tr("The stock not exists."), false);
			continue;
		}
		tcStockDailyData dailydata;
		if (! stockinfo->ReadData(pDate, &dailydata)) {
			emit OnAppendMessage(tr("Error when get daily data of stock."), false);
			continue;
		}
		dailydata.OpenPrice = data.openprice * 100;
		dailydata.ClosePrice = data.closeprice * 100;
		dailydata.MaxPrice = data.maxprice * 100;
		dailydata.MinPrice = data.minprice * 100;
		dailydata.TotalPrice = data.totalprice / 1000;
		dailydata.Quantity = data.quantity;
		if (! stockinfo->WriteData(pDate, &dailydata)) {
			emit OnAppendMessage(tr("Error when set daily data of stock."), false);
			continue;
		}
	}
	return true;
}

#include "moc_tcfxjfileimptsource.cpp"
