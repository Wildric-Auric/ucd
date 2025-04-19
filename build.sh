#!/bin/bash
set -e 
clang -Os -DLINUX_IMPL ./src/*.c -o _internal_ucd
