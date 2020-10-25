/* fifo.h */
#ifndef __PIPE_H__
 #define __PIPE_H__
 #include<stdio.h>
 #include<pthread.h>
 #include<semaphore.h>
 
  typedef struct _pipe_t {
  	int *pipe;
	int wptr, rptr;
	unsigned int size;
	sem_t full_count, empty_count;
	pthread_mutex_t use_pipe;
  } pipe_t;
  
  int pipe_read( pipe_t *pipe );
  int pipe_write( pipe_t *pipe, int data );
  int pipe_init( pipe_t *pipe, unsigned int size, int *buff ); 
  
#endif

