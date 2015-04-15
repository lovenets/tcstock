编译前，请确认你的系统中安装了 Qt4.2 或以上的版本，目前的程序在 Qt4.2.1 版本上可以顺利编译运行，但是不保证其他版本上的正确性。

# Windows 平台 #

> 使用 VC6 打开 build\_win\_vc6 目录下的 TCStock.dsw 文件即可开始编译。
> 如果使用的是VS2003或VS2005，请导入 TCStock.dsw 文件后再进行编译，（可能需要手工设置一下）。
> 使用其他编译器，请将 source 目录下的所有文件加入工程后进行编译，并且不要忘记设置 moc 。

# Linux 平台 #

> 打开控制台后执行以下指令，生成 Qt 的工程文件：
> > cd build\_linux
> > qmake -project ../source tcstock.pro

> 然后，用文本编辑器打开 tcstock.pro 文件，在“TARGET = tcstock”后插入一行，内容为：
> > QT += xml network

> 代表编译需要使用 Qt 的 xml 和 network 模块。
> 继续执行以下指令：
> > qmake

> 该命令会在 build\_linux 目录下生成 Makefile 文件，用文本编辑器打开该 Makefile 文件，并查找到 “####### Compile”行处，（并非“####### Compile, tools and options”），在其下方插入新的内容：
> > moc