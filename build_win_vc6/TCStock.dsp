# Microsoft Developer Studio Project File - Name="TCStock" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=TCStock - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TCStock.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TCStock.mak" CFG="TCStock - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TCStock - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "TCStock - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TCStock - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 user32.lib qtmain.lib QtCore4.lib QtGui4.lib QtXml4.lib QtNetwork4.lib QtOpenGL4.lib /nologo /subsystem:windows /machine:I386 /out:"../bin/TCStock.exe"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 user32.lib QtCore4.lib QtGui4.lib QtXml4.lib QtNetwork4.lib QtOpenGL4.lib /nologo /subsystem:console /debug /machine:I386 /out:"../bin/TCStock.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "TCStock - Win32 Release"
# Name "TCStock - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\resource.rc
# End Source File
# Begin Source File

SOURCE=..\source\tcaboutdlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\tcdailyviewwgt.cpp
# End Source File
# Begin Source File

SOURCE=..\source\tcmain.cpp
# End Source File
# Begin Source File

SOURCE=..\source\tcmainwnd.cpp
# End Source File
# Begin Source File

SOURCE=..\source\tcweeklyviewwgt.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\source\tcaboutdlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source
InputPath=..\source\tcaboutdlg.h

"$(InputDir)/moc_tcaboutdlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcaboutdlg.h -o $(InputDir)/moc_tcaboutdlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\tcdailyviewwgt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source
InputPath=..\source\tcdailyviewwgt.h

"$(InputDir)/moc_tcdailyviewwgt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcdailyviewwgt.h -o $(InputDir)/moc_tcdailyviewwgt.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\tcdefine.h
# End Source File
# Begin Source File

SOURCE=..\source\tcmainwnd.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source
InputPath=..\source\tcmainwnd.h

"$(InputDir)/moc_tcmainwnd.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcmainwnd.h -o $(InputDir)/moc_tcmainwnd.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\tcresource.h
# End Source File
# Begin Source File

SOURCE=..\source\tcweeklyviewwgt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source
InputPath=..\source\tcweeklyviewwgt.h

"$(InputDir)/moc_tcweeklyviewwgt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcweeklyviewwgt.h -o $(InputDir)/moc_tcweeklyviewwgt.cpp

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "stock"

# PROP Default_Filter ""
# Begin Group "stock_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\stock\tcmarket.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stock
InputPath=..\source\stock\tcmarket.h

"$(InputDir)/moc_tcmarket.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcmarket.h -o $(InputDir)/moc_tcmarket.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stock\tcmarketinfodlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stock
InputPath=..\source\stock\tcmarketinfodlg.h

"$(InputDir)/moc_tcmarketinfodlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcmarketinfodlg.h -o $(InputDir)/moc_tcmarketinfodlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stock\tcmarketlistdlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stock
InputPath=..\source\stock\tcmarketlistdlg.h

"$(InputDir)/moc_tcmarketlistdlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcmarketlistdlg.h -o $(InputDir)/moc_tcmarketlistdlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stock\tcmarketmgr.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stock
InputPath=..\source\stock\tcmarketmgr.h

"$(InputDir)/moc_tcmarketmgr.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcmarketmgr.h -o $(InputDir)/moc_tcmarketmgr.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stock\tcmarketselectdlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stock
InputPath=..\source\stock\tcmarketselectdlg.h

"$(InputDir)/moc_tcmarketselectdlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcmarketselectdlg.h -o $(InputDir)/moc_tcmarketselectdlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstock.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stock
InputPath=..\source\stock\tcstock.h

"$(InputDir)/moc_tcstock.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstock.h -o $(InputDir)/moc_tcstock.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockdata.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stock
InputPath=..\source\stock\tcstockdata.h

"$(InputDir)/moc_tcstockdata.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockdata.h -o $(InputDir)/moc_tcstockdata.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockdatacache.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stock
InputPath=..\source\stock\tcstockdatacache.h

"$(InputDir)/moc_tcstockdatacache.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockdatacache.h -o $(InputDir)/moc_tcstockdatacache.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockdatainfodlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stock
InputPath=..\source\stock\tcstockdatainfodlg.h

