#include "tctestimptsource.h"

tcTestImportSource::tcTestImportSource()
{
}

tcTestImportSource::~tcTestImportSource()
{
}

QString tcTestImportSource::GetDescription()
{
	return "just a test";
}

bool tcTestImportSource::Import()
{
	return false;
}

#include "moc_tctestimptsource.cpp"
