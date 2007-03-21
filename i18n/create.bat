qmake -project ../source -o tcstock.pro
lupdate tcstock.pro -ts tcstock.ts -noobsolete
lrelease tcstock.ts -qm tcstock.qm
copy tcstock.qm ..\bin\tcstock.qm

pause
