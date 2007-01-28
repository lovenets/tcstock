#ifndef tccfgsvc_h

#define tccfgsvc_h

#include <QtCore/QVariant>
#include <QtCore/QObject>
#include <QtCore/QDir>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

/*! \brief tcCfgService
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.29
 	
	系统各种配置参数的管理类。
*/
class tcCfgService : public QObject
{
	Q_OBJECT

public:
	static bool Initialize(int argc, char* argv[]);

	static bool Finalize();

	static QDomElement GetElement(QObject *pObject);

protected:
	tcCfgService(int argc, char* argv[]);

	~tcCfgService();

	QDomElement _GetElement(QObject *pObject);

	bool LoadFromFile();

	bool SaveToFile();

private:
	static tcCfgService *mThis;

	QDir mPath;

	QDomDocument mDocument;

	QDomElement mRootElement;

};

#endif //tccfgsvc_h
