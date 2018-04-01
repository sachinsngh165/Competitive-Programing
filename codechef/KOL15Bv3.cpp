#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

ll dpWest[1000][1000];
ll dpEast[1000][1000];
ll dpNorth[1000][1000];
ll dpSouth[1000][1000];

bool booldpWest[1000][1000];
bool booldpEast[1000][1000];
bool booldpNorth[1000][1000];
bool booldpSouth[1000][1000];
ll matrix[1000][1000];

ll KandaneEast(ll r,ll c,ll n)
{
	if (c==n)
	{
		booldpEast[r][c]=true;
		dpEast[r][c]=matrix[r][c];
		return dpEast[r][c];
	}
	
	if (booldpEast[r][c])
		{
			return dpEast[r][c];
		}
	else if(booldpEast[r][c+1])
	{
		
		dpEast[r][c] = min(matrix[r][c],matrix[r][c]+dpEast[r][c+1]);
		booldpEast[r][c]=true;
		return dpEast[r][c];
		
	}else
	{
		 dpEast[r][c+1]=KandaneEast(r,c+1,n);
		 dpEast[r][c] = min(matrix[r][c],matrix[r][c]+dpEast[r][c+1]);
		 booldpEast[r][c]=true;
		return dpEast[r][c];
	}

	
}

ll KandaneWest(ll r,ll c,ll n)
{
	if (c==0)
	{
		booldpWest[r][c]=true;
		dpWest[r][c] = matrix[r][c];
		return dpWest[r][c];
		
	}
	
	if (booldpWest[r][c])
		{
			return dpWest[r][c];
		}
	else if(booldpWest[r][c-1])
	{
		
		dpWest[r][c] = min(matrix[r][c],matrix[r][c]+dpWest[r][c-1]);
		booldpWest[r][c]=true;
		return dpWest[r][c];
		
	}else
	{
		 dpWest[r][c-1]=KandaneWest(r,c-1,n);
		 dpWest[r][c] = min(matrix[r][c],matrix[r][c]+dpWest[r][c-1]);
		 booldpWest[r][c]=true;
		return dpWest[r][c];
	}

	
}

ll KandaneNorth(ll r,ll c,ll n)
{
	if (r==0)
	{
		booldpNorth[r][c]=true;
		dpNorth[r][c]=matrix[r][c];
		return dpNorth[r][c];
	}
	
	if (booldpNorth[r][c])
		{
			return dpNorth[r][c];
		}
	else if(booldpNorth[r-1][c])
	{
		
		dpNorth[r][c] = min(matrix[r][c],matrix[r][c]+dpNorth[r-1][c]);
		booldpNorth[r][c]=true;
		return dpNorth[r][c];
		
	}else
	{
		 dpNorth[r-1][c]=KandaneNorth(r-1,c,n);
		 dpNorth[r][c] = min(matrix[r][c],matrix[r][c]+dpNorth[r-1][c]);
		 booldpNorth[r][c]=true;
		return dpNorth[r][c];
	}

	
}

ll KandaneSouth(ll r,ll c,ll n)
{
	if (r==n)
	{
		booldpSouth[r][c]=true;
		dpSouth[r][c]=matrix[r][c];
		return dpSouth[r][c];
	}
	
	if (booldpSouth[r][c])
		{
			return dpSouth[r][c];
		}
	else if(booldpSouth[r+1][c])
	{
		
		dpSouth[r][c] = min(matrix[r][c],matrix[r][c]+dpSouth[r+1][c]);
		booldpSouth[r][c]=true;
		return dpSouth[r][c];
		
	}else
	{
		 dpSouth[r+1][c]=KandaneSouth(r+1,c,n);
		 dpSouth[r][c] = min(matrix[r][c],matrix[r][c]+dpSouth[r+1][c]);
		 booldpSouth[r][c]=true;
		return dpSouth[r][c];
	}

	
}



ll Min_Sum_Subarray(ll i,ll j,char d,ll row,ll column)
{
	if (d=='E')
	{
		return KandaneEast(i,j,column);

	}else if(d=='W') return KandaneWest(i,j,column);
	else if(d=='S') return KandaneSouth(i,j,row);
	else return KandaneNorth(i,j,row);
}



int main()
{
	ll t;
	cin>>t;
	for(ll cases=0; cases<t;cases++)
	{
		ll N,M;
		cin>>N >>M;
		for (int i = 0; i < N; ++i)
		{
			for(int j=0;j<M;++j)
			{
				cin>>matrix[i][j];
			}
		}

		ll min_cost = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			for(int j=0;j<M;++j)
			{

				ll cost = Min_Sum_Subarray(i,j,'E',N-1,M-1)+Min_Sum_Subarray(i,j,'W',N-1,M-1)+Min_Sum_Subarray(i,j,'S',N-1,M-1)+
				Min_Sum_Subarray(i,j,'N',N-1,M-1) - 3*(matrix[i][j]);
				min_cost=min(min_cost,cost);
			}
		}

		/*for (int i = 0; i < N; ++i)
		{
			for(int j=0;j<M;++j)
			{
				cout<<dpSouth[i][j] <<"		";
			}
			cout<<endl;
		}*/
	cout<<min_cost <<endl;
			
	}
	
	
	return 0;
}