#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	long long n,m,c;
	long long t;
	cin>>t;

	for (long long cases = 0; cases < t; ++cases)
	{
		
		cin>>n >>m >>c;


		if (n*m < c)		
		{
			cout<<0 <<endl;
			continue;
		}else if(n*m==c)
		{
			
			cout<<1 <<endl;
			continue;
		}


		long long i=1,ct=-1;
		long long arr[1000000];

	//find numbers divides c
		while(i<=c)
		{
			if (c%i==0)
			{
				++ct;
				arr[ct]=i;
				
			}
			i++;
		}

		long long count=0;
		
		//trying all possible combinations which satisfy our conditions
		for (long long i = 0; i <=ct; ++i)
		{
			
				if(arr[i]>n) break;
			for (long long j = 0; j <=ct; ++j)
			{
				if(arr[j]>m) break;
				
				if (arr[i]*arr[j]==c && ((arr[i]<=n && arr[j]<=m)))
				{
					count++;
					break;
				}
			}
		}

		cout<<count <<endl;

	}



	return 0;
}
