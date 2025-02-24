CC := gcc

INCLUDE_DIR = include
OBJ_DIR = obj
SRC_DIR = src

CFLAGS := -g -Wall -Wextra -pedantic -I include
HDRS :=

EXEC := matrix
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(EXEC)

$(EXEC): $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJ_DIR)/$(OBJS)

.PHONY: all clean *

