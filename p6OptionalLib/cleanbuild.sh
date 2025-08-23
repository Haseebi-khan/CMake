#! /bin/sh

rm -rf build
mkdir build
cd build

cd ..

./configure.sh

./build.sh

./run.sh