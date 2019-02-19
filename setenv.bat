@echo off title qmake and nmake build prompt 
set QTDIR=C:\Qt\Qt5.6.0\5.6\mingw49_32\bin
set PATH=%QTDIR%;%PATH% 
call "%QTDIR%\qtenv2.bat"
cmd /k