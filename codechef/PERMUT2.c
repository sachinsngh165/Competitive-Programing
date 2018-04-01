#include<stdio.h>

void Perm(int* arr,int size)
{
	for(int i=0;i<size;i++)
	{
		if( arr[arr[i]-1]!=(i+1))
	{	printf("not ambiguous\n");
         return;
     }
 }
	printf("ambiguous\n");
	}

int main()
{
	while(1)
	{
		int size;
	   scanf("%d",&size);
		 
		if(size==0)
		{
		break;
	    }
		 if(size<1|| size>100000)
		 return 0;
		
		 int arr[size];
		  for(int i=0;i<size;i++)
		  scanf("%d",&arr[i]);
		 
		 Perm(arr,size);
		}
	return 0;
	}
