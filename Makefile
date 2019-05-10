CC=gcc -g
CFLAGS= -lm -I $(IDIR)

IDIR = include
ODIR = obj
SDIR = src

_DEPS = graph.h median.h dfs.h mbst.h distance.h mst.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = graph.o median.o dfs.o mbst.o distance.o mst.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o main.out main.c $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm *.out
