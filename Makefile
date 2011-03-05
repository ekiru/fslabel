all: label-dir

label-dir: label-dir.c dir.o error.o path.o

dir.o: dir.h error.h path.h

error.o: error.h

path.o: path.h
