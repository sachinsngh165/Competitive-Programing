#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int main()
{
	ll t;
	cin>>t;

	ll n;
	

	for (int cases = 0; cases < t; ++cases)
	{
		cin>> n;
		vector<ll> element;
		for (int i = 0; i < n; ++i)
		{
			ll temp;
			cin>>temp;
			element.push_back(temp%4);
		}

		ll p=0,q=0,r=0;
		// p = no of 1's
		// q = no of 2's
		// r = no of 3's
		ll sum =0;
		for (int i = 0,len=element.size(); i < len; ++i)
		{
			if (element[i]==1)
				p++;
			else if(element[i]==2)
				q++;
			else if(element[i]==3)
				r++;

			sum += element[i];

		}

		if (sum%4!=0)
		{
			cout<<-1 <<endl;
			continue;
		}


		ll steps=0;

		if (p>r)
		{
			steps += r;
			p = p-r;
			r=0;
		}else
		{
			steps +=p;
			r = r - p;
			p =0;
		}

		// cout<<p <<endl <<q <<endl <<r <<endl;

		// if no of 3's is 0
		if (r==0)
		{
			steps += (3*p)/4;
			steps += q/2;
			
		}else if(p==0)
		{
			steps += (3*r)/4;
			steps += q/2;
		}

		if (q%2==1)
			steps ++;
		

		cout<<steps <<endl;

	}

}