# Microsoft Developer Studio Project File - Name="TCStock" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=TCStock - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "TCStock.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "TCStock.mak" CFG="TCStock - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "TCStock - Win32 Release" ("Win32 (x86) Console Application" 用)
!MESSAGE "TCStock - Win32 Debug" ("Win32 (x86) Console Application" 用)
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
InputDir=\source\tcstock\002\source
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
InputDir=\source\tcstock\002\source
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
InputDir=\source\tcstock\002\source
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
InputDir=\source\tcstock\002\source
InputPath=..\source\tcweeklyviewwgt.h

"$(InputDir)/moc_tcweeklyviewwgt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcweeklyviewwgt.h -o $(InputDir)/moc_tcweeklyviewwgt.cpp

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "stockinfo"

# PROP Default_Filter ""
# Begin Group "stockinfo_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\stockinfo\tcfavtgrp.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcfavtgrp.h

"$(InputDir)/moc_tcfavtgrp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfavtgrp.h -o $(InputDir)/moc_tcfavtgrp.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcfavtgrpinfodlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcfavtgrpinfodlg.h

"$(InputDir)/moc_tcfavtgrpinfodlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfavtgrpinfodlg.h -o $(InputDir)/moc_tcfavtgrpinfodlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcfavtinfodlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcfavtinfodlg.h

"$(InputDir)/moc_tcfavtinfodlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfavtinfodlg.h -o $(InputDir)/moc_tcfavtinfodlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcfavtinfodlt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcfavtinfodlt.h

"$(InputDir)/moc_tcfavtinfodlt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfavtinfodlt.h -o $(InputDir)/moc_tcfavtinfodlt.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcfavtinfomdl.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcfavtinfomdl.h

"$(InputDir)/moc_tcfavtinfomdl.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfavtinfomdl.h -o $(InputDir)/moc_tcfavtinfomdl.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcfavtmgr.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcfavtmgr.h

"$(InputDir)/moc_tcfavtmgr.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfavtmgr.h -o $(InputDir)/moc_tcfavtmgr.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcmarket.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcmarket.h

"$(InputDir)/moc_tcmarket.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcmarket.h -o $(InputDir)/moc_tcmarket.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcmarketinfodlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcmarketinfodlg.h

"$(InputDir)/moc_tcmarketinfodlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcmarketinfodlg.h -o $(InputDir)/moc_tcmarketinfodlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcmarketlistdlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcmarketlistdlg.h

"$(InputDir)/moc_tcmarketlistdlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcmarketlistdlg.h -o $(InputDir)/moc_tcmarketlistdlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcmarketmgr.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcmarketmgr.h

"$(InputDir)/moc_tcmarketmgr.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcmarketmgr.h -o $(InputDir)/moc_tcmarketmgr.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcmarketselectdlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcmarketselectdlg.h

"$(InputDir)/moc_tcmarketselectdlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcmarketselectdlg.h -o $(InputDir)/moc_tcmarketselectdlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcnullstock.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcnullstock.h

"$(InputDir)/moc_tcnullstock.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcnullstock.h -o $(InputDir)/moc_tcnullstock.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstock.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcstock.h

"$(InputDir)/moc_tcstock.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstock.h -o $(InputDir)/moc_tcstock.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockdata.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcstockdata.h

"$(InputDir)/moc_tcstockdata.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockdata.h -o $(InputDir)/moc_tcstockdata.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockdatacache.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcstockdatacache.h

"$(InputDir)/moc_tcstockdatacache.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockdatacache.h -o $(InputDir)/moc_tcstockdatacache.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockdatainfodlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcstockdatainfodlg.h

"$(InputDir)/moc_tcstockdatainfodlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockdatainfodlg.h -o $(InputDir)/moc_tcstockdatainfodlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockdataitemdlt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcstockdataitemdlt.h

"$(InputDir)/moc_tcstockdataitemdlt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockdataitemdlt.h -o $(InputDir)/moc_tcstockdataitemdlt.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockdataitemmdl.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcstockdataitemmdl.h

"$(InputDir)/moc_tcstockdataitemmdl.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockdataitemmdl.h -o $(InputDir)/moc_tcstockdataitemmdl.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockinfo.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcstockinfo.h

"$(InputDir)/moc_tcstockinfo.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockinfo.h -o $(InputDir)/moc_tcstockinfo.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockinfodlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcstockinfodlg.h

"$(InputDir)/moc_tcstockinfodlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockinfodlg.h -o $(InputDir)/moc_tcstockinfodlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockinfolst.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcstockinfolst.h

