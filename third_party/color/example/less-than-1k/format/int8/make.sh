#!/bin/bash

# Make all examples.
# No Scons, no CMake, no Make or any other make tool
# One line one example
# Designed for easy copy/paste

# TODO g++ $gccBaseSwitch $gccExtraSwitch -I../src akin.cpp                -o  akin

pwd

g++ $gccBaseSwitch $gccExtraSwitch -I../../../../src  lab.cpp          -o  lab
