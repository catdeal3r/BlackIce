#!/bin/sh

echo "[i] Compiling lastest version ..."
g++ -o ./compiled/scr ./main.cpp ./classes/config.cpp ./classes/config.hpp ./classes/parser.hpp ./classes/parser.cpp ./classes/compiler.hpp ./classes/compiler.cpp && compiled=true

if [[ "$compiled" != "true" ]]; then
    echo "[!] Compilation failed. Errors are above."
    exit 1
fi

echo "[*] Compilation successful! You can find the newly compiled program at `./compiled/scr`."
exit 0