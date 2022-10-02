#include <stdio.h>
#include <string.h>

// void revstr(char *str1)
// {
//      // declare variable
//      int i, len, temp;
//      len = strlen(str1); // use strlen() to get the length of str string

//      // use for loop to iterate the string
//      for (i = 0; i < len / 2; i++)
//      {
//           // temp variable use to temporary hold the string
//           temp = str1[i];
//           str1[i] = str1[len - i - 1];
//           str1[len - i - 1] = temp;
//      }
// }

void printString(char s[],int start,int end){
     for (int i = start; i <= end; i++)
     {
          printf("%c",s[i]);
     }
}

int main()
{
     char s[] = "forgeeksskeegfor";
     
     int count=0;

     // for (int i = 0; i < 7; i++)
     // {
     //      // for even part
     //      // if (s[i]==s[i+1])
     //      // {
     //      //      l=i;
     //      //      h=i+1;
     //      //      count=0;
     //      //      while (s[l]==s[h])
     //      //      {
     //      //           count++;
     //      //           l--;
     //      //           h++;
     //      //      }
     //      //      printf("%d ",count);
               
     //      // }
     //      // else if (s[i]==s[i+2])
     //      // {
     //      //      l=i;
     //      //      h=i+1;
     //      //      count=0;
     //      //      while (s[l]==s[h])
     //      //      {
     //      //           count++;
     //      //           l--;
     //      //           h++;
     //      //      }
     //      //      printf("%d ",count);
               
     //      // }
     // }
     
     
     int l,h;
     int start=0,end=1;
     for (int i = 1; i <= 16; i++)
     {
          // for even part
          l=i-1;
          h=i;
          while (l>=0 && h<16 && s[l]==s[h])
          {
               if (h-l+1>end)
               {
                    start=l;
                    end=h-l+1;
               }
               l--;
               h++;
          }
          

          //for odd part
          i=i-1;
          h=i+1;
          while (l>=0 && h<16 && s[l]==s[h])
          {
               if (h-l+1>end)
               {
                    start=l;
                    end=h-l+1;
               }
               l--;
               h++;
          }
     }
     
     printString(s,start,start+end-1);
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     // int k = 0;
     // char s2[50];
     // char s3[50];
     // int j = 0;
     // for (int i = 0; i < 8; i++)
     // {
     //      k = i;
     //      j = 0;
     //      while (s[k] != '\0')
     //      {
     //           s2[j] = s[k];
     //           j++;
     //           k++;
     //      }
     //      s2[j] = '\0';
     //      strcpy(s3,s2);
     //      strrev(s2);
     //      // puts(s3);
     //      // puts(s2);
     //      int res = strcmp(s2,s3);
     //      if (res==0)
     //      {
     //           puts(s3);
     //      }
     // }
     
     
     return 0;
}