"$(InputDir)/moc_tcstockinfolst.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockinfolst.h -o $(InputDir)/moc_tcstockinfolst.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockinfopack.h
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockmgr.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcstockmgr.h

"$(InputDir)/moc_tcstockmgr.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockmgr.h -o $(InputDir)/moc_tcstockmgr.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockselectdlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\stockinfo
InputPath=..\source\stockinfo\tcstockselectdlg.h

"$(InputDir)/moc_tcstockselectdlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstockselectdlg.h -o $(InputDir)/moc_tcstockselectdlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "stockinfo_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\stockinfo\tcfavtgrp.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcfavtgrpinfodlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcfavtinfodlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcfavtinfodlt.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcfavtinfomdl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcfavtmgr.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcmarket.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcmarketinfodlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcmarketlistdlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcmarketmgr.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcmarketselectdlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcnullstock.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstock.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockdata.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockdatacache.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockdatainfodlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockdataitemdlt.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockdataitemmdl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockinfo.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockinfodlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockinfolst.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockmgr.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stockinfo\tcstockselectdlg.cpp
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
InputDir=\source\tcstock\002\source\service
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
InputDir=\source\tcstock\002\source\service
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
InputDir=\source\tcstock\002\source\service
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

SOURCE=..\source\service\tcobjsvc.cpp
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
InputDir=\source\tcstock\002\source\stockview
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
InputDir=\source\tcstock\002\source\stockview
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
InputDir=\source\tcstock\002\source\stockview
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
InputDir=\source\tcstock\002\source\stockview
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
InputDir=\source\tcstock\002\source\stockview
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
InputDir=\source\tcstock\002\source\stockview
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
InputDir=\source\tcstock\002\source\stockview
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
# Begin Group "viewmodel"

# PROP Default_Filter ""
# Begin Group "viewmodel_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\viewmodel\tcdailyviewmodel.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\viewmodel
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
InputDir=\source\tcstock\002\source\viewmodel
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
InputDir=\source\tcstock\002\source\viewmodel
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
InputDir=\source\tcstock\002\source\viewmodel
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
InputDir=\source\tcstock\002\source\viewmodel
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
InputDir=\source\tcstock\002\source\importer
InputPath=..\source\importer\tcqianlongimpt.h

"$(InputDir)/moc_tcqianlongimpt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcqianlongimpt.h -o $(InputDir)/moc_tcqianlongimpt.cpp

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "importer_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\importer\tcqianlongimpt.cpp
# End Source File
# End Group
# End Group
# Begin Group "toolpad"

# PROP Default_Filter ""
# Begin Group "toolpad_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\toolpad\tcstocklistwgt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\toolpad
InputPath=..\source\toolpad\tcstocklistwgt.h

"$(InputDir)/moc_tcstocklistwgt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcstocklistwgt.h -o $(InputDir)/moc_tcstocklistwgt.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\toolpad\tctoolpadpack.h
# End Source File
# Begin Source File

SOURCE=..\source\toolpad\tctoolpadwgt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\toolpad
InputPath=..\source\toolpad\tctoolpadwgt.h

"$(InputDir)/moc_tctoolpadwgt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tctoolpadwgt.h -o $(InputDir)/moc_tctoolpadwgt.cpp

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "toolpad_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\toolpad\tcstocklistwgt.cpp
# End Source File
# Begin Source File

SOURCE=..\source\toolpad\tctoolpadwgt.cpp
# End Source File
# End Group
# End Group
# Begin Group "dataimpt"

# PROP Default_Filter ""
# Begin Group "dataimpt_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\dataimpt\tcdataimpt.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\dataimpt
InputPath=..\source\dataimpt\tcdataimpt.h

"$(InputDir)/moc_tcdataimpt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcdataimpt.h -o $(InputDir)/moc_tcdataimpt.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcdataimptpack.h
# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcdataimptsetupdlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\dataimpt
InputPath=..\source\dataimpt\tcdataimptsetupdlg.h

"$(InputDir)/moc_tcdataimptsetupdlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcdataimptsetupdlg.h -o $(InputDir)/moc_tcdataimptsetupdlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcfxjfileimptsource.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\dataimpt
InputPath=..\source\dataimpt\tcfxjfileimptsource.h

"$(InputDir)/moc_tcfxjfileimptsource.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfxjfileimptsource.h -o $(InputDir)/moc_tcfxjfileimptsource.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcfxjfileimptsourcedlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\dataimpt
InputPath=..\source\dataimpt\tcfxjfileimptsourcedlg.h

