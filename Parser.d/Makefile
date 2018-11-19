include ../defs

LIB = $(LIBDIR)libparser.a

OBJS = $(LIB)(lex.yy.o) $(LIB)(y.tab.o) $(LIB)(auxx.o)

CC = $(CXX)

CFLAGS = $(CXXFLAGS)

$(LIBDIR)libparser.a: $(OBJS)

y.tab.c: p.y
	yacc -d -v p.y

lex.yy.c: lexer.l $(LIB)(y.tab.o)
	lex -i lexer.l

$(LIB)(lex.yy.o): lex.yy.c y.tab.h auxx.h


$(LIB)(y.tab.o): y.tab.c auxx.h

$(LIB)(auxx.o): auxx.C auxx.h ../Driver.d/Domain.h  ../Element.d/Element.h

