#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define mod 1000000007



int main()
{
  int t;
  cin>>t;
  for (ll cases = 0; cases < t; ++cases)
  {
  	ll n;
  	cin>>n;
  	ll ct = 0;
  	for (ll i = 2; i <=n-1; ++i)
  	{
  		ll minm = min(i-1,n-i);
  		
  		ct=(ct%mod+(ll)pow(n-minm,minm)%mod)%mod;
  		//cout<<i <<"= " <<(ll)pow(n-minm,minm) <<endl;
  	}
  	cout<<ct <<endl;
  }
  return 0;
}