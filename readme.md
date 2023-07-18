# Fibonacci Sequence Implementation in C

This project provides three different implementations of the Fibonacci sequence based on the piecewise recurrence relation F(n) = F(n-3) + F(n-2), where F(0) = 0, F(1) = 1, and F(2) = 2.

## Implementation Details

The project includes the following files:

- `fibonacci.h`: The header file containing function declarations and necessary structures.
- `fibonacci.c`: The source file containing the implementations of the functions declared in `fibonacci.h`.
- `main.c`: The main function to test the Fibonacci sequence using different approaches.

## Development Environment

The project was developed using the following environment:

- Language: C
- Compiler: GCC (GNU Compiler Collection)

## How to Compile and Run

To compile and run the source code, follow these steps:

1. Make sure all the source files (`fibonacci.h`, `fibonacci.c`, and `main.c`) are  in the same directory.

2. Open a terminal or command prompt and navigate to the directory where the source files are located.

3. Compile the source files using GCC:

   ```bash
   gcc -o fibonacci main.c fibonacci.c
