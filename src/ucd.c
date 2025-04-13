#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "ospec.h"
#include "ucd.h"

const int CHUNK_BYTE_SIZE = 512;

char* cachePath = 0;
char* pathPath  = 0;

long long cmds[64] = {0};

void stash(const char* st) {
    char s[CHUNK_BYTE_SIZE];
    char c = 0; int i = 0; int p = 0;
    FILE* f;
    while ((c=st[i++]))
        s[p++] = c;
    s[p] = 0;
 
    f = fopen(cachePath, "ab");
    fwrite(s, sizeof(char), CHUNK_BYTE_SIZE, f);
    fclose(f);
}

void stashCur() {
    char dir[CHUNK_BYTE_SIZE];
    dir[0] = 0;
    getCurDir(dir);
    stash(dir);
}

void pop(char* dst, int index) {
    FILE* f;
    int fs = getFileSize(cachePath);
    truncFile(cachePath,index);
    f = fopen(cachePath, "rb"); 
    fseek(f, (fs-index*CHUNK_BYTE_SIZE) - CHUNK_BYTE_SIZE, 0);
    fread(dst, sizeof(char), CHUNK_BYTE_SIZE, f);
    fclose(f);
    truncFile(cachePath,1);
}

void saveMoveDir(const char* dst) {
    FILE* f = fopen(pathPath, "wb");
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
    saveMoveDir(dst);
}

void peek(int index) {
    char dst[CHUNK_BYTE_SIZE];
    dst[0] = 0;
    FILE* f;
    int fs = getFileSize(cachePath);
    int offset = fs - (index+1) * CHUNK_BYTE_SIZE;

    f = fopen(cachePath, "rb");
    fseek(f, offset, 0);
    fread(dst, sizeof(char), CHUNK_BYTE_SIZE, f);
    fclose(f);
    
    saveMoveDir(dst);

}

void ulog(int depth) {
    char txt[CHUNK_BYTE_SIZE];
    FILE* f;
    int fs  = getFileSize(cachePath);
    int off = (depth < 0) ? 0 : fs - depth * CHUNK_BYTE_SIZE;
    int len = fs / CHUNK_BYTE_SIZE;
    int offidx = (depth < 0 || depth >= len) ? 0 : fs / CHUNK_BYTE_SIZE - depth;
    f = fopen(cachePath, "rb");
    fseek(f, off, 0);
    for (int i = 0; i < len && (i < depth || depth < 0) ; ++i) { 
        fread(txt, sizeof(char), CHUNK_BYTE_SIZE, f);
        printf("%d: %s\n", len-1-i-offidx, txt);
    } 
    fclose(f);
}

extern void displayHelpMsg();
void execCmds() {
    if (cmds[CMD_HELP] == 1) {
        displayHelpMsg();
        return;
    }

    if (cmds[CMD_STACK] == 1) {
        if (cmds[CMD_STACK1]) {
            stash((const char*)cmds[CMD_STACK1]);
        }
        else
            stashCur();
    }

    if (cmds[CMD_MV] == 1) {
        saveMoveDir((const char*)cmds[CMD_MV1]);
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
