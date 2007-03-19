#include "tcimptsource.h"

tcImportSource::tcImportSource()
{
}

tcImportSource::~tcImportSource()
{
}

QString tcImportSource::GetDescription()
{
	return "";
}

bool tcImportSource::HaveSettingDialog()
{
	return false;
}

void tcImportSource::ShowSettingDialog(QWidget *pParent)
{
}

bool tcImportSource::Import()
{
	return false;
}

#include "moc_tcimptsource.cpp"
