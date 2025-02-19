CC := gcc

CFLAGS := -Wall -Wextra -pedantic
HDRS := square_matrix.h types.h

SRCS := square_mat.c types.c

OBJS := $(SRCS:.c=.o)

EXEC := main

all: $(EXEC)
 
showfont: showfont.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

glfont: glfont.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean

