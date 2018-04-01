#include<iostream>
#include<iomanip>
#include<vector>
#include <algorithm>

#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main()
{
	double n,m;
	cin>>n >>m;

	double a,b;
	double p;
	vector<float> priceKg;
	for(int i=0;i<n;i++)
	{
		cin>>a >>b;
		p = a/b;
		priceKg.push_back(p);
	}

	sort(priceKg.begin(),priceKg.end());

	double ans = (double)m*priceKg[0];

	cout<<setprecision(7);
	cout<<ans<<endl;

	return 0;
}