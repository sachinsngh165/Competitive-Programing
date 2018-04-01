#include<iostream>
#include <vector>
#include<stack>
#include <algorithm>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;


// ull maxSum(vector<vector<ll> > a,ll n,ull last)
// {
	
// 	ll j=n-1,i=n-2;
// 	ull sum = last;

// 	while(j>=0)
// 	{
// 		if (i<0)
// 			return sum;

// 		if (a[i][j]<=last)
// 			{
// 				sum +=a[i][j];
// 				last = a[i][j];

// 				i--;
// 				j=n;
// 			}

// 			j--;
// 	}
	
// 	return -1;
// }

// 3
// 3
// 1 2 3
// 4 5 6
// 7 8 9
// 3
// 1 2 3
// 2 3 4
// 1 2 3
// 3 
// 1 2 3
// 0 1 2
// -1 0 1

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{

	  ll n;
      cin>>n;
      vector< vector<ll> > a(n,vector<ll>(n));

      for (int i = 0; i < n; ++i)
      {
      	for (int j = 0; j < n; ++j)
      		cin>>a[i][j];

      	
      	sort(a[i].begin(),a[i].end());
      }



      
	  
	  ll maxSum = INT_MIN;
	  bool gflag = false;

	  for(ll k=n-1;k>=0;k--)
	  {

	  	ll last = a[n-1][k];

      	ll j=k,i=n-2;
	  	ll sum = last;
	  	bool flag = false;

	  	while(j>=0)
		{
			if(i<0)
			{
				flag = true;
				break;
			}

			if (a[i][j]<=last)
				{
					sum +=a[i][j];
					last = a[i][j];
					// cout<<last <<endl;
					i--;
					j=n;
				}
			j--;
		}
		if (flag)
		{
			maxSum = max(maxSum,sum);
			gflag = true;
		}
	  }

	
	
	if (gflag==false)
	{
		cout<<-1 <<endl;
	}else
		cout<<maxSum <<endl;
      


	}
	return 0;
}