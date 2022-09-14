// User function Template for C

void removeDuplicates(struct Node *head)
{
     struct Node *p = head;
     while (p->next != NULL)
     {
          if (p->data == p->next->data)
          {
               p->next = p->next->next;
          }
          else
          {
               p = p->next;
          }
     }
}