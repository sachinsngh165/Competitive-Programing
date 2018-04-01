#include <iostream>
using namespace std;

int  main()
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


		

	

		long long count=0;
		
		//trying all possible combinations which satisfy our conditions
		for (long long i = 1; i <=n; ++i)
		{	
			if(c%i==0)
			{
					for (long long j = 1; j <=m; ++j)
					{
				
				
				if (i*j==c)
				{
					count++;
					break;
				}
					}
				
			}
				
			
		}

		cout<<count <<endl;

	}



	return 0;
}
