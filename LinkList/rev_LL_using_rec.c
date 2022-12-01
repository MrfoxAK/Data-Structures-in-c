#include
using namespace std;

struct Node
{
     int data;
     struct Node *next;
     Node(int data)
     {
          this->data = data;
          next = NULL;
     }
};

struct LinkedList
{
     Node *head;
     LinkedList()
     {
          head = NULL;
     }

     Node *reverse(Node *head)
     {
          if (head == NULL || head->next == NULL)
               return head;
          // Recursive call
          Node *rest = reverse(head->next);
          head->next->next = head;

          head->next = NULL;

          return rest;
     }

     void print()
     {
          struct Node *temp = head;
          while (temp != NULL)
          {
               cout << temp->data << " ";
               temp = temp->next;
          }
     }

     void push(int data)
     {
          Node *temp = new Node(data);
          temp->next = head;
          head = temp;
     }
};

int main()
{
     LinkedList ll;
     ll.push(320);
     ll.push(34);
     ll.push(315);
     ll.push(385);

     cout << "Linked List Before Reversing\n";
     ll.print();

     ll.head = ll.reverse(ll.head);

     cout << "\nLinked List After Reversing \n";
     ll.print();
     return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//      int data;
//      struct node *next;
// };

// struct node *head = NULL;

// struct node *createlinklist(int n);
// void display(struct node *head);

// struct node* rev_LL_rec(struct node* p){
//      if (p->next==NULL)
//      {
//           head = p;
//           return;
//      }
//      rev_LL_rec(p->next);
//      struct node* q = p->next;
//      q->next = p;
//      p->next = NULL;
// }

// int main()
// {
//      int n;
//      struct node *head = NULL;
//      printf("Enter how many nodes: ");
//      scanf("%d", &n);
//      head = createlinklist(n);
//      display(head);
//      printf("NULL");
//      rev_LL_rec(head);
//      display(head);
//      return 0;
// }

// struct node *createlinklist(int n)
// {
//      struct node *temp = NULL;
//      struct node *p = NULL;
//      for (int i = 0; i < n; i++)
//      {
//           temp = (struct node *)malloc(sizeof(struct node));
//           temp->next = NULL;
//           printf("Enter data: ");
//           scanf("%d", &temp->data);
//           if (head == NULL)
//           {
//                head = temp;
//           }
//           else
//           {
//                p = head;
//                while (p->next != NULL)
//                {
//                     p = p->next;
//                }
//                p->next = temp;
//           }
//      }
//      return head;
// }

// void display(struct node *head)
// {
//      struct node *p = head;
//      while (p != NULL)
//      {
//           printf("%d->", p->data);
//           p = p->next;
//      }
// }