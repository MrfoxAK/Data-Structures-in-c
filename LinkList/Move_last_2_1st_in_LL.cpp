
class Solution
{
public:
     ListNode *moveToFront(ListNode *head)
     {
          ListNode *p = head->next;
          ListNode *ptr = head;
          if (head->next == NULL)
          {
               return head;
          }
          while (p->next != NULL)
          {
               p = p->next;
               ptr = ptr->next;
          }
          // while(ptr->next!=p){
          //     ptr=ptr->next;
          // }
          ptr->next = NULL;
          p->next = head;
          head = p;
          return head;
     }
};