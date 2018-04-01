#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	long long m,q;
	cin>>m >>q;

	long long parr[m];

	for (int i = 0; i < m; ++i)
	{
		cin>>parr[i];
	}


	sort(parr,parr+m);

	
	for (int i = 0; i < q; ++i)
	{
		
		long long x,y,ct=0;
		cin>>x >>y;
		set<int> s;

		



		for (int j = 0; j < m; ++j)
		{
			for (long long k = x; k<=y; ++k)
			{
				if (k%parr[j]==0 && !s.find(k))
				{
					s.insert(k);
				}
			}

			
		}

		cout<<s.size() <<endl;
	}
	
	



	return 0;
}
