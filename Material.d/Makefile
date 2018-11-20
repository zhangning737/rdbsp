include ../defs

#CXXFLAGS = -I../Math.d $(GFLAGS) -DF_NEEDS_UNDSC

LIB = libmat.a

OBJS = $(LIB)(matela/elastic.o) $(LIB)(matset.o) $(LIB)(material.o) \
	   $(LIB)(Stress_Prin.o) \
       $(LIB)(mohr/mohr.o) $(LIB)(Prin2Stress.o)
 
 

$(LIB): $(OBJS) $(OPTOBJS)
	$(RANLIB) $(LIB)

$(LIB)(matela/elastic.o) : matela/elastic.C matela/elastic.h

$(LIB)(mohr/mohr.o): mohr/mohr.C mohr/mohr.h

$(LIB)(mises/mises.o): mises/mises.C mises/mises.h

$(LIB)(matset.o): matset.C material.h
