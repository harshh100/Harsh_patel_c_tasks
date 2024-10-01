CC=gcc
CFLAGS=-Iinclude -Iunity

UNITY_SRC=unity/unity.c

TEST_SRC=test/test_ed_11_1.c

SRC=src/ed_11_1.c

.PHONY: all clean

all: test_ed_11_1_executable

test_ed_11_1_executable: $(SRC) $(TEST_SRC) $(UNITY_SRC)
	$(CC) -o test_ed_11_1_executable $(SRC) $(TEST_SRC) $(UNITY_SRC) $(CFLAGS)

clean:
	rm -f test_ed_11_1_executable

