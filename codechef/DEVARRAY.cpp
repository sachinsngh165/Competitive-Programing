#include<iostream>
#include<limits.h>
#define endl '\n'
using namespace std;
int main()
{
	ios::sync_with_stdio(false);

	int num,q;
	cin>>num >>q;

	int arr[100000],query[q];

	for(int i= 0;i<num;i++)
	{
	 cin>>arr[i];
	}

	 for(int i= 0;i<q;i++)
	 {
			  cin>>query[i];
         }

	 int min=INT_MAX,max=INT_MIN;

        for(int i=0;i<num;i++)
	{

		if(arr[i]<min)
			min=arr[i];


		if(arr[i]>max)
			max= arr[i];
	}

	for(int i=0;i<q;i++)
	{
		if(query[i]<=max && query[i]>=min)
		{
			cout<<"Yes" <<endl;
		}else cout<<"No" <<endl;
	}



return 0;
}
