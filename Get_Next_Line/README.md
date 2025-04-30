# Get_next_line

> Reading from a file descriptor one line at a time shouldn't be so hard — so let's make it easier.

This project, part of the 42 programming curriculum, is all about writing a function called `get_next_line` that can read from a file descriptor **line by line**. That means every time you call it, you get the next line of text — including the newline character if it exists.

Although it might sound like a straightforward task, there's quite a bit of complexity involved. You’ll need to handle buffering, memory management, and edge cases, all while complying with strict constraints like avoiding global variables or using external libraries (not even your own `libft`!).

---

## Project Overview

Here’s what the project requires:

- You must implement the function:

  ```c
  char *get_next_line(int fd);
  ```

## Allowed Functions

You are only allowed to use the following standard library functions:

- `read`
- `malloc`
- `free`

## Forbidden

The following are **not** allowed:

- `lseek`
- Global variables
- `libft` or any other custom libraries

## Required Files

The following files must be submitted:

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

## Compilation

You can compile the code using the following command:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```
The `BUFFER_SIZE` macro can be modified to test different reading behaviors.

## How It Works

Each time `get_next_line` is called, it reads just enough data to return the next line from the file descriptor. If a newline character is encountered, that line is returned (including the newline character). If there’s no more data to read, the function returns `NULL`.

This function works not only with regular files but also with standard input (stdin). It is designed to adapt efficiently to different `BUFFER_SIZE` values — whether it’s small (like 1) or large (like 9999).

## Bonus Features

After completed the basic version of the function, I enhance my implementation with the following:

- Use **only one static variable**.
- Support for **multiple file descriptors** simultaneously.
- Independent read states for each file descriptor.

---

## Example Usage:

Here’s how you might use `get_next_line` in a simple C program:

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

This program opens `example.txt`, reads and prints each line until the end of the file, and then closes the file. Remember to free each line after you're done with it.
