#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include"fifo.h"

#define NUM_WORDS 128
 
pipe_width_ten_t pipe;
pthread_mutex_t use_fifo;
sem_t full_count;
sem_t empty_count;


int main( ){
	pipe.rptr = 0;
	pipe.wptr = 0;

	/*writing thread*/
	sem_init( &full_count, 0, 0 );
	sem_init( &empty_count, 0, 10 );

	pthread_t wthread;
	pthread_t rthread;
	pthread_create(	&wthread, NULL, write_func_core, NULL);
	pthread_create(	&rthread, NULL, read_func_core, NULL);
	
	pthread_join( wthread, NULL);	
	pthread_join( rthread, NULL);
	
	sem_destroy( &full_count );
	sem_destroy( &empty_count );
	
	return 0;
}

void *write_func_core ( void *argv ){
	int i;
	for( i = 0; i < NUM_WORDS; i++ ){
		/* producer does this repeatedly */
		sem_wait( &empty_count );
			pthread_mutex_lock( &use_fifo );
			write( i );
			pthread_mutex_unlock( &use_fifo );
			sem_post( &full_count );
			fprintf( stdout, "written value = %d\n", i );

	}
	pthread_exit( NULL );	
}

void *read_func_core ( void *argv ){
        int i, data;
        for( i = 0; i < NUM_WORDS; i++ ){
		sem_wait( &full_count);
		//	printf("kkkkkk---------------");
                	pthread_mutex_lock( &use_fifo );
                	data = read( );
                	pthread_mutex_unlock( &use_fifo );
			sem_post( &empty_count );
                	fprintf( stdout, "read value = %d\n", data );

        }
        pthread_exit( NULL );

}

int read( ){
	int data;
	data =  pipe.pipe[pipe.rptr];
	pipe.rptr = (pipe.rptr + 1)%10;	
	return data;
}

int write( int data ){
	pipe.pipe[pipe.wptr] = data;
	pipe.wptr = (pipe.wptr + 1)%10;
	return 0;
}
