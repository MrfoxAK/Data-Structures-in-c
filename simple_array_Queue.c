#include <stdio.h>
#define N 5

int queue[N];
int r=-1;
int f=-1;

void enQueue(int val){
     if (r==N-1)
     {
          printf("Queue OverFlow\n");
     }
     // else if (f==-1 && r==-1)
     // {
     //      f=r=0;
     //      queue[r]=val;
     // }
     else
     {
          r++;
          queue[r]=val;
     }
}

void deQueue(){
     if (f==-1 && r==-1)
     {
          printf("Queue UNderFlow\n");
     }
     else if (f==r)
     {
          f=r=-1;
     }
     else{
          f++;
          printf("%d element deQueued\n",queue[f]);
     }
}

void display(){
     if (f==-1 && r==-1)
     {
          printf("Queue is Empty\n");
     }
     else{
          for (int i = f+1; i <= r; i++)
          {
               printf("%d ",queue[i]);
          }
     }
}

int main()
{
     enQueue(2);
     enQueue(23);
     enQueue(234);
     deQueue();
     deQueue();
     display();
     return 0;
}