#include<iostream>
#include <vector>
#include<unordered_map>

typedef long long ll;

using namespace std;


ll getMaxPolnWithCloud(unordered_map<ll,ll>xToP,vector<ll> l,vector<ll> r)
{
	ll m = l.size();
	ll maxPoln = 0,poln;
	for(ll i=0;i<m;i++)
	{
		poln =0;
		for(ll j=l[i];j<r[i];j++)
		{
			if(xToP.find(j)!=x.end())
			{
				poln += xToP[j];
				maxPoln = max(maxPoln,poln);
			}
		}
	}
	return maxPoln;
}

ll getPolnWithoutCloud(unordered_map<ll,ll>xToP,vector<ll> l,vector<ll> r)
{
	
}

int main()
{
	ll n,m,temp;
	vector<ll>p(n+1),x(n+1),y(m+1),rg(m+1),l(m+1),r(m+1);

	for(ll i=0;i<n;i++)
		cin>>p[i];

	for(ll i=0;i<n;i++)
		cin>>x[i];

	unordered_map<ll,ll>xToP;

	for(ll i=0;i<n;i++)
	{
		xToP[x[i]] = p[i];
	}

	for(ll i=0;i<m;i++)
		cin>>y[i];

	for(ll i=0;i<m;i++)
		cin>>rg[i];

	for(ll i=0;i<m;i++)
		{
			l[i] = y[i]-rg[i];
			r[i] = y[i]-rg[i];
		}

	ll maxPolnWithCloud = getMaxPolnWithCloud(xToP,l,r);
	ll PolnWithoutCloud = getPolnWithoutCloud(xToP,l,r);


	return 0;
}