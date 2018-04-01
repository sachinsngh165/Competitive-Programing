#include<iostream>
#include<vector>
#define endl '\n'
#define long long ll
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{


	string v;
	cin>>v;
	
	int count1=0,count0=0;

	for(int i=0;i<v.size();i++)
	{
		if(v[i]=='0')	
			count1++;
		else count0++;
	}	

	if(count1==1 || count0==1)
		cout<<"Yes" <<endl;
	else cout<<"No" <<endl;

	}
	return 0;
}
