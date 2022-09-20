public boolean isIdentical (Node head1, Node head2){

     Node curr1=head1;

     Node curr2=head2;

     while(curr1!=null && curr2!=null){

         if(curr1.data==curr2.data){

             curr1=curr1.next;

             curr2=curr2.next;

         }

         else{

             return false;

         }

     }

     if(curr1==null && curr2==null){

         return true;

     }

     return false;

 }