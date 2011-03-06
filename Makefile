all: label-create label-dir

label-create: label-create.c dir.o error.o file.o path.o
label-dir: label-dir.c dir.o error.o path.o

dir.o: dir.h error.h path.h

error.o: error.h

file.o: file.h

path.o: path.h
