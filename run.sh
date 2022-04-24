#!/bin/bash

mkdir build
cd build
cmake ../src
make
cd ..

echo START_GAME
./build/target
