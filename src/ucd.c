
#include "ucd.h"
#include "ospec.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

const int CHUNK_BYTE_SIZE = 512;

char* cachePath = 0;
char* pathPath  = 0;

long long cmds[64] = {0};

void mexec(const char* cmd,...) {
    va_list args;
    char fnl[512]; 
    const char* arg;
    int p = 0;
    int i = 0;
    char c = 0;
    
    while ((c=cmd[i++])) {
        fnl[p++] = c;
    }
    va_start(args, cmd); 
    fnl[p++] = ' ';
    while ((arg=va_arg(args,const char*))) {
        i = 0;
        c = 0;
        while ((c=arg[i++])) {
            fnl[p++] = c;
        }
        fnl[p++] = ' '; 
    } 
    fnl[p] = 0;
    va_end(args);    
    system(fnl);
}

void stash(const char* st) {
    char s[CHUNK_BYTE_SIZE];
    char c = 0; int i = 0; int p = 0;
    FILE* f;
    while ((c=st[i++]))
        s[p++] = c;
    s[p] = 0;

    fopen_s(&f, cachePath, "ab");
    fwrite(s, sizeof(char), CHUNK_BYTE_SIZE, f);
    //fwrite("\n", sizeof(char), 1, f);
    fclose(f);
}

void stashCur() {
    char dir[CHUNK_BYTE_SIZE];
    dir[0] = 0;
    getCurDir(dir);
    printf("stahCur: %s | fileSize: %d\n", dir, getFileSize(cachePath));
    stash(dir);
}

void pop(char* dst, int index) {
    FILE* f;
    int fs = getFileSize(cachePath);
    truncFile(cachePath,index);
    fopen_s(&f, cachePath, "rb"); 
    fseek(f, (fs-index*CHUNK_BYTE_SIZE) - CHUNK_BYTE_SIZE, 0);
    fread(dst, sizeof(char), CHUNK_BYTE_SIZE, f);
    fclose(f);
    printf("pop trunc ret: %d\n", truncFile(cachePath,1)); 
}

void saveMoveDir(const char* dst) {
    FILE* f;
    fopen_s(&f, pathPath, "wb");
    char c;
    int i=0;
    while ((c=dst[i++])) {}
    fwrite(dst, sizeof(char), i-1, f);
    fclose(f);
}

void popAndSave(int index) {
    char dst[CHUNK_BYTE_SIZE];
    dst[0] = 0;
    pop(dst,index);
    printf("popAndSave path: %s\n", dst);
    saveMoveDir(dst);
}

void peek(int index) {
    char dst[CHUNK_BYTE_SIZE];
    dst[0] = 0;
    FILE* f;
    int fs = getFileSize(cachePath);
    int offset = fs - (index+1) * CHUNK_BYTE_SIZE;

    fopen_s(&f, cachePath, "rb");
    fseek(f, offset, 0);
    fread(dst, sizeof(char), CHUNK_BYTE_SIZE, f);
    fclose(f);
    
    saveMoveDir(dst);

}

void install() {
    createFile(cachePath);
    createFile(pathPath);
}

void uninstall() {
    remove("ucd.exe");
}

void ulog(int depth) {
    char txt[CHUNK_BYTE_SIZE];
    FILE* f;
    int fs  = getFileSize(cachePath);
    int off = (depth < 0) ? 0 : fs - depth * CHUNK_BYTE_SIZE;
    fopen_s(&f, cachePath, "rb");
    fseek(f, off, 0);
    for (int i = 0; i < fs / CHUNK_BYTE_SIZE && (i < depth || depth < 0) ; ++i) { 
        fread(txt, sizeof(char), CHUNK_BYTE_SIZE, f);
        printf("%d: %s\n", i, txt);
    } 
}

extern void displayHelpMsg();
void execCmds() {
    if (cmds[CMD_HELP] == 1) {
        displayHelpMsg();
        return;
    }
    if (cmds[CMD_INSTALL] == 1) {
        install();
        return;
    }
    if (cmds[CMD_UNINSTALL] == 1) {
        uninstall();
        return;
    }
    if (cmds[CMD_STACK] == 1) {
        if (cmds[CMD_MV] == 1) {
            stash((const char*)cmds[CMD_MV1]);
            return;
        }
        stashCur();
    }
    if (cmds[CMD_UNSTACK] == 1) {
        popAndSave(cmds[CMD_UNSTACK1]);
    }

    if (cmds[CMD_PEEK]) {
        peek(cmds[CMD_PEEK1]); 
    }

    if (cmds[CMD_LOG]) {
        ulog(cmds[CMD_LOG1]); 
    }
}
