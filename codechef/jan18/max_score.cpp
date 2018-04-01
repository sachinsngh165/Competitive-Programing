#include<iostream>
#include <vector>
#include<stack>
#include <algorithm>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector< vector<bool> > visited(701,vector<bool>(701));
vector< vector<ll> > mSum(701,vector<ll>(701));

ll maxSum(vector<vector<ll> > a,ll i,ll j,ll n,ll sum,ll last)
{

	if (i>=n)
		return sum;
	
	if (visited[i][j])
		return mSum[i][j];
	
	for(j=n-1;j>=0;j--)
	{
		if (visited[i][j])
		{
			if (mSum[i][j]>0)
			{
				return mSum[i][j];
			}
			
		}
		else if (a[i][j]>=last)
		{
			
				mSum[i][j] = maxSum(a,i-1,j,n,sum+a[i][j],a[i][j]);
			    visited[i][j] = true;
			    if (mSum[i][j] <0)
				   continue;
				else
					return mSum[i][j];
		
			

		}else if(a[i][j]<last)
		{
			return -1;	
		}

	}

	if (j<0)
		return -1;
	
	return mSum[n-1][n-1];
}


// ll maxSum(vector<vector<ll> > a,ll i,ll j,ll n,ll sum,ll last)
// {


// }



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
      	{
      		ll temp;
      		cin>>temp;
      		a[i][j] = temp;
      		visited[i][j] = false;
      		mSum[i][j] = -1;
      	}
      	sort(a[i].begin(),a[i].end());
      }


      ll mSum = maxSum(a,n-1,n-1,n,0,INT_MIN);
      cout<<mSum <<endl;


	}
	return 0;
}