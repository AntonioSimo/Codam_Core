# Libft

> The very first custom library you create — built from scratch in pure C.

Libft is one of the foundational projects in the 42 cursus, where the challenge is to reimplement standard C library functions without relying on the original `libc`. This project aims to help students understand low-level programming concepts like memory management, pointers, and string manipulation. The custom library that is developed in this project becomes an essential toolkit for future 42 projects.

---

## Project Information

The name of the library created in this project is `libft.a`, and students must submit the necessary files, including the header and source files (`libft.h`, `ft_*.c`), along with a `Makefile` to compile them. The compilation flags `-Wall -Wextra -Werror` must be used to ensure proper code quality. The library is created using the `ar rc libft.a *.o` command to generate the static library. It is important to note that the use of `libtool` and declaring global variables is strictly forbidden.

---

## Part 1 — Reimplementing Libc Functions

In this part of the project, the goal is to reimplement several standard C functions, all of which are prefixed with `ft_` to avoid any conflicts with the original libc functions. The functions include:

- **Character checks:** Functions like `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, and `ft_isprint` are implemented to check properties of characters.
- **String and memory management:** Functions such as `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_strlcpy`, and `ft_strlcat` are included to handle string length calculation, memory initialization, memory copying/moving, and string manipulation.
- **Case conversion:** Functions `ft_toupper` and `ft_tolower` convert characters to upper or lower case.
- **String search and comparison:** Functions like `ft_strchr`, `ft_strrchr`, `ft_strncmp`, and `ft_strnstr` are used for searching and comparing strings.
- **Memory search and comparison:** Functions such as `ft_memchr` and `ft_memcmp` help in searching and comparing blocks of memory.
- **Conversion:** `ft_atoi` is implemented to convert strings to integers.
- **Memory allocation:** Functions `ft_calloc` and `ft_strdup` are implemented to allocate memory and duplicate strings.

---

## Part 2 — Additional Utility Functions

This part focuses on additional utility functions that are either not included in `libc` or are provided in a different form:

- `ft_substr` — Extracts a substring from a string.
- `ft_strjoin` — Concatenates two strings.
- `ft_strtrim` — Trims characters from both ends of a string.
- `ft_split` — Splits a string by a delimiter.
- `ft_itoa` — Converts an integer to a string.
- `ft_strmapi` — Applies a function to each character of a string (with index).
- `ft_striteri` — Applies a function to each character of a string in-place.
- `ft_putchar_fd` — Prints a character to a file descriptor.
- `ft_putstr_fd` — Prints a string to a file descriptor.
- `ft_putendl_fd` — Prints a string with a newline to a file descriptor.
- `ft_putnbr_fd` — Prints a number to a file descriptor.

---

## Bonus — Linked List Utilities

The bonus part of the project is only implemented if the mandatory part is completed successfully. It involves creating a set of functions that work with linked lists. The linked list is represented using the following `t_list` struct:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

## Bonus Functions

The bonus part of the project involves working with linked lists and implementing a series of utility functions to manipulate them. These functions are only required if the mandatory part is completed successfully.

### Implemented Bonus Functions:

- `ft_lstnew` — Creates a new list node.
- `ft_lstadd_front` — Adds a new node to the front of the list.
- `ft_lstsize` — Returns the number of nodes in the list.
- `ft_lstlast` — Retrieves the last node of the list.
- `ft_lstadd_back` — Adds a new node to the back of the list.
- `ft_lstdelone` — Deletes a single node.
- `ft_lstclear` — Clears the entire list.
- `ft_lstiter` — Iterates over the list and applies a function to each node.
- `ft_lstmap` — Maps the list to a new one, applying a function to each node.

---

## Makefile Rules

The `Makefile` used for compiling and managing the library provides several useful commands:

| Rule         | Description                                                  |
|--------------|--------------------------------------------------------------|
| `make`       | Compiles the `libft.a` static library                        |
| `make clean` | Removes the object files (`*.o`)                             |
| `make fclean`| Removes the object files and the `libft.a` static library    |
| `make re`    | Cleans and recompiles everything from scratch                |
| `make bonus` | Adds the bonus linked list functions to the library          |

---

## What I Learned

Working on this project offered valuable insights into core programming concepts, such as:

- Manual memory handling and pointer manipulation in C.
- Recreating the behavior of standard library functions from scratch.
- Designing reusable code components and building custom libraries.
- Automating build and cleanup tasks using a `Makefile`-driven workflow.
