@echo off
title qmake and  build prompt
set QTDIR=C:\Qt\Qt5.6.0\5.6\mingw49_32\bin
set PATH=%QTDIR%;%PATH% 
call "%QTDIR%\qtenv2.bat"
qmake.exe D:\Xpro_ReleaseHead\tool\Winproladder2\src\project_treeview\test.pro -r -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
mingw32-make.exe in D:\Xpro_ReleaseHead\tool\Winproladder2\src\output

