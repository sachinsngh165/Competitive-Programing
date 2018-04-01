#include<iostream>
#include<vector>
#include <algorithm>

#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main()
{
	ll n;
	cin>>n;
	vector<ll>fib(n+1);

	fib[1]=1;
	fib[2]=2;

	for(int i=3;i<=n;i++)
	{
		fib[i]=fib[i-2]+fib[i-1];
	}

	for(int i=1;i<=n;i++)
	{
		if(find(fib.begin(),fib.end(),i)!=fib.end())
			cout<<'O';
		else
			cout<<'o';
	}

	cout<<endl;


}