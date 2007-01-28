cd ../source
qmake -project
cd ../i18n
lupdate ../source/source.pro -ts tcstock.ts -noobsolete
lrelease tcstock.ts -qm tcstock.qm
copy tcstock.qm ..\bin\tcstock.qm

pause