"$(InputDir)/moc_tcstockdatainfodlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockdatainfodlg.h -o $(InputDir)/moc_tcstockdatainfodlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockdataitemdlt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stock
InputPath=..\source\stock\tcstockdataitemdlt.h

"$(InputDir)/moc_tcstockdataitemdlt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockdataitemdlt.h -o $(InputDir)/moc_tcstockdataitemdlt.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockdataitemmdl.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stock
InputPath=..\source\stock\tcstockdataitemmdl.h

"$(InputDir)/moc_tcstockdataitemmdl.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockdataitemmdl.h -o $(InputDir)/moc_tcstockdataitemmdl.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockinfo.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stock
InputPath=..\source\stock\tcstockinfo.h

"$(InputDir)/moc_tcstockinfo.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockinfo.h -o $(InputDir)/moc_tcstockinfo.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockinfodlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stock
InputPath=..\source\stock\tcstockinfodlg.h

"$(InputDir)/moc_tcstockinfodlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockinfodlg.h -o $(InputDir)/moc_tcstockinfodlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockpack.h
# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockselectdlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stock
InputPath=..\source\stock\tcstockselectdlg.h

"$(InputDir)/moc_tcstockselectdlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockselectdlg.h -o $(InputDir)/moc_tcstockselectdlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "stock_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\stock\tcmarket.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stock\tcmarketinfodlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stock\tcmarketlistdlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stock\tcmarketmgr.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stock\tcmarketselectdlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstock.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockdata.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockdatacache.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockdatainfodlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockdataitemdlt.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockdataitemmdl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockinfo.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockinfodlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stock\tcstockselectdlg.cpp
# End Source File
# End Group
# End Group
# Begin Group "service"

# PROP Default_Filter ""
# Begin Group "service_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\service\tccfgsvc.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\service
InputPath=..\source\service\tccfgsvc.h

"$(InputDir)/moc_tccfgsvc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tccfgsvc.h -o $(InputDir)/moc_tccfgsvc.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\service\tclogsvc.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\service
InputPath=..\source\service\tclogsvc.h

"$(InputDir)/moc_tclogsvc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tclogsvc.h -o $(InputDir)/moc_tclogsvc.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\service\tcobjsvc.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\service
InputPath=..\source\service\tcobjsvc.h

"$(InputDir)/moc_tcobjsvc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcobjsvc.h -o $(InputDir)/moc_tcobjsvc.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\service\tcsvcpack.h
# End Source File
# End Group
# Begin Group "service_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\service\tccfgsvc.cpp
# End Source File
# Begin Source File

SOURCE=..\source\service\tclogsvc.cpp
# End Source File
# Begin Source File

SOURCE=..\source\service\tcobjvc.cpp
# End Source File
# End Group
# End Group
# Begin Group "stockview"

# PROP Default_Filter ""
# Begin Group "stockview_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\stockview\tcstockscene.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stockview
InputPath=..\source\stockview\tcstockscene.h

"$(InputDir)/moc_tcstockscene.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockscene.h -o $(InputDir)/moc_tcstockscene.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockview\tcstockview.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stockview
InputPath=..\source\stockview\tcstockview.h

"$(InputDir)/moc_tcstockview.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockview.h -o $(InputDir)/moc_tcstockview.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockview\tcstockviewdef.h
# End Source File
# Begin Source File

SOURCE=..\source\stockview\tcstockviewpack.h
# End Source File
# Begin Source File

SOURCE=..\source\stockview\tcviewentity.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stockview
InputPath=..\source\stockview\tcviewentity.h

"$(InputDir)/moc_tcviewentity.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcviewentity.h -o $(InputDir)/moc_tcviewentity.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockview\tcviewentitygroup.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stockview
InputPath=..\source\stockview\tcviewentitygroup.h

"$(InputDir)/moc_tcviewentitygroup.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcviewentitygroup.h -o $(InputDir)/moc_tcviewentitygroup.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockview\tcviewquantity.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stockview
InputPath=..\source\stockview\tcviewquantity.h

"$(InputDir)/moc_tcviewquantity.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcviewquantity.h -o $(InputDir)/moc_tcviewquantity.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockview\tcviewquantitygroup.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stockview
InputPath=..\source\stockview\tcviewquantitygroup.h

