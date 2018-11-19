include ../defs

#CXXFLAGS = -I../Math.d $(GFLAGS) -DF_NEEDS_UNDSC

LIB = libele.a

OBJS = $(LIB)(Coordset.o) $(LIB)(Elemset.o) $(LIB)(Element.o) \
       $(LIB)(AddElem.o)  \
       $(LIB)(Node.o)\
       $(LIB)(Press2force.o) \
       $(LIB)(Bricko.d/EightNodeBricko.o)\
		$(LIB)(Bricko.d/jacob.o)\
        $(LIB)(Bricko.d/inverse.o)\
        $(LIB)(Part.o)
 

$(LIB): $(OBJS) $(OPTOBJS)
	$(RANLIB) $(LIB)

$(LIB)(Bricko.d/EightNodeBricko.o):  Bricko.d/EightNodeBricko.C Bricko.d/EightNodeBricko.h

$(LIB)(Brick.d/EightNodeBrick.o):  Brick.d/EightNodeBrick.C Brick.d/EightNodeBrick.h
