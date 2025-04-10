@echo off


set "origin=%localappdata%/ucd/"
set "cachePath=%origin%ucd"
set "pathPath=%origin%tmp"

echo %origin%
if not exist "%origin%" mkdir "%origin%"
if not exist "%cachePath%" type nul > "%cachePath%"
if not exist "%pathPath%" type nul > "%pathPath%"

%~dp0/_internal_ucd.exe  %cachePath% %pathPath% %*
set "l="
set /p l=<%pathPath%
if defined l (
    cd %l%
)
type nul > "%pathPath%"

