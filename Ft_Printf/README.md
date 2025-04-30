# Ft_Printf

> Because `ft_putnbr()` and `ft_putstr()` aren’t enough.

A custom implementation of the standard `printf()` function, written in pure C.  
This project is part of the 42 cursus and aims to deepen understanding of variadic functions, formatted output, and low-level string manipulation.

---

## 📦 Project Information

- **Program Name:** `libftprintf.a`
- **Turn-in Files:** `Makefile`, `*.h`, `*.c`, `*/*.h`, `*/*.c`
- **Allowed Functions:** `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`
- **Libft Authorized:** ✅ Yes
- **Forbidden:** Use of `libtool`, standard `printf()` buffer handling
- **Library Creation:** `ar rc libftprintf.a *.o`

---

## 🔧 Function Prototype

```c
int ft_printf(const char *format, ...);

Recreates the behavior of the standard C printf() function with support for specific format specifiers.
Handles variadic arguments manually using <stdarg.h>.
```

## ✅ Supported Conversions

| Specifier | Description                              |
|-----------|------------------------------------------|
| `%c`      | Print a single character                 |
| `%s`      | Print a null-terminated string           |
| `%p`      | Print a pointer address in hexadecimal   |
| `%d`      | Print a signed decimal integer           |
| `%i`      | Print a signed decimal integer           |
| `%u`      | Print an unsigned decimal integer        |
| `%x`      | Print an unsigned hexadecimal (lowercase)|
| `%X`      | Print an unsigned hexadecimal (uppercase)|
| `%%`      | Print a literal percent sign             |

## 🛠 Makefile Rules

| Rule        | Description                                 |
|-------------|---------------------------------------------|
| `make`      | Compile and create `libftprintf.a`          |
| `make clean`| Remove object files (`*.o`)                 |
| `make fclean`| Remove object files and `libftprintf.a`    |
| `make re`   | Recompile from scratch                      |

## 🧪 Testing
Tested against the behavior of the standard printf() using:
- Custom test cases
- Edge-case checks (NULL strings, INT_MIN, large hex values, etc.)

## 📚 What I Learned
- Manual argument parsing with stdarg.h
- Format parsing and branching logic
- Memory-safe string manipulation
- Reproducing standard library behavior
- Building reusable code as a static library
