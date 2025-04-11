#pragma once

#define CMD_HELP 0
#define CMD_MV  1
#define CMD_MV1 2
#define CMD_STACK 3
#define CMD_UNSTACK 4
#define CMD_PEEK 5
#define CMD_LOG 6
#define CMD_INSTALL 7
#define CMD_UNINSTALL 8
#define CMD_UNSTACK1  9
#define CMD_LOG1 10
#define CMD_PEEK1 12
#define CMD_STACK1 13


#define dprintf(...) printf(__VA_ARGS__)

extern const int CHUNK_BYTE_SIZE;

extern long long cmds[64];

void stash(const char*);

void stashCur();

void pop(char* dst, int index);

void execCmds();

void ulog(int depth);
