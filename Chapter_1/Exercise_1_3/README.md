
## Author
- **Harsh Patel **
- **Created:** 17/7/2024
- **Modified:** 25/7/2024

# Fahrenheit to Celsius Table Generator

This program dynamically generates a table converting Fahrenheit to Celsius based on user inputs forthe lower limit, upper limit, and step size. It allows the user to continue generating tables until they choose to exit.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Usage](#usage)
- [Example](#example)
- [Author](#author)

## Description
The program takes three inputs from the user:
1. Lower limit of the Fahrenheit values (must be an integer).
2. Upper limit of the Fahrenheit values (must be an integer).
3. Step size for the Fahrenheit values (must be an integer).

Using these inputs, it generates a table converting the specified range of Celsius values to Fahrenheit. After displaying the table, the user is prompted to decide if they want to generate another table or exit the program.

## Features
- Dynamic user input for the range and step size.
- Continues to prompt the user until they choose to exit.
- Displays the table in a formatted manner.

## Usage
1. Compile the program using a C compiler, e.g., `gcc -o Exercise_1_4 Exercise_1_4.c`.
2. Run the compiled program, e.g., `./Exercise_1_4`.
3. Follow the prompts to enter the lower limit, upper limit, and step size.
4. View the generated table.
5. Choose whether to generate another table or exit.

## Run the Program using MAKEFILE
1. Go to ROOT directory (cd CProgramming)
2. Run the below command.
3. make run_exercise EXERCISE="Chapter1/Exercise_1.4/Exercise_1_4.c"

## Example

`Enter Lower Fahrenheit Value : 100
Enter Upper Fahrenheit Value : 200
Enter Step Value : 20
Fahr            Celsius
-----------------------
100               37.8
120               48.9
140               60.0
160               71.1
180               82.2
200               93.3
Do you want to Run Again [1 for YES / 0 for NO] : 0`
