#include "front.h"
#include "print.h"
#include "ucd.h"
#include <string.h>

static const char* generalMsg = 
""
"Uber cd, a simple improved cd command to navigate quicker."  "\n"
"-------------------------------------------------"  "\n"
"Usage: "  "\n"
"    ucd [opt] \"directory\""  "\n"
"Example:"  "\n"
"    ucd --help"  "\n"
"    for more details."  "\n"
"";

static const char* helpMsg= 
""
"Uber cd, a simple improved cd command to navigate quicker."  "\n"
"-------------------------------------------------"  "\n"
"Usage: "  "\n"
"    ucd [opt] \"directory\""  "\n"
"opt:"  "\n"
"    --help      show this help."  "\n"
"    -s          stash current directory."  "\n"
"    -p [n]      pop [n]'th last stashed directory."  "\n"
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

        if (SCMP2(c[i], "--stack", "-s")) {
            cmds[CMD_STACK] = 1;
        }
        
        if (SCMP2(c[i], "--unstack", "-u")) {
            cmds[CMD_UNSTACK] = 1;
        }

        if (SCMP2(c[i], "--peek", "-p")) {
            cmds[CMD_PEEK] = 1;
        }

        if (SCMP2(c[i], "--log", "-l")) {
            cmds[CMD_LOG] = 1;
        }

        if (SCMP(c[i], "--install")) {
            cmds[CMD_INSTALL] = 1;
        }

        if (SCMP(c[i], "--uninstall")) {
            cmds[CMD_UNINSTALL] = 1;
        }

        else if (!dirPassed) {
            cmds[CMD_MV]  = 1;
            cmds[CMD_MV1] = (long long)c[i];
            dirPassed = 1;
        }

        else {
            printf("Ignored unknown argument: %s", c[i]); 
        }
    }
    execCmds();
}

void displayHelpMsg() {
    print(helpMsg);
}

void displayGeneralMsg() {
    print(generalMsg);
}
