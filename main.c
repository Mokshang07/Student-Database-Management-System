#include "header.h"

int main(){

        SLL * headptr=0;
        int c,op;
        char ch;

        while(1)
        {
                printf("\n");
                printf(" *****STUDENT RECORD MENU*****\n");
                printf(" ------------------------------\n");
                printf(" a/A\t:add new record\n d/D\t:delete record\n s/S\t:show the list\n m/M\t:modify a record\n v/V\t:save\n e/E\t:exit\n t/T\t:sort     the list\n l/L\t:delete all the records\n r/R\t:reverse the list\n");

                printf(" ------------------------------\n");
                printf(" Enter your choice:");
                scanf(" %c",&ch);
                ch=my_toupper(ch);

                switch(ch)
                {
                        case 'A':stud_add(&headptr);break;

                        case 'D':{
                                         if(headptr==0)
                                         {
                                                 printf(" No record found\n");
                                                 break;
                                         }
                                         printf(" 1\t:name wise\n 2\t:rollno wise\n");
                                         printf(" Enter your choice:");
                                         scanf(" %d",&op);
                                         switch(op){
                                                 case 1:delete_name(&headptr);break;
                                                 case 2:delete_rollno(&headptr);break;
                                                 default:printf(" Invalid option\n");break;
                                         }
                                 }

                        case 'S':stud_show(headptr);break;

                        case 'T':{
                                         char ch1;
                                         if(headptr==0)
                                         {
                                                 printf(" No record found\n");
                                                 break;
                                         }
                                         printf(" n/N\t:sort with name\n p/P\t:sort with percentage\n");
                                         printf(" Enter your choice:");
                                         scanf(" %c",&ch1);
                                         ch1=my_toupper(ch1);

                                         switch(ch1)
                                         {
                                                 case 'N':sort_name(headptr);break;
                                                 case 'P':sort_marks(headptr);break;
                                                 default:printf(" Invalid option\n");break;
                                         }
                                         break;
                                 }

                        case 'L':deleteAll(&headptr);break;
                        case 'R':reverseLinks(&headptr);break;
                        case 'E':free_memory(headptr); exit(0);
                        default:printf(" Invalid option\n");break;
                }
        }
}

int c1=1;

void stud_add(SLL **ptr)
{
        SLL *new = malloc(sizeof(SLL));
        new->rollno = c1++;

        printf(" Enter name and marks:");
        scanf("%s %f", new->name, &new->marks);

        new->next = NULL;

        if (*ptr == NULL) {
                *ptr = new;
                return;
        }

        SLL *temp = *ptr;
        while (temp->next != NULL)
                temp = temp->next;

        temp->next = new;
}

void delete_name(SLL **ptr){

        char name[20];
        printf(" Enter name to delete: ");
        scanf("%s", name);

        SLL *temp = *ptr;
        int count = 0;

        while (temp) {
                if (strcmp(name, temp->name) == 0)
                        count++;
                temp = temp->next;
        }

        if (count == 0) {
                printf(" No record found with this name\n");
                return;
        }

        if (count == 1) {

                SLL *del = *ptr, *prev = NULL;

                while (del) {
                        if (strcmp(name, del->name) == 0) {
                                if (del == *ptr)
                                        *ptr = del->next;
                                else
                                        prev->next = del->next;

                                free(del);
                                printf(" Record deleted successfully\n");
                                return;
                        }
                        prev = del;
                        del = del->next;
                }
        }

        printf("\nMultiple records found:\n");
        printf("RollNo\tName\t\tMarks\n");
        printf("-----------------------------\n");

        temp = *ptr;
        while (temp) {
                if (strcmp(name, temp->name) == 0) {
                        printf("%-7d %-10s %.2f\n",
                               temp->rollno, temp->name, temp->marks);
                }
                temp = temp->next;
        }

        delete_rollno(ptr);
}

void delete_rollno(SLL **ptr){

        int rollno;
        printf(" Enter rollno to delete:");
        scanf("%d",&rollno);

        SLL *del=*ptr,*prev;

        while(del){
                if(rollno==del->rollno)
                {
                        if(del==*ptr)
                                *ptr=del->next;
                        else
                                prev->next=del->next;

                        free(del);
                        printf("Record deleted succesfully\n");
                        return;
                }
                prev=del;
                del=del->next;
        }

        printf("No records found\n");
}

void stud_show(SLL *ptr)
{
        if(ptr==0)
        {
                printf("Record not found\n");
                return;
        }

        printf("\n---------------------------------\n");
        printf("RollNo\tName\t\tMarks");
        printf("\n---------------------------------\n");

        while(ptr)
        {
                printf("%d\t%s\t\t%.2f\n",
                       ptr->rollno,ptr->name,ptr->marks);
                ptr=ptr->next;
        }
}

void sort_marks(SLL *ptr){

        int i,j,c=countnode(ptr);
        SLL *p1=ptr,*p2,t;

        for(i=0;i<c;i++){
                p2=p1->next;
                for(j=0;j<c-1-i;j++){
                        if(p1->marks>p2->marks){

                                t.marks=p1->marks;
                                strcpy(t.name,p1->name);
                                t.rollno=p1->rollno;

                                p1->marks=p2->marks;
                                strcpy(p1->name,p2->name);
                                p1->rollno=p2->rollno;

                                p2->marks=t.marks;
                                strcpy(p2->name,t.name);
                                p2->rollno=t.rollno;
                        }
                        p2=p2->next;
                }
                p1=p1->next;
        }

        printf(" Data sorted\n");
}

void sort_name(SLL *ptr){

        int i,j,c=countnode(ptr);
        SLL *p1=ptr,*p2,t;

        for(i=0;i<c;i++){
                p2=p1->next;
                for(j=0;j<c-1-i;j++){
                        if(strcmp(p1->name,p2->name)>0){

                                t.marks=p1->marks;
                                strcpy(t.name,p1->name);
                                t.rollno=p1->rollno;

                                p1->marks=p2->marks;
                                strcpy(p1->name,p2->name);
                                p1->rollno=p2->rollno;

                                p2->marks=t.marks;
                                strcpy(p2->name,t.name);
                                p2->rollno=t.rollno;
                        }
                        p2=p2->next;
                }
                p1=p1->next;
        }

        printf(" Data sorted\n");
}

void deleteAll(SLL **ptr)
{
        if(*ptr==0){
                printf("No record found\n");
                return;
        }

        int c=1;
        SLL *del=*ptr;

        while(del)
        {
                *ptr=del->next;
                free(del);
                printf("Node position deleted:%d\n",c++);
                sleep(1);
                del=*ptr;
        }

        printf("All records deleted\n");
}

void reverseLinks(SLL **ptr)
{
        if(*ptr==0)
        {
                printf("No records found\n");
                return;
        }

        int c=countnode(*ptr);

        if(c>1){

                SLL**a=malloc(sizeof(SLL*)*c);
                SLL *t=*ptr;
                int i=0;

                while(t){
                        a[i++]=t;
                        t=t->next;
                }

                for(i=c-1;i>0;i--)
                        a[i]->next=a[i-1];

                a[0]->next=0;
                *ptr=a[c-1];
        }
}

char my_toupper(char ch)
{
        if (ch >= 'a' && ch <= 'z')
                return ch - 32;
        else
                return ch;
}

int countnode(SLL *ptr)
{
        int c=0;

        while(ptr)
        {
                c++;
                ptr=ptr->next;
        }

        return c;
}

void free_memory(SLL *ptr){

        SLL *del=ptr;

        while(del)
        {
                ptr=del->next;
                free(del);
                del=ptr;
        }
}

