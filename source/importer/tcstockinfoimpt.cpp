#include "tcstockinfoimpt.h"

#include <QtCore/QTextStream>

#include "../service/tcsvcpack.h"
#include "../stock/tcmarketmgr.h"

tcStockInfoImporter::tcStockInfoImporter()
{
}

tcStockInfoImporter::~tcStockInfoImporter()
{
}

int tcStockInfoImporter::LoadFromFile(const QString &pFileName, int pMarketIndex)
{
	QFile file(pFileName);
	if (! file.open(QFile::ReadOnly)) {
		tcLogService::CreateLog(this, "Error when open file.");
		return -1;
	}
	
	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	tcMarket*market = marketmanager->GetMarket(pMarketIndex);
	if (market == NULL) {
		return -1;
	}
	market->ClearAllStocks();

	QTextStream stream(&file);
	QString linestr;
	QStringList strlist;
	int count = 0;
	while (! stream.atEnd()) {
		linestr = stream.readLine();
		strlist = linestr.split(",");
		if (strlist.count() < 2) {
			continue;
		}
		tcStock *stock = market->AppendStock(strlist[0], strlist[1]);
		if (stock != NULL) {
			count++;
		}
	}
	market->SaveToFile();

	file.close();
	return count;
}

#ifdef WIN32
	#include "moc_tcstockinfoimpt.cpp"
#endif
