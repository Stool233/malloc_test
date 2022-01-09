#!bin/bash
set -x
set -e
cd ./hook
gcc -shared -fPIC my_malloc.c -o my_malloc.so -ldl -std=c99
cd ..