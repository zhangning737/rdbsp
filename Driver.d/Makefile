include ../defs

LIB = libdriver.a

#OPTOBJS = $(LIB)(SOpt.o)

OBJS = $(LIB)(Domain.o) 

$(LIB): $(OBJS) $(OPTOBJS)
#	$(RANLIB) $(LIB)

$(LIB)(Domain.o) : Domain.C Domain.h ../Element.d/Element.h ../Material.d/material.h 

