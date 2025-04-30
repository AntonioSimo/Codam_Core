# Push_swap

The `push_swap` project is a sorting algorithm challenge in C, where the goal is to sort a stack of integers using a minimal number of operations. The project is designed to test your understanding of sorting algorithms, memory management, and efficient problem-solving in C.

---

## Mandatory Part

### The Rules

In this project, you will work with two stacks, `a` and `b`:

- **Stack `a`**: Initially contains a list of unique integers (positive and/or negative).
- **Stack `b`**: Starts empty.

The objective is to sort the numbers in stack `a` in ascending order using the fewest operations possible. The operations available are:

- **sa** (swap a): Swap the first two elements of stack `a`.
- **sb** (swap b): Swap the first two elements of stack `b`.
- **ss**: Perform both `sa` and `sb` at the same time.
- **pa** (push a): Take the top element from stack `b` and move it to the top of stack `a`.
- **pb** (push b): Take the top element from stack `a` and move it to the top of stack `b`.
- **ra** (rotate a): Shift all elements of stack `a` up by one, with the first element becoming the last.
- **rb** (rotate b): Shift all elements of stack `b` up by one, with the first element becoming the last.
- **rr**: Perform both `ra` and `rb` at the same time.
- **rra** (reverse rotate a): Shift all elements of stack `a` down by one, with the last element becoming the first.
- **rrb** (reverse rotate b): Shift all elements of stack `b` down by one, with the last element becoming the first.
- **rrr**: Perform both `rra` and `rrb` at the same time.

## Project Rules

Your project must comply with the following rules to be considered valid:

### 1. Makefile
You must include a `Makefile` that correctly compiles your source files. It's important that the `Makefile` does not perform "relinking," meaning it should not recompile the files unnecessarily each time you build the project.

### 2. Global Variables
The use of global variables is strictly prohibited. You must ensure that all variables are local and well-managed within functions.

### 3. Program `push_swap`
You need to write a program named `push_swap` that takes a list of integers as an argument to be sorted. This list represents the "stack a," and the order of the arguments must be respected: the first argument of the list should be the first element of the stack (the top of the stack).

### 4. Instruction Sequence
The program must display the shortest sequence of operations required to sort stack `a` in ascending order, with the smallest number at the top of the stack. The operations should be shown one per line, separated by a newline (`\n`), and without any additional characters between them.

### 5. Operation Objective
The goal of the program is to sort the stack using the fewest possible operations. During the evaluation process, the number of operations found by your program will be compared against a maximum limit of allowed operations. If your program displays a longer sequence of instructions or if the numbers are not sorted correctly, your project will receive a grade of 0.

### 6. Behavior with No Parameters
If no parameters are provided, the program should not display anything. It should simply return to the prompt without any output.

### 7. Error Handling
In the event of an error, the program must print the message `Error` followed by a newline (`\n`) to the standard error output. Errors can include, for example:
- Arguments that are not integers.
- Arguments that exceed the integer limits.
- The presence of duplicate numbers in the list.

These rules are essential to ensure that your program functions correctly and is ready for evaluation. Any violation of these guidelines may compromise the program's functionality, so it is important to pay close attention to every detail.

### Example Usage:

```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

If invalid arguments are provided, the program should output:

```bash
$ ./push_swap 0 one 2 3
Error
```
