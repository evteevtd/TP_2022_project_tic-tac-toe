#!/bin/bash

$(mkdir build)
$(cd build; cmake)
$(cd build; make)
echo START_GAME
./build/target
