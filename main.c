#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include"pipe.h"
#define NUM_WORDS 89

pipe_t pipe_1;

void *write_func_core ( void *argv );
void *read_func_core ( void *argv );

int main() {
	pipe_init( &pipe_1, 2 );
	
	pthread_t wthread;
	pthread_t rthread;
	
	pthread_create(	&wthread, NULL, write_func_core, NULL);
	pthread_create(	&rthread, NULL, read_func_core, NULL);

	pthread_join( wthread, NULL);	
	pthread_join( rthread, NULL);

	return 0;
}

void *write_func_core ( void *argv ){
	int i;
	
	for( i = 0; i < NUM_WORDS; i++ ){
		/* producer does this repeatedly */
		pipe_write( &pipe_1, i );
		fprintf( stdout, "written value = %d\n", i );
	}
	pthread_exit( NULL );	
}

void *read_func_core ( void *argv ){
        int i, data;
        
	for( i = 0; i < NUM_WORDS; i++ ){
		data = pipe_read( &pipe_1 );
                fprintf( stdout, "--------------------read value = %d\n", data );

        }
        pthread_exit( NULL );

}
