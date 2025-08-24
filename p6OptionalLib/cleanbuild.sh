#!/bin/sh

# Clean and recreate build directory
rm -rf build
rm -rf include
rm -rf lib
rm -rf share

mkdir build
cd build

# Configure project (.. points to source dir)
cmake .. -DUSE_ADDER=ON -DCMAKE_INSTALL_PREFIX="C:\\Users\\NoNeo\\OneDrive\\Desktop\\learningcmake\\p6OptionalLib\\"

# Build with whatever generator was used
if [ -f build.ninja ]; then
    ninja
    ninja install
    echo "Install through ninja."

elif [ -f Makefile ]; then
    make
    make install
    echo "Install through make."

else
    echo "No known build system generated!"
    exit 1
fi

# Go back to project root
cd ..

# Run helper scripts (if they exist)
./run.sh
