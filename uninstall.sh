#!/bin/bash

rm "${UCD_PATH}/_internal_ucd"

sed -i '/^ucd() {/,/^}/d' ~/.bashrc
sed -i '/^export UCD_PATH=/d' ~/.bashrc
