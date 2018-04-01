#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){

	ll t;
	cin>>t;
	for(ll cases=0;cases<t;cases++)
	{
		ll n;
		cin>>n;
		ll A[n];
		for(ll i=0;i<n;i++)
		{
			cin>>A[i];
		}
	
		sort(A,A+n);

		ll flag=0;
		for(ll i=0;i<n-1;i++)
		{
			if (A[i+1]-A[i] >1)
			{
				flag=1;
				break;
			}

		}

		if (flag==1)
		{
			cout<<"NO" <<endl;
		}else cout<<"YES" <<endl;


	}
	return 0;
}