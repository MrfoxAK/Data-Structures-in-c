// int getNthFromLast(struct Node *head, int n)
// {
//     int count=0,i=0;
//     struct Node *ptr = head;
//     struct Node *temp=head;
//     while(ptr!=NULL){
//         ptr=ptr->next;
//         count++;
//     }
//     int m = (count-n)+1;
//     if(n>count)
//         return -1;
//     else{
//         while(i<=m){
//             temp=temp->next;
//             i++;
//         }
//         return temp->data;
//     }    
// }