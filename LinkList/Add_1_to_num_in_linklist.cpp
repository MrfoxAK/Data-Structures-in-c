class Solution
{
public:
     Node *addOne(Node *head)
     {
          // Your Code here
          // return head of list after adding one
          int num = 0;
          Node *p;
          while (p != NULL)
          {
               num = num * 10 + (p->data);
               p = p->next;
          }
          num = num + 1;
          Node *newhead = NULL;
          Node *new_node;
          Node *temp;
          int r;
          while (num)
          {
               r = num % 10;
               new_node = new Node(r);
               new_node->next = NULL;
               if (newhead == NULL)
               {
                    newhead = temp = new_node;
               }
//                else 2nd
               else
               {
                    temp->next = new_node;
               }
               num /= 10;
               
          }
          return newhead;
     }
};
