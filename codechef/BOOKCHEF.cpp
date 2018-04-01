#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
string str[100001];
bool s[10000]={false};
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	
	cin>>n >>m;

	//input all special friend
	for(int cases=0;cases<n;cases++)
	{
		ll temp;
		cin>>temp;
		s[temp]=true;
	}

	ll f,p;
	
	priority_queue<int> special;
	priority_queue<int> other;

	for(ll i=0;i<m;i++)
	{
		cin>>f >>p;
		cin>>str[p];
		if (s[f])
		{
			special.push(p);
		}else other.push(p);


	}

	while (!special.empty())
  {
     cout<<str[special.top()] <<endl;
     special.pop();
  }

  	while (!other.empty())
  {
     cout<<str[other.top()] <<endl;
     other.pop();
  }
	return 0;
}