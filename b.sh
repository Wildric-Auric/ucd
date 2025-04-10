#!/bin/bash

set -e  # Exit on error

clang -Os ./src/*.c -o _internal_ucd
