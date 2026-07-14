#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct student {
    int rollno;
    char name[20];
    float marks;
    struct student *next;
} SLL;

void stud_add(SLL **);
void delete_name(SLL **);
void delete_rollno(SLL **);
void stud_show(SLL *);
void sort_marks(SLL *);
void sort_name(SLL *);
void deleteAll(SLL **);
void reverseLinks(SLL **);
char my_toupper(char);
int countnode(SLL *);
void free_memory(SLL *);
