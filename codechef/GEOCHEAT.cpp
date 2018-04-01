#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct  cord
{
	ll x;
	ll y;
};

ull distance(cord A,cord B)
{
	ull dist= (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
	return dist;
}



int main()
{
	ll n;
	cin>>n;
	vector<cord> v(n);
	
	//input the co-ordinates
	for (ll i = 0; i < n; ++i)
	{
		cord temp;
		cin>>temp.x;
		cin>>temp.y;

		v[i] = temp;
	}

	for (ll range = 0; range < n; ++range)
	{
		ull max_dist = 0;

		for (ll startindex = 0; startindex <=range; ++startindex)
			{
		
			for (int size = startindex; size <=range; ++size)
				{

				max_dist = max(max_dist,distance(v[startindex],v[size]));
				
				}

		}

		cout<<max_dist <<endl;
	}



	return 0;
}