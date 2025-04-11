@echo off
clang -Os -DWIN_IMPL -D_CRT_SECURE_NO_WARNINGS ./src/*.c -o _internal_ucd.exe
