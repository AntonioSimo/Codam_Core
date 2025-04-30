# Ft_Printf

## About the Project

The goal of this project is to create a custom implementation of the standard `printf()` function, written in pure C. The project is part of the 42 cursus and is designed to help deepen the understanding of variadic functions, formatted output, and low-level string manipulation. By building this library, you will gain a better grasp of how the `printf()` function works behind the scenes and how variadic arguments can be handled manually.

The project involves recreating the behavior of the standard `printf()` function, while also implementing support for specific format specifiers. This will allow the user to print various types of data, from strings and characters to hexadecimal values, in a manner similar to the original `printf()` function in the C standard library.

---

## Project Information

- **Program Name**: `libftprintf.a`
- **Turn-in Files**: `Makefile`, `*.h`, `*.c`, and `*/ *.h`, `*/ *.c`
- **Allowed Functions**: You are allowed to use `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, and `va_end`.
- **Libft Authorized**: ✅ Yes, you can use your `libft` for utility functions.
- **Forbidden**: The use of `libtool` and standard `printf()` buffer handling is strictly prohibited.
- **Library Creation**: The static library is created using the `ar rc libftprintf.a *.o` command.

---

## Function Prototype
The prototype for the custom `printf()` function is as follows:

```c
int ft_printf(const char *format, ...);
```
This function recreates the behavior of the standard C printf() function. It supports a variety of format specifiers and handles variadic arguments manually using the <stdarg.h> library. The challenge is to implement this functionality from scratch while ensuring memory safety and correct formatting for each type of argument.

## Supported Conversions
The `ft_printf()` function supports the following format specifiers:

## Supported Conversions

| Specifier | Description                              |
|-----------|------------------------------------------|
| `%c`      | Prints a single character.               |
| `%s`      | Prints a null-terminated string.         |
| `%p`      | Prints a pointer address in hexadecimal.|
| `%d`      | Prints a signed decimal integer.        |
| `%i`      | Prints a signed decimal integer.        |
| `%u`      | Prints an unsigned decimal integer.     |
| `%x`      | Prints an unsigned hexadecimal (lowercase). |
| `%X`      | Prints an unsigned hexadecimal (uppercase). |
| `%%`      | Prints a literal percent sign.          |

Each specifier is processed to handle its corresponding data type, allowing the `ft_printf()` function to output data in the desired format.

## Makefile Rules

To compile and manage the project, the following Makefile rules are available:

| Rule        | Description                                                 |
|-------------|-------------------------------------------------------------|
| `make`      | Compiles and creates the `libftprintf.a` static library.    |
| `make clean`| Removes object files (`*.o`).                               |
| `make fclean`| Removes object files and the `libftprintf.a` binary.       |
| `make re`   | Cleans and recompiles the project from scratch.             |

## Testing
The implementation has been tested against the behavior of the standard `printf()` function. The tests include:

- Custom test cases that cover a range of formatting scenarios.
- Edge-case checks, such as printing `NULL` strings, handling `INT_MIN`, printing large hexadecimal values, and more.

These tests help ensure that the `ft_printf()` function works as expected, and that it correctly mimics the behavior of the original `printf()`.

## What I Learned
Through this project, I have gained valuable insights into the following concepts:
- **Manual argument parsing**: By working with the `stdarg.h` library, I learned how to handle a variable number of arguments and process them according to the format specifiers.
- **Format parsing and branching logic**: I developed the ability to handle different types of format specifiers and implement branching logic to format each argument accordingly.
- **Memory-safe string manipulation**: The project reinforced the importance of memory management in C, as I needed to ensure that all strings and variables were properly allocated and freed.
- **Reproducing standard library behavior**: By recreating the `printf()` function, I gained a deeper understanding of how the standard library functions are implemented and how to mimic their behavior.
- **Building reusable code**: I learned how to organize my code into a static library, which can be reused in other projects or contexts.

This project has provided a solid foundation for working with variadic functions and formatted output in C, which is a crucial skill for low-level systems programming.
