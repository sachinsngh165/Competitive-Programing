#include<stdio.h>
#include<string.h>

int prime(int* arr,int L,int H)
{
	int flag=0;
	for(int j=L;j<=H;j++)
	{
		for(int i=0;i<num;i++)
	  {
		  
		  if(arr[i]%(i+2)==0)
		  {
			  flag=1;
			  break;
			  }
	   if(flag==1)
			  break;
		  
		  }
		  if(flag==1) return 1;
		   else return 0;
		
    }
	 
}



int main()
{
	int N,X;
	scanf("%d%d",&N,&X);
	int a[N];
	for(int i=0;i<N;i++)
	 scanf("%d",&a[i]);

     int count=0,sum=0;
      for(int i=0;i<N;i++)
       {
		   flag=0;
		   sum=a[i];
		  if(prime(a[i]))
		    flag=1;
		   for(int j=i+1;j<N;j++)
		    {
				if(flag==0)
				 if(prime(a[j])
				  flag=1;
				  
				if(sum<X)
				
			}
			
			if(flag==0)
			 sum=0;
		   
    }



}
