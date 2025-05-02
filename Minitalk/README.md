# Minitalk

## Description

**MiniTalk** is a small communication system built using UNIX signals. The project consists of two programs: a `server` and a `client`. The communication is performed exclusively using `SIGUSR1` and `SIGUSR2`, where each signal represents a bit (0 or 1).

## How it works

- The `server` is launched first and immediately prints its **PID** (process ID).
- The `client` takes **two parameters**:
  1. The PID of the server.
  2. The string message to send.

- The client sends the given string **bit by bit** using only the `SIGUSR1` and `SIGUSR2` signals.
- Once the server has received the full message, it prints it to the standard output.
- The server must be able to handle multiple clients sequentially, without restarting.
- The message delivery must be **fast**: e.g., taking 1 second for 100 characters is too slow.

## Technical Requirements

- Only the following functions are allowed:
  - `write`, `ft_printf` (or any equivalent you implement)
  - `signal`, `sigemptyset`, `sigaddset`, `sigaction`
  - `kill`, `getpid`, `malloc`, `free`, `pause`, `sleep`, `usleep`, `exit`

- Programs must handle all errors gracefully (no segmentation faults, memory leaks, etc.).
- Only **one global variable per program** is allowed, with justification.

## Bonus Features

- The server acknowledges each received message by sending a confirmation signal back to the client.
- Support for **Unicode characters**.

## Example Usage

```bash
# On terminal 1
$ ./server
Server PID: 12345

# On terminal 2
$ ./client 12345 "Hello from client!"