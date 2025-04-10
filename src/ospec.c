#include "ospec.h"
#define WIN_IMPL
//#define LINUX_IMPL

#ifdef WIN_IMPL
#include <windows.h>
#endif

extern const int CHUNK_BYTE_SIZE;

void getCurDir(char* dst) {
#ifdef WIN_IMPL
    GetCurrentDirectoryA(CHUNK_BYTE_SIZE, dst);
#endif
}

int getFileSize(const char* path) {
#ifdef WIN_IMPL
    WIN32_FIND_DATA fd;
    HANDLE h = FindFirstFileA(path, &fd);
    if (h == INVALID_HANDLE_VALUE) return -1;
    FindClose(h);
    return fd.nFileSizeLow;  
#endif 
    return 0;
}

int truncFile(const char* path,int index) {
#ifdef WIN_IMPL
    int s = getFileSize(path);
    HANDLE h = CreateFileA(
        path, GENERIC_WRITE, 0, NULL, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    if (h==INVALID_HANDLE_VALUE) return -1;
    SetFilePointer(h, s - CHUNK_BYTE_SIZE * index, 0, FILE_BEGIN);
    SetEndOfFile(h);
    CloseHandle(h);
    return 0;
#endif 
    return 0;
}

int createFile(const char* path) {
#ifdef WIN_IMPL
    HANDLE h = CreateFileA(
        path,
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    if (h == INVALID_HANDLE_VALUE) return -1;
    return 0;
#endif
    return 0;
}

int createDirectory(const char* dir) {
#ifdef WIN_IMPL
    CreateDirectory(dir, 0); 
    return 1;
#endif
    return 1;
}

int createPath(const char* path) {
#ifdef WIN_IMPL
    createDirectory(path);
    createFile(path);
#endif
    return 0;
}

osbool isDirectory(const char* dir) {
#ifdef WIN_IMPL
    DWORD fattrib = GetFileAttributesA(dir);
    return fattrib != INVALID_FILE_ATTRIBUTES 
       && (fattrib & FILE_ATTRIBUTE_DIRECTORY);
#endif
    return 0;
}
