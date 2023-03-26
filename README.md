# Solutions to Exercises in "The C Programming Language" by Brian W. Kernighan and Dennis M. Ritchie

This repository contains my solutions to the exercises in the book "The C Programming Language". The exercises are organized by chapter, and each chapter has its own directory.

# Installation and Usage

In Chapter 1, you can compile and run the exercises directly since the answers are written in the main() function.

In Chapter 2, the answers are also written in the main() function, so you can easily compile and run them as well.

However, in Chapter 3, the exercises are organized differently. You will need to include the corresponding header files in your main file and use the functions defined in those files to run the exercises.

Additionally, the main.c file contains example code for each exercise in chapter 3 and some of exercises in chapter 4. To run a specific exercise, you will need to uncomment the relevant code in main.c and then compile and run the program.

# Exercises

A list of the exercises included in the repository, organized by chapter. Each exercise should include a brief description and a link to the source code.
Chapter 1 - A Tutorial Introduction

    Exercise 1-3: Modify the temperature conversion program to print a heading above the table.
    Exercise 1-4: Write a program to print the corresponding Celsius to Fahrenheit table.
    Exercise 1-5: Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
    Exercise 1-6: Verify that the expression getchar() != EOF is 0 or 1.
    Exercise 1-7: Write a program to print the value of EOF.
    Exercise 1-8: Write a program to count blanks, tabs, and newlines.
    Exercise 1-9: Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
    Exercise 1-10: Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \. This makes tabs and backspaces visible in an unambiguous way.
    Exercise 1-12: Write a program that prints its input one word per line.
    Exercise 1-13: Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
    Exercise 1-14: Write a program to print a histogram of the frequencies of different characters in its input.
    Exercise 1-15: Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
    Exercise 1-16: Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text.
    Exercise 1-17: Write a program to print all input lines that are longer than 80 characters.
    Exercise 1-18: Write a program to remove all trailing blanks and tabs from each line of input, and to delete entirely blank lines.
    Exercise 1-19: Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.

Chapter 2 - Types, Operators, and Expressions

    Exercise 2-4: Write an alternate version of squeeze(s1, s2) that deletes each character in s1 that matches any character in the string s2.
    Exercise 2-9: In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount.

Chapter 3 - Control Flow

    Exercise 3-1: Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside). Write a version with only one test inside the loop and measure the difference in run-time.
    Exercise 3-2: Write a function escape(s, t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch.
    Exercise 3-3: Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
