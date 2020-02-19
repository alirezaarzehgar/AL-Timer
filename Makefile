CC  = cc
INP = AL-Timer
OUT = *.c
LIB = `pkg-config --libs --cflags gtk+-2.0 gthread-2.0`
ARG = -w -g -Wall

all:
	$(CC) $(ARG) -o $(INP) $(OUT) $(LIB)
