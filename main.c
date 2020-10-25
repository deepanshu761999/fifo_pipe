#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include"pipe.h"
#define NUM_WORDS 17
#define BUFF_SIZE 2
pipe_t pipe_1;

void *write_func_core ( void *argv );
void *read_func_core ( void *argv );

int main() {
	int buff[BUFF_SIZE];
	printf( "pipe init started\n" );
	pipe_init( &pipe_1, BUFF_SIZE, buff );
	
	pthread_t wthread;
	pthread_t rthread;
	
	pthread_create(	&wthread, NULL, write_func_core, NULL);
	printf( "writing thread started\n" );
	pthread_create(	&rthread, NULL, read_func_core, NULL);
	printf( "reading thread started\n" );

	pthread_join( wthread, NULL);
	printf( "writing thread joined\n" );	
	pthread_join( rthread, NULL);
	printf( "reading thread joined\n" );

	return 0;
}

void *write_func_core ( void *argv ){
	int i;
	printf( "writing core entered\n" );
	for( i = 0; i < NUM_WORDS; i++ ){
		/* producer does this repeatedly */
		pipe_write( &pipe_1, i );
		fprintf( stdout, "written value = %d\n", i );
	}
	pthread_exit( NULL );	
}

void *read_func_core ( void *argv ){
        int i, data;
        printf( "reading core entered\n" );
	for( i = 0; i < NUM_WORDS; i++ ){
		data = pipe_read( &pipe_1 );
                fprintf( stdout, "--------------------read value = %d\n", data );

        }
        pthread_exit( NULL );

}