"$(InputDir)/moc_tcfxjfileimptsourcedlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcfxjfileimptsourcedlg.h -o $(InputDir)/moc_tcfxjfileimptsourcedlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcimptprogressdlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\dataimpt
InputPath=..\source\dataimpt\tcimptprogressdlg.h

"$(InputDir)/moc_tcimptprogressdlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcimptprogressdlg.h -o $(InputDir)/moc_tcimptprogressdlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcimptsource.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\dataimpt
InputPath=..\source\dataimpt\tcimptsource.h

"$(InputDir)/moc_tcimptsource.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcimptsource.h -o $(InputDir)/moc_tcimptsource.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcqianlongfileimptsource.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\dataimpt
InputPath=..\source\dataimpt\tcqianlongfileimptsource.h

"$(InputDir)/moc_tcqianlongfileimptsource.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcqianlongfileimptsource.h -o $(InputDir)/moc_tcqianlongfileimptsource.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcsinawebimptsource.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\dataimpt
InputPath=..\source\dataimpt\tcsinawebimptsource.h

"$(InputDir)/moc_tcsinawebimptsource.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcsinawebimptsource.h -o $(InputDir)/moc_tcsinawebimptsource.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcsinawebimptsourcedlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\dataimpt
InputPath=..\source\dataimpt\tcsinawebimptsourcedlg.h

"$(InputDir)/moc_tcsinawebimptsourcedlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcsinawebimptsourcedlg.h -o $(InputDir)/moc_tcsinawebimptsourcedlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcyahoowebimptsource.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\dataimpt
InputPath=..\source\dataimpt\tcyahoowebimptsource.h

"$(InputDir)/moc_tcyahoowebimptsource.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcyahoowebimptsource.h -o $(InputDir)/moc_tcyahoowebimptsource.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcyahoowebimptsourcedlg.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\dataimpt
InputPath=..\source\dataimpt\tcyahoowebimptsourcedlg.h

"$(InputDir)/moc_tcyahoowebimptsourcedlg.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/tcyahoowebimptsourcedlg.h -o $(InputDir)/moc_tcyahoowebimptsourcedlg.cpp

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "dataimpt_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\dataimpt\tcdataimpt.cpp
# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcdataimptsetupdlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcfxjfileimptsource.cpp
# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcfxjfileimptsourcedlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcimptprogressdlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcimptsource.cpp
# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcqianlongfileimptsource.cpp
# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcsinawebimptsource.cpp
# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcsinawebimptsourcedlg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcyahoowebimptsource.cpp
# End Source File
# Begin Source File

SOURCE=..\source\dataimpt\tcyahoowebimptsourcedlg.cpp
# End Source File
# End Group
# End Group
# Begin Group "thirdparty"

# PROP Default_Filter ""
# Begin Group "quazip"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\thirdparty\quazip\crypt.h
# End Source File
# Begin Source File

SOURCE=..\source\thirdparty\quazip\ioapi.c
# End Source File
# Begin Source File

SOURCE=..\source\thirdparty\quazip\ioapi.h
# End Source File
# Begin Source File

SOURCE=..\source\thirdparty\quazip\quazip.cpp
# End Source File
# Begin Source File

SOURCE=..\source\thirdparty\quazip\quazip.h
# End Source File
# Begin Source File

SOURCE=..\source\thirdparty\quazip\quazipfile.cpp
# End Source File
# Begin Source File

SOURCE=..\source\thirdparty\quazip\quazipfile.h

!IF  "$(CFG)" == "TCStock - Win32 Release"

!ELSEIF  "$(CFG)" == "TCStock - Win32 Debug"

# Begin Custom Build
InputDir=\source\tcstock\002\source\thirdparty\quazip
InputPath=..\source\thirdparty\quazip\quazipfile.h

"$(InputDir)/moc_quazipfile.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc -i $(InputDir)/quazipfile.h -o $(InputDir)/moc_quazipfile.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\source\thirdparty\quazip\quazipfileinfo.h
# End Source File
# Begin Source File

SOURCE=..\source\thirdparty\quazip\quazipnewinfo.cpp
# End Source File
# Begin Source File

SOURCE=..\source\thirdparty\quazip\quazipnewinfo.h
# End Source File
# Begin Source File

SOURCE=..\source\thirdparty\quazip\unzip.c
# End Source File
# Begin Source File

SOURCE=..\source\thirdparty\quazip\unzip.h
# End Source File
# Begin Source File

SOURCE=..\source\thirdparty\quazip\zip.c
# End Source File
# Begin Source File

SOURCE=..\source\thirdparty\quazip\zip.h
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=.\Question.ico
# End Source File
# End Target
# End Project
