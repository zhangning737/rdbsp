#!/bin/sh

rm */*.a
rm *.o
rm */*.o
cp ../tecio64.a .
make -f Makefile_LINUX64
#idb ./dcp
#cp dcp ../wodetest/dcpnew
