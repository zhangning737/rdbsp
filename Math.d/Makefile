include ../defs

#CXXFLAGS = $(GFLAGS) 

LIB = $(LIBDIR)libmath.a

OBJS =  $(LIB)(mathfem.o)  $(LIB)(egen.o)

$(LIB):  $(OBJS)
	$(RANLIB) $(LIB)



$(LIB)(mathfem.o): mathfem.C mathfem.h 

$(LIB)(egen.o): egen.C egen.h 
