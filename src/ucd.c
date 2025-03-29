#include "ucd.h"
#include "ospec.h"
#include <cstdlib>
#include <stdarg.h>
#include <cstdio>
#include <cstring>

#define CHUNK_BYTE_SIZE 512

const char* cachePath = "./ucd";

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
    while (c=st[i++]) 
        s[p++] = c;
    s[p] = '0';

    fopen_s(&f, cachePath, "a");
    fwrite(s, sizeof(char), CHUNK_BYTE_SIZE, f);
    fwrite("\n", sizeof(char), 1, f);
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
    fopen_s(&f, cachePath, "r"); 
    fseek(f, fs - 512, 0);
    fread(dst, 1, CHUNK_BYTE_SIZE, f);
    fclose(f);
    truncFile(cachePath,1);
}

void install() {

}

void uninstall() {

}

void log(int depth) {
    char txt[CHUNK_BYTE_SIZE];
    FILE* f;
    int fs = getFileSize(cachePath);
    fopen_s(&f, cachePath, "r");
    for (int i = fs / CHUNK_BYTE_SIZE; i < fs / CHUNK_BYTE_SIZE; i) { 
        fread(txt, sizeof(char), CHUNK_BYTE_SIZE, f);
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
    if (cmds[CMD_LOG]) {
        log(0);
    }
}
