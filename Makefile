CFLAGS = -lpthread -lrt

main_program: main.o pipe_def.o
	gcc main.o pipe_def.o ${CFLAGS} -o main_program

main.o: main.c pipe.h
	gcc ${CFLAGS} -c main.c

pipe_def.o: pipe_def.c pipe.h
	gcc ${CFLAGS} -c pipe_def.c

clean:
	rm -f main_program main.o pipe_def.o
	@echo "cleaned"
