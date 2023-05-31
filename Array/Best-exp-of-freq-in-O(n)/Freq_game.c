#include <stdio.h>
int main()
{
     int A[] = {2,2,5,50,1};
     int n = 5;
     int freq[51];
     for (int i = 0; i < 51; i++)
     {
          freq[i] = 0;
     }
     for (int i = 0; i < n; i++)
     {
          freq[A[i]]++;
     }
     int minFreq=1000;
     for (int i = 0; i < 51; i++)
     {
          // printf("%d = %d\n",i,freq[i]);
          if(freq[i]<minFreq && freq[i]!=0)
               minFreq = freq[i];
     }
     int max = 0;
     for (int i = 0; i < 51; i++)
     {
          // printf("%d = %d\n",i,freq[i]);
          if(freq[i] == minFreq && i>max)
               max = i;
     }
     printf("Ans is :- %d\n",max);
     return 0;
}