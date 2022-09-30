#include <stdio.h>
#include <stdlib.h>

struct Node
{
     int data;
     struct Node *next;
};

struct Node *newNode(int x)
{
     struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
     temp->data = x;
     temp->next = NULL;
     return temp;
}

// function to find out middle element
struct Node *middle(struct Node *start, struct Node *last)
{
     if (start == NULL)
          return NULL;

     struct Node *slow = start;
     struct Node *fast = start->next;

     while (fast != last)
     {
          fast = fast->next;
          if (fast != last)
          {
               slow = slow->next;
               fast = fast->next;
          }
     }

     return slow;
}

// Function for implementing the Binary
// Search on linked list
struct Node *binarySearch(struct Node *head, int value)
{
     struct Node *start = head;
     struct Node *last = NULL;

     do
     {
          // Find middle
          struct Node *mid = middle(start, last);

          // If middle is empty
          if (mid == NULL)
               return NULL;

          // If value is present at middle
          if (mid->data == value)
               return mid;

          // If value is more than mid
          else if (mid->data < value)
               start = mid->next;

          // If the value is less than mid.
          else
               last = mid;

     } while (last == NULL ||
              last != start);

     // value not present
     return NULL;
}

// Driver Code
int main()
{
     struct Node *head = newNode(1);
     head->next = newNode(4);
     head->next->next = newNode(7);
     head->next->next->next = newNode(8);
     head->next->next->next->next = newNode(9);
     head->next->next->next->next->next = newNode(10);
     int value = 8;
     if (binarySearch(head, value) == NULL)
          printf("Value not present\n");
     else
          printf("Value Present\n");
     return 0;
}