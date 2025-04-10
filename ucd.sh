#!/bin/bash

set -e  # Exit on error

origin="$HOME/.local/share/ucd/"
cachePath="${origin}ucd"
pathPath="${origin}tmp"

mkdir -p "$origin"
[ -f "$cachePath" ] || touch "$cachePath"
[ -f "$pathPath" ] || touch "$pathPath"

"$(dirname "$0")/_internal_ucd" "$cachePath" "$pathPath" "$@"

l=""
if [ -s "$pathPath" ]; then
    l=$(<"$pathPath")
    echo "$l"
    if [ -n "$l" ]; then
        cd "$l" || echo "Failed to cd into $l"
    fi
fi
# Empty the file
: > "$pathPath"
