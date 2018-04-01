#include<iostream>
#include<set>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll grid[10001][10001];
bool visited[10001][10001];
bool calcuated[10001][10001];
ll tm[10001][10001];


ll calculateTime(int i,int j,int n,int m)
{

	if (i>=n || i<0 || j>=m || j<0 || grid[i][j]==-1)
	{
		return 100;
	}

	if (visited[i][j])
	{
		return 100;
	}

	visited[i][j]=true;


	if (grid[i][j]>0)
	{
		return -grid[i][j];
	}else
	{
		ll right = calculateTime(i,j+1,n,m);
		ll left = calculateTime(i,j-1,n,m);
		ll up = calculateTime(i-1,j,n,m);
		ll down = calculateTime(i+1,j,n,m);
		tm[i][j] = min(right,
						min(left,
						min(up,down)))+1;

		visited[i][j]=false;
		return tm[i][j];
	}
}


int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{

     ll n,m;
     cin>>n >>m;
     for (int i = 0; i < n; ++i)
     {
     	for (int j = 0; j < m; ++j)
     	{
     		cin>>grid[i][j];
     	}
     }

      for (int i = 0; i < n; ++i)
     {
     	for (int j = 0; j < m; ++j)
     	{
     		cout<<grid[i][j] <<" ";
     	}
     	cout<<endl;
     }

	for (int i = 0; i < n; ++i)
     {
     	for (int j = 0; j < m; ++j)
     	{
     		visited[i][j]=false;
     		calcuated[i][j]=false;
     	}
     } 

	for (int i = 0; i < n; ++i)
     {
     	for (int j = 0; j < m; ++j)
     	{
     		if (!calcuated[i][j])
     		{
     			tm[i][j]= calculateTime(i,j,n,m);
     		}
     		calcuated[i][j] = true;
     	}
     }

     for (int i = 0; i < n; ++i)
     {
     	for (int j = 0; j < m; ++j)
     	{
     		cout<<tm[i][j] <<" ";
     	}
     	cout<<endl;
     }


     for (int i = 0; i < n; ++i)
     {
     	for (int j = 0; j < m; ++j)
     	{
     		if (grid[i][j]==-1)
     		{
     			cout<<"B";
     		}
     		else if (tm[i][j]<=0)
     		{
     			cout<<"Y";
     		}else
     			cout<<"N";
     	}
     	cout<<endl;
     }         

	}
	return 0;
}