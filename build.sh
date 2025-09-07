#!/bin/sh

function build_test()
{
  mkdir ./debug
  g++ -o ./debug/screate ./main.cpp ./classes/config.cpp ./classes/config.hpp ./classes/parser.hpp ./classes/parser.cpp && compiled=true
  if [[ "$compiled" == "true" ]] && [[ "$1" != "" ]]; then
    git add .
    git commit -m "$1" && git push
    exit 0
  else
    echo "Error: add commit message or fix code!"
    exit 1
  fi
}

function build_fin()
{
  mkdir ./release
  g++ -o ./debug/screate ./main.cpp ./classes/config.cpp ./classes/config.hpp ./classes/parser.hpp ./classes/parser.cpp && compiled=true
  if [[ "$compiled" == "true" ]] && [[ "$1" != "" ]]; then
    git add .
    git commit -m "$1" && git push
    exit 0
  else
    echo "Error: add commit message or fix code!"
    exit 1
  fi
}

case $1 in
release) build_fin $2 ;;
debug) build_test $2 ;;
esac
