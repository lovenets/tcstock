#include "tcdataimpt.h"

#include <QtXml/QDomElement>
#include "../service/tcsvcpack.h"
#include "tcdataimptsetupdlg.h"
#include "tcsinawebimptsource.h"
#include "tcimptprogressdlg.h"

#include "tctestimptsource.h"

tcDataImporter::tcDataImporter()
{
}

tcDataImporter::~tcDataImporter()
{
}

void tcDataImporter::ShowSetupDialog(QWidget *pParent)
{
	tcDataImporterSetupDialog dlg(pParent, this);
	dlg.exec();
}

bool tcDataImporter::Import(QWidget *pParent)
{
	tcImportSource *source = CreateImportSource(GetActiveSourceIndex());
	if (source == NULL) {
		tcLogService::CreateLog(this, "Error when create import source.");
		return false;
	}

	tcImportProgressDialog dlg(pParent, source);
	dlg.show();
	if (! source->Import()) {
		tcLogService::CreateLog(this, "Error when import.");
	}
	delete source;

	while (dlg.isVisible()) {
		qApp->processEvents();
	}
	return true;
}

tcImportSource* tcDataImporter::CreateImportSource(int pIndex)
{
	switch (pIndex) {
	case 0:
		return new tcSinaWebImportSource();
		break;
	case 1:
		return new tcTestImportSource();
		break;
	default:
		tcLogService::CreateLog(this, "The index of import source not correct.");
		return NULL;
	}
}

int tcDataImporter::GetActiveSourceIndex()
{
	return tcCfgService::GetAttribute(this, "ImportSourceIndex", "0").toInt();
}

void tcDataImporter::SetActiveSourceIndex(const int pIndex)
{
	QString sourceindex;
	sourceindex.setNum(pIndex);
	tcCfgService::SetAttribute(this, "ImportSourceIndex", sourceindex);
}


#include "moc_tcdataimpt.cpp"
