#!/bin/sh

rm */*.a
rm *.o
rm */*.o
make -f Makefile_LINUX64
#idb ./dcp
cp dcp ../wodetest/dcpnew
