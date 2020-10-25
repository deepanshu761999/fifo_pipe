/* fifo.h */
#ifndef FIFO_H
 #define FIFO_H
  typedef struct _pipe_width_ten_t{
  	int pipe[10];
	int wptr, rptr;
  } pipe_width_ten_t;
  
  int read( );
  int write( int data ); 
   
  void *read_func_core ( void *argv );
  void *write_func_core ( void *argv );
  
#endif

