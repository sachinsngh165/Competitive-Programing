#include <iostream>
#include <math.h>
using namespace std;

typedef unsigned long long int ll;

int main()
{
	ll q,n,k;

	cin>>q;



	for (int i = 0; i < q; ++i)
	{
		cin>>n >>k;

		ll num = (long long )pow(2,(int)n);
		ll a = 0,ans=0,pos = k;
		for (int j = 0; j <=n-2; ++j)
		{
			if (pos&1)
			{
				a = a + pow(2,(int)(j));
				ans = ans + num/pow(2,(int)(j+1));
			}

			pos = (k - a)/pow(2,(int)(j+1));
		}

		ans += pos;

		cout<<ans <<endl;

	}



	return 0;

}