"$(InputDir)/moc_tcviewquantitygroup.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcviewquantitygroup.h -o $(InputDir)/moc_tcviewquantitygroup.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockview\tcviewstockgroup.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stockview
InputPath=..\source\stockview\tcviewstockgroup.h

"$(InputDir)/moc_tcviewstockgroup.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcviewstockgroup.h -o $(InputDir)/moc_tcviewstockgroup.cpp

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "stockview_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\stockview\tcstockscene.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockview\tcstockview.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockview\tcviewentity.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockview\tcviewentitygroup.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockview\tcviewquantity.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockview\tcviewquantitygroup.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockview\tcviewstockgroup.cpp
# End Source File
# End Group
# End Group
# Begin Group "stocklistwgt"

# PROP Default_Filter ""
# Begin Group "stocklistwgt_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\stocklistwgt\tcstocklistallwgt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stocklistwgt
InputPath=..\source\stocklistwgt\tcstocklistallwgt.h

"$(InputDir)/moc_tcstocklistallwgt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstocklistallwgt.h -o $(InputDir)/moc_tcstocklistallwgt.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stocklistwgt\tcstocklistfavtwgt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stocklistwgt
InputPath=..\source\stocklistwgt\tcstocklistfavtwgt.h

"$(InputDir)/moc_tcstocklistfavtwgt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstocklistfavtwgt.h -o $(InputDir)/moc_tcstocklistfavtwgt.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stocklistwgt\tcstocklistwgt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\stocklistwgt
InputPath=..\source\stocklistwgt\tcstocklistwgt.h

"$(InputDir)/moc_tcstocklistwgt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstocklistwgt.h -o $(InputDir)/moc_tcstocklistwgt.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stocklistwgt\tcstocklistwgtpack.h
# End Source File
# End Group
# Begin Group "stocklistwgt_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\stocklistwgt\tcstocklistallwgt.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stocklistwgt\tcstocklistfavtwgt.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stocklistwgt\tcstocklistwgt.cpp
# End Source File
# End Group
# End Group
# Begin Group "viewmodel"

# PROP Default_Filter ""
# Begin Group "viewmodel_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\viewmodel\tcdailyviewmodel.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\viewmodel
InputPath=..\source\viewmodel\tcdailyviewmodel.h

"$(InputDir)/moc_tcdailyviewmodel.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcdailyviewmodel.h -o $(InputDir)/moc_tcdailyviewmodel.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\viewmodel\tcmonthlyviewmodel.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\viewmodel
InputPath=..\source\viewmodel\tcmonthlyviewmodel.h

"$(InputDir)/moc_tcmonthlyviewmodel.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcmonthlyviewmodel.h -o $(InputDir)/moc_tcmonthlyviewmodel.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\viewmodel\tcviewmodel.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\viewmodel
InputPath=..\source\viewmodel\tcviewmodel.h

"$(InputDir)/moc_tcviewmodel.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcviewmodel.h -o $(InputDir)/moc_tcviewmodel.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\viewmodel\tcviewmodelpack.h
# End Source File
# Begin Source File

SOURCE=..\source\viewmodel\tcweekly2viewmodel.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\viewmodel
InputPath=..\source\viewmodel\tcweekly2viewmodel.h

"$(InputDir)/moc_tcweekly2viewmodel.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcweekly2viewmodel.h -o $(InputDir)/moc_tcweekly2viewmodel.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\viewmodel\tcweeklyviewmodel.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\viewmodel
InputPath=..\source\viewmodel\tcweeklyviewmodel.h

"$(InputDir)/moc_tcweeklyviewmodel.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcweeklyviewmodel.h -o $(InputDir)/moc_tcweeklyviewmodel.cpp

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "viewmodel_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\viewmodel\tcdailyviewmodel.cpp
# End Source File
# Begin Source File

SOURCE=..\source\viewmodel\tcmonthlyviewmodel.cpp
# End Source File
# Begin Source File

SOURCE=..\source\viewmodel\tcviewmodel.cpp
# End Source File
# Begin Source File

SOURCE=..\source\viewmodel\tcweekly2viewmodel.cpp
# End Source File
# Begin Source File

