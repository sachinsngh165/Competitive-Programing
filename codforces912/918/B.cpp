#include<iostream>
#include<vector>
#include <algorithm>
#include<unordered_map>

#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main()
{
	ll n,m;
	cin>>n >>m;

	unordered_map<string,string> mp;

	string name,ip;
	
	for(int i=0;i<n;i++)
	{
		cin>>name >>ip;
		mp[ip]=name;
	}

	string ans;
	for(int i=0;i<m;i++)
	{
		ans = "";
		cin>>name >>ip;
		string temp = ip.substr(0,ip.length()-1);
		ans = name + " "+ip +" " + "#" + mp[temp];
		cout<<ans<<endl;
	}



}