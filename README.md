# fifo_pipe
FIFO - implemented using semaphore and pthread to establish communication between threads.

## Directory Structure
pipe_def.c-
  contains definitions of pipe utility functions

pipe.h-
  contains declerations of pipe and pipe utility functions
  
main.c-
  sample test bench for pipe testing
  
## PIPE DOCUMENTATION
Pipe can be used for data sharing between different threads. Pipe is extremely useful for concurrent program. Concurrent program may be model of hardware system, software application, etc.

### pipe decleration
A pipe can be decleared by following syntax:
 > pipe_t \*<*pipe-name*>;
      
### pipe initialization
    kkkkk
