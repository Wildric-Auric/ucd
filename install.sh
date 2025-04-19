#!/bin/bash

UCD_PATH="$1"
if [ -z "$1" ]; then
    echo "You need to pass directory of installation as first argument"
    exit 2
fi

if [ ! -d "$UCD_PATH" ]; then
    echo "Error: '$UCD_PATH' is not recognized as path."
    exit 1
fi

SRC_BIN="./_internal_ucd"

if [ -f "${UCD_PATH}_internal_ucd" ]; then
    SRC_BIN="${UCD_PATH}_internal_ucd" 
fi

if [ ! -f "$SRC_BIN" ]; then
    echo "Error: Binary not found, you need to recompile or get the binary."
    exit 3
fi

# Detect the shell using the SHELL environment variable
case "$SHELL" in
    */zsh)
        SHELL_RC="$HOME/.zshrc"
        ;;
    */bash)
        SHELL_RC="$HOME/.bashrc"
        ;;
    *)
        echo "Unsupported shell. Please use bash or zsh."
        exit 4
        ;;
esac

# Remove existing ucd function and UCD_PATH export from the shell configuration file
sed -i '/^ucd() {/,/^}/d' "$SHELL_RC"
sed -i '/^export UCD_PATH=/d' "$SHELL_RC"

# Move the binary to the target directory
mv "$SRC_BIN" "$UCD_PATH/_internal_ucd"

# Append the new ucd function and UCD_PATH export to the shell configuration file
cat <<EOF >> "$SHELL_RC"
export UCD_PATH="$UCD_PATH";
ucd() {
    origin="\$HOME/.local/share/ucd/"
    cachePath="\${origin}ucd"
    pathPath="\${origin}tmp"

    mkdir -p "\$origin"
    [ -f "\$cachePath" ] || touch "\$cachePath"
    [ -f "\$pathPath" ] || touch "\$pathPath"

    "${UCD_PATH}/_internal_ucd" "\$cachePath" "\$pathPath" "\$@"

    l=""
    if [ -s "\$pathPath" ]; then
        l=\$(<"\$pathPath")
        if [ -n "\$l" ]; then
            cd "\$l" || echo "Failed to cd into \$l"
        fi
    fi
    : > "\$pathPath"
}
EOF

echo "Installation is successful. Please restart your shell or run 'source $SHELL_RC' to apply changes."