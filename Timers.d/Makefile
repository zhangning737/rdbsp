
LIB = libtimer.lib

OBJS =  Timing.obj  GetTime.obj StaticTimers.obj

$(LIB): $(OBJS)
	xilink /Lib /out:libtimer.lib $(OBJS)


Timing.obj : Timing.cpp Timing.h ../Utils.d/resize_array.h
	icl /c Timing.cpp


GetTime.obj: GetTime.cpp GetTime.h
	icl /c GetTime.cpp

StaticTimers.obj: StaticTimers.cpp StaticTimers.h ../Timers.d/Timing.h  ../Timers.d/StaticTimers.h ../Timers.d/MatrixTimers.h ../Driver.d/Domain.h ../Utils.d/Memory.h
	icl /c StaticTimers.cpp
