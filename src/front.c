#include "front.h"
#include "ucd.h"
#include "ospec.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static const char* generalMsg = 
""
"\n"
"Uber cd, a simple improved cd command to navigate quicker."  "\n"
"-------------------------------------------------"  "\n"
"Usage: "  "\n"
"    ucd [opt] \"directory\""  "\n"
"Example:"  "\n"
"    ucd --help"  "\n"
"    for more details."  "\n"
"\n"
"";

static const char* helpMsg= 
""
"\n"
"Uber cd, a simple improved cd command to navigate quicker."  "\n"
"-------------------------------------------------"  "\n"
"Usage: "  "\n"
"    ucd [opt] \"directory\""  "\n"
"opt:"  "\n"
"    -h | --help         show this help."  "\n"
"    -s | --stack [path] stack current directory if \"path\" is not passed or does not exist."  "\n"
"                        Otherwise \"path\" is stacked"  "\n"
"    -u | --unstack [n]  pop [n] last stacked directories. Then pop the next one and move to it."    "\n"
"    -l | --log  [n]     outputs [n] directories of the the stack, starting from the back."          "\n"
"                        If [n] is not passed, the whole stack is output."                           "\n"
"    -p | --peek [n]     Move to [n]'th (or last if not passed) directory of the stack without popping." "\n"
"\n"
"";

#define SCMP(a,b) (!strcmp(a,b))
#define SCMP2(a,b,c) SCMP(a,b) || SCMP(a,c)
void sendCmd(int n, char** c) {
    if (n <= 1) {
        displayGeneralMsg();
    }
    char dirPassed = 0;
    for (int i = 1; i < n; ++i) {
        if (SCMP2(c[i], "--help", "-h")) {
            cmds[CMD_HELP] = 1;
        }

        else if (SCMP2(c[i], "--stack", "-s")) {
            cmds[CMD_STACK] = 1;
            if (i+1 >= n) continue;
            const char* path = c[i+1];
            if (path[0] == '-') continue;
            if (!isDirectory(path)) continue;
            cmds[CMD_STACK1] = (long long)path;
            ++i;
        }
        
        else if (SCMP2(c[i], "--unstack", "-u")) {
            cmds[CMD_UNSTACK] = 1;
            if (i+1 >= n) continue;
            const char* num = c[i+1];
            if (num[0] == '-') continue;
            int ret = atoi(c[i+1]);
            if (ret == 0) continue;
            cmds[CMD_UNSTACK1] = ret;
            ++i;
        }

        else if (SCMP2(c[i], "--peek", "-p")) {
            cmds[CMD_PEEK] = 1;
            cmds[CMD_PEEK1] = 0;
            if (i+1 >= n) continue;
            const char* num = c[i+1];
            if (num[0] == '-') continue;
            int ret = atoi(c[i+1]);
            if (ret == 0) continue;
            cmds[CMD_PEEK1] = ret;
            ++i;
        }

        else if (SCMP2(c[i], "--log", "-l")) {
            cmds[CMD_LOG]  = 1;
            cmds[CMD_LOG1] = -1;
            if (i+1 >= n) continue;
            const char* num = c[i+1];
            if (num[0] == '-') continue;
            int ret = atoi(c[i+1]);
            if (ret == 0) continue;
            cmds[CMD_LOG1] = ret;
            ++i;
        }

        else if (SCMP(c[i], "--install")) {
            cmds[CMD_INSTALL] = 1;
        }

        else if (SCMP(c[i], "--uninstall")) {
            cmds[CMD_UNINSTALL] = 1;
        }

        else if (!dirPassed && isDirectory(c[i])) {
            cmds[CMD_MV]  = 1;
            cmds[CMD_MV1] = (long long)c[i];
            dirPassed = 1;
        }

        else {
            printf("Ignored unknown argument: %s\n", c[i]); 
        }
    }
    execCmds();
}

void displayHelpMsg() {
    printf("%s",helpMsg);
}

void displayGeneralMsg() {
    printf("%s",generalMsg);
}
