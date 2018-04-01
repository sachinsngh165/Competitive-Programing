#include<iostream>
using namespace std;
int isMagical(int* arr,int size)
{
	int odd=0;
	
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			
			if(arr[j]%2==0)
			 break;
			 
			 odd++;
			
			
		}
		
		
	}
	
	if(odd%2==0)
	 return 1;
	 else return 0;
	
	
	}



int main()
{
	int n;
	cin>>n;
	
	for (int i = 0; i < n; i++)
	{
		int num;
		cin>>num;
		
		int arr[1000000000000],size=0;
		while(num>0)
		{	
			arr[size]=num%10;
			num/=10;
			size++;
		}
		
		
		int 
		
		
	}
	
	 
	 return 0;
	
	
	}
