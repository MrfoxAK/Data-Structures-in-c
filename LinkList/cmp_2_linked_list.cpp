
/* Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
    
    Node(char x){
        c = x;
        next = NULL;
    }
    
};
*/

// Compare two strings represented as linked lists
int compare(Node *list1, Node *list2) 

{

     // Code Here

     while(list1 != NULL && list2 != NULL){

         if(list1->c == list2->c){

             list1 = list1->next;

             list2 = list2->next;

         }

         else if(list1->c > list2->c){

             return 1;

         }

         else{

             return -1;

         }

     }

     if(list1!=NULL){

         return -1;

     }

     else if(list2!=NULL){

         return 1;

     }

     else {

         return 0;

     }

}