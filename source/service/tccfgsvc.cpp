#include "tccfgsvc.h"

#include <QtCore/QFileInfo>

#include "tclogsvc.h"

#define CONFIG_XML_FILE "config.xml"

tcCfgService* tcCfgService::mThis = NULL;

bool tcCfgService::Initialize(int argc, char* argv[])
{
	Q_ASSERT(! mThis);
	mThis = new tcCfgService(argc, argv);
	return true;
}

bool tcCfgService::Finalize()
{
	Q_ASSERT(mThis);
	delete mThis;
	mThis = NULL;
	return true;
}

QDomElement tcCfgService::GetElement(QObject *pObject)
{
	Q_ASSERT(mThis);
	return mThis->_GetElement(pObject);
}

tcCfgService::tcCfgService(int argc, char* argv[])
{
	QFileInfo fileinfo(argv[0]);
	mPath = fileinfo.absolutePath();
}

tcCfgService::~tcCfgService()
{
}

QDomElement tcCfgService::_GetElement(QObject *pObject)
{
	QDomElement element;
	QDomNode node = mRootElement.namedItem(pObject->metaObject()->className());
	if (! node.isElement()) {
		element = mDocument.createElement(pObject->metaObject()->className());
	}
	else {
		element = node.toElement();
	}
	return element;
}

bool tcCfgService::LoadFromFile()
{
	QFileInfo fileinfo(mPath, CONFIG_XML_FILE);
	QFile file(fileinfo.filePath());
	if (! file.open(QIODevice::ReadOnly)) {
		tcLogService::CreateLog(this, "Can not open config file.");
		return false;
	}

	if (! mDocument.setContent(&file, true)) {
		file.close();
		tcLogService::CreateLog(this, "Can not load config file.");
		return false;
	}
	file.close();

	mRootElement = mDocument.documentElement();
	return true;
}

bool tcCfgService::SaveToFile()
{
	return false;
}

#include "moc_tccfgsvc.cpp"


