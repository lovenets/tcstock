#include "tcsinastockdataimpt.h"

#include <QtCore/QUrl>

#include <QtCore/QFile>

#include "../service/tcsvcpack.h"

tcSinaStockDataImporter::tcSinaStockDataImporter()
{
	mHttp = new QHttp(this);
	connect(mHttp, SIGNAL(requestFinished(int, bool)), this, SLOT(DoRequestFinished(int, bool)));
	connect(mHttp, SIGNAL(done(bool)), this, SLOT(DoDone(bool)));
}

tcSinaStockDataImporter::~tcSinaStockDataImporter()
{
	delete mHttp;
}

int tcSinaStockDataImporter::LoadStockData()
{
	QUrl url("http://stock.sina.com.cn/stock/quote/sha0.html");
	mHttp->setHost(url.host(), url.port() != -1 ? url.port() : 80);
	if (! url.userName().isEmpty()) {
		mHttp->setUser(url.userName(), url.password());
	}
	mHttp->get(url.path());
	return 0;
}

void tcSinaStockDataImporter::DoRequestFinished(int pId, bool pError)
{
	if (pError) {
		tcLogService::CreateLog(this, "Error: " + mHttp->errorString());
	}
	else {
		QString s = mHttp->readAll();
		tcLogService::CreateLog(this, s);
	}
}

void tcSinaStockDataImporter::DoDone(bool pError)
{
	if (pError) {
		tcLogService::CreateLog(this, "Done Error: " + mHttp->errorString());
	}
	else {
		tcLogService::CreateLog(this, "Done Success.");
	}
}

#include "moc_tcsinastockdataimpt.cpp"
