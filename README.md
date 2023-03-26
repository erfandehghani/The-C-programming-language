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

    Exercise 1-1: Run the "hello, world" program on your system.
    Exercise 1-2: Experiment to find out what happens when printf's argument string contains \c, where c is some character not listed above.
    Exercise 1-3: Modify the temperature conversion program to print a heading above the table.
    ...

Chapter 2 - Types, Operators, and Expressions

    Exercise 2-1: Write a program to determine the ranges of char, short, int, and long variables.
    Exercise 2-2: Write a loop equivalent to the for loop above without using && or ||.
    Exercise 2-3: Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value.
    ...

Chapter 3 - Control Flow

    Exercise 3-1: Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside). Write a version with only one test inside the loop and measure the difference in run-time.
    Exercise 3-2: Write a function escape(s, t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch.
    Exercise 3-3: Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
    ...
