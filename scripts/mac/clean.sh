#!/bin/bash

# Author : Nghia Lam
# Copyright (c) Nghia Lam

rm -rf bin
rm -rf build

/usr/local/bin/cmake -H. -B build
