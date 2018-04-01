#include<stdio.h>

	
int min_value(int* arr,int N)
{
	int min;
	min=arr[0];
	for(int i=1;i<N;i++)
	{
		if(arr[i]<min)
		min=arr[i];
		
		}
	return min;
	}

void LCM(int* arr,int N)
{
	//find min
	int temp=1,true=1;
	int min=min_value(arr,N);
for(int i=2;i<=min;i++)
{
	 true=1;
 for(int j=0;j<N;j++)
	 { 
		if(arr[j]%i!=0)
	    {
			true=0;
			break;  
	     }
	     
	  }
	  if(true==1)
	  temp=i;
  }
  
  for(int i=0;i<N;i++)
  printf("%d ",arr[i]/temp);
}

	
int main()
{
	int t;
	scanf("%d",&t);
	if(t>100)
	return 0;
	
	for(int j=0;j<t;j++)
  {	int N;
	scanf("%d",&N);
	if(N>50)
	return 0;
	
  int arr[N];
  for(int i=0;i<N;i++)
  scanf("%d",&arr[i]);
  
  LCM(arr,N);
   }
	
	}
