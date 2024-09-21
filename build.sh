#!/bin/bash

if [ ! -d build ]; then
  mkdir build
fi
cd build

"$HOME"/Qt/6.2.4/gcc_64/bin/qt-cmake ..

make

cd ..