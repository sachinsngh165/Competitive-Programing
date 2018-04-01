#include<iostream>
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

      int n,m;
      cin>>n >>m;

	if(n==1 && m==1)
		cout<<"No" <<endl;

	else if((n==1 && m%2!=0)|| (m==1 && n%2!=0))
		cout<<"No" <<endl;
	else cout<<"Yes" <<endl;

		


	}
	return 0;
}
