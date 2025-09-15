CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude

SRC = src/set_iterator.c
OBJ = src/set_iterator.o

TEST_SRC = test/test.c
TEST_OBJ = test/test.o
TEST_BIN = test/run/tests

.PHONY: all clean

all: $(TEST_BIN)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BIN): $(OBJ) $(TEST_OBJ)
	if not exist test\run mkdir test\run
	$(CC) $(OBJ) $(TEST_OBJ) -o $(TEST_BIN)

clean:
	del /q $(OBJ) $(TEST_OBJ) $(TEST_BIN)
