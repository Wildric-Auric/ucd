#define CMD_HELP 0
#define CMD_MV  1
#define CMD_MV1 2


extern long long cmds[64];

void mexec(const char* cmd,...);

void stash(const char*);

void stashCur();

void pop(char* dst, int index);

void execCmds();
