CC=gcc
CFLAGS=-Iinclude

UNITY_SRC=unity/unity.c

TEST_SRC=test/test_my_code.c

SRC=src/my_code.c

all: test

test: $(SRC) $(TEST_SRC) $(UNITY_SRC)
	$(CC) -o test $(SRC) $(TEST_SRC) $(UNITY_SRC) $(CFLAGS)

clean:
	rm -f test

