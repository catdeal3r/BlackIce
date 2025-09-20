#!/bin/sh

# edit these to change where the program is installed to
COMPILE_LOC="./compile/scr"
INSTALL_LOC="/usr/bin/scr"

[ ! -d "$(dirname $COMPILE_LOC)" ] && mkdir "$(dirname $COMPILE_LOC)"

echo "[i] Compiling lastest version ..."
g++ -o "$COMPILE_LOC" ./main.cpp ./classes/config.cpp ./classes/config.hpp ./classes/parser.hpp ./classes/parser.cpp ./classes/compiler.hpp ./classes/compiler.cpp && compiled="true"

if [[ "$compiled" != "true" ]]; then
    echo "[!] Compilation failed. Errors are above."
    exit 1
fi

echo "[*] Compilation successful! You can find the newly compiled program at `${COMPILE_LOC}`."

if [[ "$1" != "install" ]]; then
    exit 0
fi

echo "[i] Going on to stage two: install."

# copy program to correct paths based on distro
distro="undetected"

if [ -f /etc/os-release ]; then
    . /etc/os-release
    distro=$NAME
elif [ -f /etc/lsb-release ]; then
    . /etc/lsb-release
    distro=$DISTRIB_ID
fi

if [[ "$distro" == "NixOS" ]] || [[ "$distro" == "undetected" ]]; then
    echo "[!] Unable to install as distribution is unsupported. Detected distribution is: $distro"
    exit 1
fi

echo "[i] Asking for higher privileges to copy executable to `$(dirname $INSTALL_LOC)` ..."
sudo cp $COMPILE_LOC $INSTALL_LOC
echo "[*] Install successful!"