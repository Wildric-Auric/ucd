#include "ospec.h"

//Define in as preprocessor macro or here
//#define WIN_IMPL
//#define LINUX_IMPL

#ifdef WIN_IMPL
#include <windows.h>
#endif
#ifdef LINUX_IMPL
#include <sys/stat.h>
#include <unistd.h>
#endif

extern const int CHUNK_BYTE_SIZE;

void getCurDir(char* dst) {
#ifdef WIN_IMPL
    GetCurrentDirectoryA(CHUNK_BYTE_SIZE, dst);
#endif
#ifdef LINUX_IMPL
    getcwd(dst, CHUNK_BYTE_SIZE);
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
#ifdef LINUX_IMPL
    struct stat st;
    if (stat(path, &st) != 0) return -1;
    return st.st_size;
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
#ifdef LINUX_IMPL
    int s = getFileSize(path);
    int ret = truncate(path, s - CHUNK_BYTE_SIZE * index);
    if (ret != 0) return -1;
    return 0;
#endif
    return 0;
}

osbool isDirectory(const char* dir) {
#ifdef WIN_IMPL
    DWORD fattrib = GetFileAttributesA(dir);
    return fattrib != INVALID_FILE_ATTRIBUTES 
       && (fattrib & FILE_ATTRIBUTE_DIRECTORY);
#endif
#ifdef LINUX_IMPL
    struct stat st;
    int ret = stat(dir, &st);
    if (ret != 0) return -1;
    return S_ISDIR(st.st_mode);
#endif
    return 0;
}
