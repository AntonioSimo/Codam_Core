# Philosophers
>I never thought philosophy would be so deadly

The **Philosophers Problem** is a classic synchronization problem that involves a group of philosophers sitting around a round table, with a bowl of spaghetti in the center. The challenge is to simulate the behaviors of these philosophers, who take turns eating, thinking, and sleeping while trying to avoid starvation.

Here are the key points of the problem:

- There are several philosophers, each with a fork to their left and right. However, they need both forks to eat. If a philosopher is not eating, they are either thinking or sleeping.
- Philosophers do not communicate with each other and do not know if another philosopher is about to starve.
- Each philosopher must avoid starvation and get a chance to eat periodically.
- The simulation stops when a philosopher dies from starvation.
  
## Program Structure

The requirements is to implement two programs: one for the mandatory part and another for the bonus part (if you decide to attempt it). Both programs must adhere to the following guidelines:

- **No global variables** are allowed.
- The programs should accept the following arguments:
  - `number_of_philosophers`: The number of philosophers (and also the number of forks on the table).
  - `time_to_die` (in milliseconds): The time it takes for a philosopher to starve if they don't eat.
  - `time_to_eat` (in milliseconds): The amount of time it takes for a philosopher to eat.
  - `time_to_sleep` (in milliseconds): The amount of time a philosopher spends sleeping.
  - `number_of_times_each_philosopher_must_eat` (optional): If provided, the simulation will stop after all philosophers have eaten this many times.

Each philosopher is represented by a thread, and the main challenge of this project is managing the synchronization between these threads to ensure that philosophers can safely pick up and put down forks without causing conflicts or deadlocks.

### States of a Philosopher

The states of each philosopher are as follows:

1. **Thinking**: A philosopher is not eating or sleeping.
2. **Eating**: A philosopher is consuming spaghetti and holding two forks.
3. **Sleeping**: After eating, a philosopher will sleep for a period of time.
4. **Dead**: If a philosopher doesn't eat within the specified time, they will die.

Whenever the state of a philosopher changes, the program logs it, showing the timestamp and the current action. Here are the logs for the state changes:

- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

## Mandatory Part

### Program Name: `philo`

The program must follow these specific requirements:

- **Threads and Mutexes**: Each philosopher must be represented as a separate thread.
- **Forks**: There is one fork between each pair of philosophers. When there are multiple philosophers, each philosopher will have a fork on their left and right. If there is only one philosopher, they will only have one fork.
- **Mutex Protection**: To prevent philosophers from picking up the same fork simultaneously, you must protect each fork using a mutex. This ensures that only one philosopher can hold a fork at any given time, avoiding conflicts and deadlocks.
  
### File Structure
The project should include the following files:
- `Makefile`
- `*.h` header files
- `*.c` source files (in the `philo/` directory)

The `Makefile` should support the following commands:
- `NAME`, `all`, `clean`, `fclean`, `re`

### Required Functions

You are only allowed to use the following library functions:

- `memset`, `printf`, `malloc`, `free`, `write`
- `usleep`, `gettimeofday`
- Thread-related functions: `pthread_create`, `pthread_detach`, `pthread_join`
- Mutex-related functions: `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`

### Restrictions
- **Libft** is not allowed in this part of the project.
- **Global variables** are forbidden.

## Additional Notes

The simulation should stop when a philosopher dies of starvation or, if specified, after all philosophers have eaten a certain number of times. 

By using mutexes, you can ensure that each philosopher can safely access the forks and avoid race conditions. The challenge lies in synchronizing the actions of the philosophers so that no one starves, and everyone gets a chance to eat and think.

This project is an excellent exercise in multithreading and synchronization, as it requires you to manage resources (the forks) across multiple threads, ensuring that philosophers can eat without conflict.

Good luck, and remember: **philosophers should avoid dying**!
