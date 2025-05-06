# Ft_Printf
>Because ft_putnbr() and ft_putstr() aren’t enough

The goal of this project is to create a custom implementation of the standard `printf()` function, written in pure C. The project is part of the 42 cursus and is designed to help deepen the understanding of variadic functions, formatted output, and low-level string manipulation. By building this library, you will gain a better grasp of how the `printf()` function works behind the scenes and how variadic arguments can be handled manually.

The project involves recreating the behavior of the standard `printf()` function, while also implementing support for specific format specifiers. This will allow the user to print various types of data, from strings and characters to hexadecimal values, in a manner similar to the original `printf()` function in the C standard library.

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
