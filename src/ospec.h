#pragma once

typedef unsigned char osbool;

osbool isDirectory(const char* dir);

void getCurDir(char* dst);

int truncFile(const char* path,int index);

int getFileSize(const char* path);
