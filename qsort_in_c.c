#include <stdio.h>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
   int n;

   printf("Before sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) 
   {
      printf("%d ", values[n]);
   }

   qsort(values, 5, sizeof(int), cmpfunc);

   printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) 
   {   
      printf("%d ", values[n]);
   }


   std::vector<int> V;
// (fill V with values)
std::sort(V.begin(), V.end());

int numValsLessThan5 = std::lower_bound(V.begin(), V.end(), 5) - V.begin();
int numValsLessThanOrEqualTo5 = std::upper_bound(V.begin(), V.end(), 5) - V.begin();
  
   return(0);
}