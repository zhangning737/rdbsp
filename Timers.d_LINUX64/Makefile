include ../defs

LIB = libtimer.a

OBJS =  $(LIB)(Timing.o)   $(LIB)(GetTime.o) $(LIB)(StaticTimers.o)

$(LIB):  $(OBJS)


$(LIB)(Timing.o) : Timing.C Timing.h ../Utils.d/resize_array.h


$(LIB)(GetTime.o): GetTime.C GetTime.h

$(LIB)(StaticTimers.o): StaticTimers.C StaticTimers.h ../Timers.d_LINUX64/Timing.h  ../Timers.d_LINUX64/StaticTimers.h ../Timers.d_LINUX64/MatrixTimers.h ../Driver.d/Domain.h ../Utils.d/Memory.h
