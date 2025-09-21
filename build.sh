#!/bin/sh

mkdir ./debug
g++ -o ./debug/scr ./main.cpp ./classes/config.cpp ./classes/config.hpp ./classes/parser.hpp ./classes/parser.cpp ./classes/compiler.hpp ./classes/compiler.cpp && compiled=true
if [[ "$compiled" == "true" ]] && [[ "$1" != "" ]]; then
  git add .
  git commit -m "$1" && git push
  exit 0
else
  echo "Error: add commit message or fix code!"
  exit 1
fi

