#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

	ll t;
	cin>>t;
	for (ll cases = 0; cases < t; ++cases)
	{
		ll s,v;
		cin>>s >>v;

	
		double time = ((double)(2*s))/(3*v);
		cout<<fixed <<time <<endl;


	}

	return 0;
}