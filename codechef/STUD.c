#include<stdio.h>
#include<string.h>
int main()
{
	int t,alpha[26];
	char str[100000];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int j=0;
		int cost=0,index1,index2;
	   
	   scanf(" %s",str);
	    j=strlen(str);
		
		//input costs
		for(int k=0;k<26;k++)
		  scanf("%d",&alpha[k]);
			
		for(int k=0;k<j;k++)
		{

			if(str[k]!=str[j-1])
			{
			 
				 index1=(int)str[k]-97;
				 index2=(int)str[j-1]-97;
				if(alpha[index1]<alpha[index2]) 
				cost+=alpha[index1];
				else
				  cost+=alpha[index2];
				 
			}
			j--;
			
		}
	   printf("%d\n",cost);
	
	}
	
	return 0;
}
