#include "front.h"
#include <stdio.h>

extern char*  cachePath; 
extern char*  pathPath;

int main(int argc, char** argv) {
    cachePath = argv[1];
    pathPath  = argv[2];
    if (argc < 3) {
        printf("This is an internal utility, call ucd.bat instead.");
        return 0;
    }
    sendCmd(argc-2, argv + 2);
    return 0;
}
