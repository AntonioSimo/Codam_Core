# Minishell

This is our implementation of **Minishell**, a group project for two people from the 42 coding school curriculum. It is a project that challenges you to build your own shell in C, mimicking the behavior of **bash shell** in many fundamental aspects. The aim is to get hands-on experience with process control, input parsing, environment management, and Unix system calls—all while following strict coding and memory management standards.

---

## Project Goal

The goal of this project is to recreate a simplified version of the Unix shell. The shell will display a prompt, accept and parse user input, execute commands (with or without pipes and redirections), and handle built-in shell behaviors—all while remaining robust, memory-safe, and responsive to user signals.

---

## Core Features

Minishell should support the following functionality:

### Prompt and Input
- It displays a custom prompt, waiting for the user to enter a new command.
- It maintains a working command history using the `readline` library.

### Command Execution
- It correctly finds and executes binaries using the `PATH` environment variable, or through absolute/relative paths.
- Pipes (`|`) are supported, allowing the output of one command to be passed to the input of another.

### Quotes and Parsing
- Single quotes `'` prevent interpretation of metacharacters.
- Double quotes `"` also prevent interpretation, **except** for the dollar sign (`$`) which still triggers variable expansion.
- Special characters like `\` and `;` are **not** interpreted unless required.
- The shell should handle **unclosed quotes** gracefully (i.e., by not interpreting them at all).

### Redirections
The following redirections are implemented:
- `<` to redirect input from a file.
- `>` to redirect output to a file, overwriting it.
- `>>` to redirect output to a file in append mode.
- `<<` (here-document): reads input until a delimiter line is found.

> Note: The `<<` redirection doesn’t need to update the shell’s command history.

### Environment Handling
- Environment variables prefixed with `$` should expand to their values.
- The special variable `$?` should expand to the exit status of the most recent foreground command.

---

## Signal Handling

The shell must handle the following signals in an interactive way, similar to bash:

- **CTRL+C**: Interrupts the current command and displays a new prompt.
- **CTRL+D**: Exits the shell.
- **CTRL+\\**: Does nothing.

A single global variable is permitted to track received signals. However, it **must only store the signal number** and must **not** provide access to the rest of your program’s state or logic.

---

## Built-in Commands

The shell includes several built-in commands that should be implemented internally:

- `echo` (with the `-n` option)
- `cd` (with a relative or absolute path)
- `pwd`
- `export`
- `unset`
- `env`
- `exit`

---

## Memory Management

While the `readline()` function is known to have some memory leaks (which are accepted), I made sure that all the code I wrote is **completely free of leaks**. I used tools like `valgrind` and 'fsanitize' during development to track and fix every memory allocation.

---

## Example Usage:

```bash
$ ./minishell
mustash> echo "Hello, world!"
Hello, world!
mustash> cd ..
mustash> ls | grep minishell
