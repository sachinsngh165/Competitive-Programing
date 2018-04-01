#include<iostream>
#define endl '\n'
typedef long long ll;
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	
	ll a,b,x,y,z;
	cin>>a >>b;
	cin>>x >>y >>z;

	ll yc = x*2 +y;
	ll bc = y + 3*z;

	ll count = 0;

	ll yc_needed = yc-a;
	ll bc_needed = bc-b;
	if (yc_needed>0)
	{
		count+=yc_needed;
	}
	if (bc_needed>0)
	{
		count +=bc_needed;
	}

	cout<<count <<endl;


	return 0;
}