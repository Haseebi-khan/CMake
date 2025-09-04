#!/bin/sh

mkdir build
cd build

cmake -S .. -B . -DUSE_ADDER=OFF

cmake --build .
cd build
./p7.exe