# Get_next_line

> Reading a line from a file descriptor is far too tedious. This function makes it easier.

`get_next_line` is a project from the 42 curriculum that challenges you to implement a function capable of reading one line at a time from a file descriptor. This function will be an essential building block for future file-based operations in C.

---

## 📦 Project Information

- **Function name:** `get_next_line`
- **Prototype:** `char *get_next_line(int fd);`
- **Authorized functions:** `read`, `malloc`, `free`
- **Forbidden:** `lseek`, global variables, use of your `libft`
- **Turn-in files:**  
  - `get_next_line.c`  
  - `get_next_line_utils.c`  
  - `get_next_line.h`  
- **Compilation Example:**  
  ```bash
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

## 🧠 How It Works
- Reads from a file descriptor, one line at a time.
- Returns the next line **including the newline character** `\n` if one is found.
- Returns `NULL` on error or when there's nothing left to read.
- Works with **standard input** as well as files.
- Must handle varying `BUFFER_SIZE` values efficiently (e.g. 1, 42, 9999).

## 🚫 Constraints
- You must read **as little data as possible** on each call.
- You may **not** use global variables or `libft`.
- You **must not** read the entire file in advance.
- Behavior is **undefined** when reading binary files or modifying the file externally during execution.

## 💡 Implementation Hints
- Use a `static` variable to persist the buffer across function calls.
- Break the read buffer at the first newline and return that part.
- Handle memory carefully to avoid leaks or dangling pointers.
- Carefully manage partial lines between calls.

## ✨ Bonus (Optional)
If you've completed the mandatory part, you can implement these bonus features:
- Use **only one static variable**.
- Support **multiple file descriptors** simultaneously.
- Maintain separate read states for each `fd`.

## 🛠 Makefile Rules

| Rule         | Description                                |
|--------------|--------------------------------------------|
| `make`       | Compile the mandatory `get_next_line.a`    |
| `make clean` | Remove object files (`*.o`)                |
| `make fclean`| Remove object files and binaries           |
| `make re`    | Clean and recompile from scratch           |
| `make bonus` | Compile the bonus version of the project   |

## 🔍 Example Usage
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
