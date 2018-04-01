#include<iostream>
#define endl '\n'
typedef long long ll;
using namespace std;


int f(string a,string b,int n,int m,char last)
{

	if (n==0 && m==0)
	{
		return 0;
	}

	else if (n==0 && m!=0)
	{
		if (b[m-1]==last)
		{
			return f(a,b,n,m-1,b[m-1]);
		}else
			return 1+f(a,b,n,m-1,b[m-1]);

	}else if(n!=0 && m==0)
	{
		if (a[n-1]==last)
		{
			return f(a,b,n-1,m,a[n-1]);
		}else
			return 1+f(a,b,n-1,m,a[n-1]);
	}

	if (a[n-1]==last)
	{
		return f(a,b,n-1,m,a[n-1]);
	}else if(b[m-1]==last)
		return f(a,b,n,m-1,b[m-1]);
	else
		return 1 + min(f(a,b,n-1,m,a[n-1]),f(a,b,n,m-1,b[m-1]));

}


int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{

      int n,m;
      cin>>n >>m;
      string a,b;
      cin>>a >>b;

      cout<<f(a,b,a.length(),b.length(),'_') <<endl;

      

	}
	return 0;
}