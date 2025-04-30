# Libft

> Your very first own library — built from scratch in pure C.

Libft is a foundational project of the 42 cursus, where students reimplement standard C library functions without relying on the original `libc`. This custom library will become a useful toolkit throughout future projects.

---

## 📦 Project Information

- **Library Name:** `libft.a`
- **Turn-in Files:** `libft.h`, `ft_*.c`, `Makefile`
- **Compilation Flags:** `-Wall -Wextra -Werror`
- **Library Creation:** `ar rc libft.a *.o`
- **Forbidden:** Use of `libtool`, declaring global variables

---

## 🧰 Part 1 — Libc Functions

Reimplementation of standard C functions, all prefixed with `ft_`:

- **Character checks:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- **String/memory:** `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_strlcpy`, `ft_strlcat`
- **Case conversion:** `ft_toupper`, `ft_tolower`
- **String search/compare:** `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`
- **Memory search/compare:** `ft_memchr`, `ft_memcmp`
- **Conversion:** `ft_atoi`
- **Allocation:** `ft_calloc`, `ft_strdup`

---

## ✨ Part 2 — Additional Functions

Utility functions not included in `libc`, or provided in a different form:

- `ft_substr` — extract substring from string  
- `ft_strjoin` — concatenate two strings  
- `ft_strtrim` — trim characters from both ends  
- `ft_split` — split string by delimiter  
- `ft_itoa` — convert integer to string  
- `ft_strmapi` — apply function to string (with index)  
- `ft_striteri` — apply function to string in-place  
- `ft_putchar_fd` — print character to file descriptor  
- `ft_putstr_fd` — print string to file descriptor  
- `ft_putendl_fd` — print string with newline  
- `ft_putnbr_fd` — print number to file descriptor  

---

## 🧩 Bonus — Linked List Utilities

> Implemented only if mandatory part is perfect

Using the following `t_list` struct:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

## Bonus Functions
- `ft_lstnew` — create new list node
- `ft_lstadd_front` — add node at beginning
- `ft_lstsize` — count number of nodes
- `ft_lstlast` — get last node
- `ft_lstadd_back` — add node at end
- `ft_lstdelone` — delete single node
- `ft_lstclear` — clear entire list
- `ft_lstiter` — iterate and apply function
- `ft_lstmap` — map list to new one using function

## 🛠 Makefile Rules


| Rule        | Description                                |
|-------------|--------------------------------------------|
| `make`      | Compile `libft.a`                          |
| `make clean`| Remove object files (`*.o`)                |
| `make fclean`| Remove object files and `libft.a`         |
| `make re`   | Clean and recompile from scratch           |
| `make bonus`| Add bonus list functions to the library    |

## 📚 What I Learned
- Manual memory handling and pointer manipulation
- Reproducing standard behavior without relying on built-ins
- Structuring reusable code and libraries
- Managing projects with a strict Makefile workflow
