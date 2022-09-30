#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createarry(struct myArray * a, int tsize, int usized){ 
    a->total_size = tsize;
    a->used_size = usized;
    a->ptr = (int *) malloc(tsize*sizeof(int));
    // (*a).total_size = tsize;
    // (*a).used_size = usized;
    // (* a).ptr = (int *) malloc(tsize*sizeof(int));
}

void show(struct myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}


void setval(struct myArray *a){
    int n;
//     for 2nd
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d: ",i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
    
}


int main()
{
    struct myArray marks;
    createarry(&marks,10,2);
    printf("We r running setval now\n");
    setval(&marks);
    printf("We r running setval now\n");
    show(&marks);
    return 0;
}
















// #include <stdio.h>
// #include <stdlib.h>

// struct myarray
// {
//     int tsize;
//     int usize;
//     int* ptr;

// };

// void createArray(struct myarray* a,int t1size,int u1size){
//     (*a).tsize = t1size;
//     (*a).usize = u1size;
//     (*a).ptr = (int*)malloc(t1size*sizeof(int));
// }

// void setval(struct myarray * a){
//     for (int i = 0; i < (*a).usized; i++)
//     {
//         int n;
//         printf("Enter the element at %d: ",i);
//         scanf("%d",&n);
//         (*a).ptr[i]=n;
//     }
     
// }

// int main()
// {
//     int ts,us;
//     printf("Enter the total size: ");
//     scanf("%d",ts);
//     printf("Enter the used size: ");
//     scanf("%d",us);
//     struct myarray marks;
//     createArray(&marks,ts,us);
//     setval(&marks);
//     return 0;
// }








































