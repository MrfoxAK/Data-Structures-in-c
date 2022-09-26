

// You are required to complete this method

Node *subLinkedList(Node *l1, Node *l2)
{
     // Your code here
     int lnum1 = 0;
     int lnum2 = 0;
     Node *p = l1;
     Node *q = l2;
     while (p != NULL)
     {
          lnum1 = (lnum1 * 10) + (p->data);
          p = p->next;
     }
     while (q != NULL)
     {
          lnum2 = (lnum2 * 10) + (q->data);
          q = q->next;
     }
     int sub = lnum1 - lnum2;
     int r;
     Node *head;
     Node *temp;
     while (sub)
     {
          r = sub % 10;
          Node *newNode = new Node(r);
          newNode->next = NULL;
          if (head == NULL)
          {
               head = temp = newNode;
          }
          else
          {
               temp->next = newNode;
               temp = newNode;
          }
          sub /= 10;
     }
     return head;
}