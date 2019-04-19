CC=gcc
CFLAGS=-lm -I $(IDIR)

IDIR = include
ODIR = obj
SDIR = src

_DEPS = graph.h median.h dfs.h mbst.h distance.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = graph.o median.o dfs.o mbst.o distance.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o main.o main.c $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm *.o
