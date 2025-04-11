#!/bin/bash

set -e  # Exit on error

clang -Os -DLINUX_IMPL ./src/*.c -o _internal_ucd
