# fifo_pipe
FIFO - implemented using semaphore and pthread to establish communication between threads.

## Directory Structure
**pipe_def.c**-
  contains definitions of pipe utility functions

**pipe.h**-
  contains declerations of pipe and pipe utility functions
  
**main.c**-
  sample test bench for pipe testing
  
## PIPE DOCUMENTATION
Pipe can be used for data sharing between different threads. Pipe is extremely useful for concurrent program. Concurrent program may be model of hardware system, software application, etc.

### pipe definition
A pipe is defined by following syntax:
 > pipe_t \*<*pipe-name*>;
      
### pipe initialization
Initialization of the defined is done using:
>pipe_init( pipe_t <*pipe-name*>, int *<pipe-size>*, int *<buffer-pointer>*);
  
### pipe read
> int pipe_read( pipe_t <*pipe-name*>);
### pipe write
> void pipe_read( pipe_t <*pipe-name*>, int <*val*> );
