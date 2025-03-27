#include "front.h"
#include "print.h"
#include "ucd.h"
#include <cstring>

static const char* generalMsg = 
R"V0G0N(
Uber cd, a simple improved cd command to navigate quicker.
-------------------------------------------------
Usage: 
    ucd [opt] "directory"
Example:
    ucd --help
    for more details.
)V0G0N";

static const char* helpMsg= 
R"V0G0N(
Uber cd, a simple improved cd command to navigate quicker.
-------------------------------------------------
Usage: 
    ucd [opt] "directory"
opt:
    --help      show this help.
    -s          stash current directory.
    -p [n]      pop [n]'th last stashed directory.
)V0G0N";

void sendCmd(int n, char** c) {
    if (n <= 1) {
        displayGeneralMsg();
    }
    char dirPassed = 0;
    for (int i = 1; i < n; ++i) {
        if (!strcmp(c[i], "--help")) {
            cmds[CMD_HELP] = 1;
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
