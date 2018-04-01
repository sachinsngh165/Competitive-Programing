#include<iostream>
#include <math.h>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;



ll getSumOf4digits(int d0,int d1)
{
	ll m = d0 + d1;
	ll sum = (2*m)%10 + (4*m)%10 + (8*m)%10 + (6*m)%10;
	return sum;
}

ll getRemSum(ull k,int d0,int d1)
{
	ll rem = (k-3)%4;
	// cout<<rem <<endl;
	ll m = d0 + d1;
	if (rem==1)
	{
		return (2*m)%10;
	}else if (rem==2)
	{
		return (2*m)%10 + (4*m)%10;
	}else if(rem==3)
		return (2*m)%10 + (4*m)%10 + (8*m)%10;
	else 
		return 0;
}



int main()
{
	ios::sync_with_stdio(false);
	ll t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{

	 ll k,d0,d1;
      cin>>k >>d0 >>d1;
      ll d2 = (d0 + d1)%10;
      ll s = getSumOf4digits(d0,d1);
      ll x = getRemSum(k,d0,d1);

      ll sum = 0;
      ll cycles = floor((k-3)/4);

      if (k==2)
      {
      	sum = d0 + d1;
      }
      else if(k==3)
      	sum = d0 + d1 + d2;
      else
      {
  		sum = d0 + d1 + d2 + s*(cycles) + x;      	
      	
      }

      if (sum%3==0)
      {
      	cout<<"YES"<<endl;
      }else
      	cout<<"NO"<<endl;

	}
	return 0;
}