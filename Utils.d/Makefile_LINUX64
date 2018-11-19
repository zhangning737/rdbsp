include ../defs

#CXXFLAGS = $(GFLAGS) 

LIB = $(LIBDIR)libutility.a

OBJS =  $(LIB)(BlockAlloc.o) $(LIB)(Memory.o)\
        $(LIB)(curve.o)\
        $(LIB)(crossprod.o) \
        $(LIB)(RWStatfile.o)\
        $(LIB)(Sign.o)




$(LIB):  $(OBJS)
	$(RANLIB) $(LIB)


$(LIB)(BlockAlloc.o) : BlockAlloc.C BlockAlloc.h resize_array.h

$(LIB)(Memory.o) : Memory.C Memory.h

$(LIB)(curve.o): curve.C curve.h

$(LIB)(crossprod.o): crossprod.C utilities.h

$(LIB)(RWStatfile.o): RWStatfile.C RWStatfile.h

$(LIB)(Sign.o): Sign.C Sign.h
