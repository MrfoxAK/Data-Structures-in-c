#include <stdio.h>
#include <stdlib.h>

struct student
{
     int roll;
     char name[20];
     float marks;
};

int main()
{
     struct student s = {1,"akash",0.22};
     s.roll = 1;
     // s.name = "Akash"; //Remember that strings in C are actually an array of characters, and unfortunately, you can't assign a value to an array like this:
     struct student * ptr=NULL;
     ptr = (struct student*)malloc(sizeof(struct student));
     printf("%s",s.name);
     printf("%d\n",s.roll);
     // printf("%d\n",(*ptr).roll);
     ptr->roll = 10;
     printf("%d\n",ptr->roll);
     // ---------- Main ---------
     printf("Main\n");
     struct student * p = &s;
     printf("%d",(*p).roll);
     return 0;
}