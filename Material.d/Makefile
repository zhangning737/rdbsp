include ../defs

#CXXFLAGS = -I../Math.d $(GFLAGS) -DF_NEEDS_UNDSC

LIB = libmat.a

OBJS = $(LIB)(matela/elastic.o) $(LIB)(matset.o) $(LIB)(material.o) \
       $(LIB)(mymat/mymat.o)  $(LIB)(mymat/umatmy.o) \
       $(LIB)(mymatm/mymatm.o) $(LIB)(Stress_Prin.o) \
       $(LIB)(mohr/mohr.o) $(LIB)(Prin2Stress.o) $(LIB)(mymatfq/mymatfq.o) \
       $(LIB)(mymatmpalpha/mymatmpalpha.o) $(LIB)(mymatmpalpha/umatmpalpha.o)\
       $(LIB)(matNULL/null.o) $(LIB)(dp/dp.o)
 
 

$(LIB): $(OBJS) $(OPTOBJS)
	$(RANLIB) $(LIB)

$(LIB)(matela/elastic.o) : matela/elastic.C matela/elastic.h

$(LIB)(mymat/mymat.o) : mymat/mymat.C mymat/mymat.h

$(LIB)(mymatfq/mymatfq.o) : mymatfq/mymatfq.C mymatfq/mymatfq.h

$(LIB)(mymatm/mymatm.o) : mymatm/mymatm.C mymatm/mymatm.h

$(LIB)(mohr/mohr.o): mohr/mohr.C mohr/mohr.h

$(LIB)(mises/mises.o): mises/mises.C mises/mises.h

$(LIB)(mymatmpalpha/mymatmpalpha.o): mymatmpalpha/mymatmpalpha.C mymatmpalpha/mymatmpalpha.h
