CC = gcc

student_db : main.o
	$(CC) main.o -o student_db

main.o : main.c header.h
	$(CC) -c main.c

clean :
	rm -f *.o student_db
