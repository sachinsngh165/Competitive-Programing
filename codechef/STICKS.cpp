#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	
	int cases;
	cin>>cases;
	for (int i = 0; i < cases; i++)
	{
		
		int n;
		cin>>n;
		int arr[1000];
		for (int j = 0; j < n; j++)
		{
			cin>>arr[j];
		}
		
		sort(arr,arr+n);
		
		int l1=-1,l2=-1;
		
		for (int j = n-1; j > 0 ; )
		{
			if(l1>0 && l2>0)
			 break;
			
			
			if(arr[j] == arr[j-1])
			 {
				 if(l1>0)
				  l2=arr[j];
				  
				  else l1=arr[j];
				 j-=2;
				 
			 }
				 
			else j--;
			
		}
		
		 if(l1>0 && l2>0)
		 cout<<l1*l2 <<endl;
		 else  cout<<-1 <<endl;
		 
		
		
		
		
		
		
	}
	
	return 0;
	
	}
