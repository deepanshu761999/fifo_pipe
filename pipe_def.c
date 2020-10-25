#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include"pipe.h"

int pipe_write ( pipe_t *pipe, int data ){
	
	sem_wait( &(*pipe).empty_count );
	pthread_mutex_lock( &(*pipe).use_pipe );
	(*pipe).pipe[(*pipe).wptr] = data;
	(*pipe).wptr = ( (*pipe).wptr + 1 ) % (*pipe).size;
	pthread_mutex_lock( &(*pipe).use_pipe );
	sem_post( &(*pipe).full_count );
	return 0;
}

int pipe_read ( pipe_t *pipe ){
	int data;

	sem_wait( &(*pipe).full_count ) ;
	pthread_mutex_lock( &(*pipe).use_pipe );
	data = (*pipe).pipe[(*pipe).rptr];
	(*pipe).rptr = ( (*pipe).rptr + 1 ) % (*pipe).size;
	pthread_mutex_unlock( &(*pipe).use_pipe );
	sem_post( &(*pipe).empty_count );
	return data;
}

int pipe_init( pipe_t *pipe, const unsigned int size = 1 ){
	(*pipe).wptr = 0;
	(*pipe).rptr = 0;
	(*pipe).size = size;
	sem_init( &(*pipe).full_count, 0, 0);
	sem_init( &(*pipe).empty_count, 0, size );
	return 0;
}
