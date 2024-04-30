#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* next;
};

struct node* createNode(int data){
     struct node* new = (struct node*)malloc(sizeof(struct node));
     new->data = data;
     new->next = NULL;
     return new;
}

void display(struct node* head){
     struct node* temp = head;
     while (temp != NULL)
     {
          printf("%d -> ", temp->data);
          temp = temp->next;
     }
}

struct node* create(struct node* head){
     int c = 1;
     int data;
     struct node* temp = NULL;
     while (c)
     {
          printf("Enter data: ");
          scanf("%d",&data);
          struct node* new = createNode(data);
          if(head == NULL){
               head = temp = new;
          }
          else{
               temp->next = new;
               temp = new;
          }
          printf("Do u want to continue? (1/0): ");
          scanf("%d",&c);
     }
     return head;
}

struct node* add_two_Lists(struct node* head1, struct node* head2){
     struct node* temp1 = head1;
     struct node* temp2 = head2;
     int num1 = 0;
     int num2 = 0;
     int total = 0;
     while (temp1!=NULL)
     {
          num1 = num1*10 + temp1->data;
          temp1 = temp1->next;
     }
     while (temp2!=NULL)
     {
          num2 = num2*10 + temp2->data;
          temp2 = temp2->next;
     }
     total = num1 + num2;
     int c = 0;
     int number = total;
     while (number>0)
     {
          c++;
          number = number/10;
     }
     // printf("The Total is %d\n",c);
     number = total;
     int arr[c];
     int i = 0;
     while (number>0)
     {
          arr[i] = number%10;
          number = number/10;
          i++;
     }
     int temp,j,z;
     for (z = 0, j = c-1; z < j; z++, j--) {
          temp = arr[z];
          arr[z] = arr[j];
          arr[j] = temp;
     }
     for (int i = 0; i < c; i++)
     {
          printf("%d ",arr[i]);
     }
     struct node* head = NULL;
     struct node* newNode = NULL;
     struct node* temp4 = NULL;
     int k = 0;
     int s = 0;
     while (k<c)
     {
          newNode = (struct node *)malloc(sizeof(struct node));
          newNode->data = arr[s];
          s++;
          newNode->next = NULL;
          if (head == NULL)
          {
               head = temp4 = newNode;
          }
          else
          {
               temp4->next = newNode;
               temp4 = newNode;
          }
          k++;
     }
     return head;
}

int main()
{
     struct node* head = NULL;
     struct node* head1 = NULL;
     struct node* head2 = NULL;
     head1 = create(head1);
     head2 = create(head2);
     printf("The 1st is......\n");
     display(head1);
     printf("\nThe 2nd is......\n");
     display(head2);
     printf("\n");
     head = add_two_Lists(head1,head2);
     printf("\nThe Final LinkedList is......\n");
     display(head);
     return 0;
}