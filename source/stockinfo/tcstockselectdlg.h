#ifndef tcstockselectdlg_h

#define tcstockselectdlg_h

#include <QtCore/QVariant>
#include <QtGui/QDialog>
#include "ui_stockselectdlg.h"

#include "tcstockinfo.h"
#include "tcstockinfolst.h"

/*! \brief tcStockSelectDialog
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.26
 	
	��ʾ��Ʊ�б������û�����ѡ�񵥸�������Ʊ��ѡ�еĹ�Ʊ�� tcStockInfoList ��ʽ���ء�
*/
class tcStockSelectDialog : public QDialog , private Ui_tcStockSelectDialog
{
	Q_OBJECT

public:
	tcStockSelectDialog(QWidget *pParent);

	bool GetSelectedStockInfoList(tcStockInfoList &pStockInfoList);

protected slots:
	void DoMarketModified();

	void DoStockModified();

	void DoMarketIndexChanged(int pIndex);

	void DoFilterTextChanged(const QString &pText);

	void DoOk();

private:
	tcStockInfoList mViewStockInfoList;

};

#endif //tcstockselectdlg_h