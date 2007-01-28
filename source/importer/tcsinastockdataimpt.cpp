#include "tcsinastockdataimpt.h"

#include "../service/tcsvcpack.h"

tcSinaStockDataImporter::tcSinaStockDataImporter()
{
	connect(&mHttp, SIGNAL(requestFinished(int, bool)), this, SLOT(DoRequestFinished(int, bool)));
	connect(&mHttp, SIGNAL(done(bool)), this, SLOT(DoDone(bool)));
}

tcSinaStockDataImporter::~tcSinaStockDataImporter()
{
}

int tcSinaStockDataImporter::LoadStockData()
{
	/*
	mHttp.setProxy("202.202.202.3", 3128, "guxiaodong", "omron99");
	mHttp.setHost("stock.sina.com.cn");
	mHttp.get("/stock/quote/sha0.html");
	*/
	mHttp.setHost("localhost");
	mHttp.get("localstart.asp");
	return 0;
}

void tcSinaStockDataImporter::DoRequestFinished(int pId, bool pError)
{
	if (pError) {
		tcLogService::CreateLog(this, "Error" + mHttp.errorString());
	}
	else {
		QString s = mHttp.readAll();
		tcLogService::CreateLog(this, s);
	}
}

void tcSinaStockDataImporter::DoDone(bool pError)
{
	if (pError) {
		tcLogService::CreateLog(this, "Done Error" + mHttp.errorString());
	}
	else {
		tcLogService::CreateLog(this, "Done Success.");
	}
}

#ifdef WIN32
	#include "moc_tcsinastockdataimpt.cpp"
#endif