SOURCE=..\source\viewmodel\tcweeklyviewmodel.cpp
# End Source File
# End Group
# End Group
# Begin Group "importer"

# PROP Default_Filter ""
# Begin Group "importer_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\importer\tcimporterpack.h
# End Source File
# Begin Source File

SOURCE=..\source\importer\tcqianlongimpt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\importer
InputPath=..\source\importer\tcqianlongimpt.h

"$(InputDir)/moc_tcqianlongimpt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcqianlongimpt.h -o $(InputDir)/moc_tcqianlongimpt.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\importer\tcsinastockdataimpt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\importer
InputPath=..\source\importer\tcsinastockdataimpt.h

"$(InputDir)/moc_tcsinastockdataimpt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcsinastockdataimpt.h -o $(InputDir)/moc_tcsinastockdataimpt.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\importer\tcstockinfoimpt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\importer
InputPath=..\source\importer\tcstockinfoimpt.h

"$(InputDir)/moc_tcstockinfoimpt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockinfoimpt.h -o $(InputDir)/moc_tcstockinfoimpt.cpp

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "importer_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\importer\tcqianlongimpt.cpp
# End Source File
# Begin Source File

SOURCE=..\source\importer\tcsinastockdataimpt.cpp
# End Source File
# Begin Source File

SOURCE=..\source\importer\tcstockinfoimpt.cpp
# End Source File
# End Group
# End Group
# Begin Group "favourite"

# PROP Default_Filter ""
# Begin Group "favourite_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\favourite\tcfavouritegroupinfodlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\favourite
InputPath=..\source\favourite\tcfavouritegroupinfodlg.h

"$(InputDir)/moc_tcfavouritegroupinfodlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfavouritegroupinfodlg.h -o $(InputDir)/moc_tcfavouritegroupinfodlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\favourite\tcfavouritegrp.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\favourite
InputPath=..\source\favourite\tcfavouritegrp.h

"$(InputDir)/moc_tcfavouritegrp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfavouritegrp.h -o $(InputDir)/moc_tcfavouritegrp.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\favourite\tcfavouriteinfodlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\favourite
InputPath=..\source\favourite\tcfavouriteinfodlg.h

"$(InputDir)/moc_tcfavouriteinfodlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfavouriteinfodlg.h -o $(InputDir)/moc_tcfavouriteinfodlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\favourite\tcfavouritemgr.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\favourite
InputPath=..\source\favourite\tcfavouritemgr.h

"$(InputDir)/moc_tcfavouritemgr.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfavouritemgr.h -o $(InputDir)/moc_tcfavouritemgr.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\favourite\tcfavouritepack.h
# End Source File
# Begin Source File

SOURCE=..\source\favourite\tcfavouritestockdlt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\favourite
InputPath=..\source\favourite\tcfavouritestockdlt.h

"$(InputDir)/moc_tcfavouritestockdlt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfavouritestockdlt.h -o $(InputDir)/moc_tcfavouritestockdlt.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\favourite\tcfavouritestockinfo.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\favourite
InputPath=..\source\favourite\tcfavouritestockinfo.h

"$(InputDir)/moc_tcfavouritestockinfo.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfavouritestockinfo.h -o $(InputDir)/moc_tcfavouritestockinfo.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\favourite\tcfavouritestockmdl.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\TCStock\001\source\favourite
InputPath=..\source\favourite\tcfavouritestockmdl.h

"$(InputDir)/moc_tcfavouritestockmdl.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfavouritestockmdl.h -o $(InputDir)/moc_tcfavouritestockmdl.cpp

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "favourite_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\favourite\tcfavouritegroupinfodlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\favourite\tcfavouritegrp.cpp
# End Source File
# Begin Source File

SOURCE=..\source\favourite\tcfavouriteinfodlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\favourite\tcfavouritemgr.cpp
# End Source File
# Begin Source File

SOURCE=..\source\favourite\tcfavouritestockdlt.cpp
# End Source File
# Begin Source File

SOURCE=..\source\favourite\tcfavouritestockinfo.cpp
# End Source File
# Begin Source File

SOURCE=..\source\favourite\tcfavouritestockmdl.cpp
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=.\Question.ico
# End Source File
# End Target
# End Project
