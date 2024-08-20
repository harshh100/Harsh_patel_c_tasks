# Compiler
CC = gcc

# Compiler flags
CFLAGS = -g -Werror -Wall -I.

# Common source files
COMMON_SRC = error_handling.c

# Function to remove all exe files in the current directory.
EXE_FILES = $(wildcard *.out)

# Default target
all: $(DIR)/$(EXE)

# Rule to compile all .c files in the specified directory along with common files
$(DIR)/$(EXE): $(DIR)/$(SRC) $(COMMON_SRC)
	@$(CC) $(CFLAGS) -o $(DIR)/$(EXE) $^ -lm
	
# Rule to run the generated executable
run:
	@./$(DIR)/$(EXE)

# Clean target
clean: $(EXE_FILES)
	@rm -f $(EXE_FILES)

# To compile an exercise, you need to specify the directory containing the .c files 
# .c file name and the name of the output executable when invoking make.
 
# For example:
# Command For Compile --->  make DIR=164975_harsh_patel_Chapter_1 SRC=164975_Harshpatel_ex_1_1.c EXE=ex_1_1
# Command For Run ---> make run DIR=164975_harsh_patel_Chapter_1 EXE=ex_1_1






