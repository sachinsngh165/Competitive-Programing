#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

ll x,y,z;

ll t;
cin>>t;
for (ll cases = 0; cases < t; ++cases)
{
	ll n,q;
	cin>>n >>q;
	ll f[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>f[i];
	}

if (n==1)
{
	ll i=1,flag=0;;
	for (int a1 = 0; a1 <=10000000; ++a1)
	{
		if (a1==f[0])
			{
				x=a1;

				for (int i = 0; i < q; ++i)
	{
		ll xi;
		cin>>xi;
		ll ans=(long long)(pow(x,xi));
		ans=ans%(1000000000+7);
		cout<<ans <<" ";
	}
				break;


			}

	
	}

	
}
else if (n==2)
{
	ll i=1,flag=0;;
	for (int a1 = 0; a1 <=10000; ++a1)
	{
		if (flag==1)
		{
			break;
		}

		for (int a2 = 0; a2 <=10000; ++a2)
	{
				if ((pow(a1,1)+pow(a2,1)==f[0]) && (pow(a1,2)+pow(a2,2)==f[1]))
			{
				x=a1;
				y=a2;
				flag=1;

				for (int i = 0; i < q; ++i)
					{
						ll xi;
						cin>>xi;
						ll ans=(long long)(pow(x,xi)+pow(y,xi));
						ans=ans%(1000000000+7);
						cout<<ans <<" ";
					}

				break;

			}
	}
	
	}

	
}
else if (n==3)
	{
		ll i=1,flag=0;;
	for (int a1 = 0; a1 <=1000; ++a1)
	{
		if (flag==1)
		{
			break;
		}

		for (int a2 = 0; a2 <=1000; ++a2)
		{
		if (flag==1)
		{
			break;
		}
		for (int a3 = 0; a3 <=1000; ++a3)
		{	
			if ((pow(a1,1)+pow(a2,1)+pow(a3,1)==f[0]) && (pow(a1,2)+pow(a2,2)+pow(a3,2)==f[1]) && 
				(pow(a1,3)+pow(a2,3)+pow(a3,3)==f[2]))
			{
				x=a1;
				y=a2;
				z=a3;
				flag=1;
				for (int i = 0; i < q; ++i)
				{
					ll xi;
					cin>>xi;
					ll ans=(long long)(pow(x,xi)+pow(y,xi)+pow(z,xi));
					ans=ans%(1000000000+7);
					cout<<ans <<" ";
				}

				break;
			}
				

		}
			
		}
	}
	
	}

	
	cout<<endl;



}



}