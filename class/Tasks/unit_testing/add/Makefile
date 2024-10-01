CC=gcc
CFLAGS=-Iinclude -Iunity

UNITY_SRC=unity/unity.c

TEST_SRC=test/test_my_code.c

SRC=src/my_code.c

.PHONY: all clean

all: my_test_executable

my_test_executable: $(SRC) $(TEST_SRC) $(UNITY_SRC)
	$(CC) -o my_test_executable $(SRC) $(TEST_SRC) $(UNITY_SRC) $(CFLAGS)

clean:
	rm -f my_test_executable

