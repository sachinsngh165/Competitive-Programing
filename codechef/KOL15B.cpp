#include<iostream>
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
ll matrix[4][4]={
	{1,2,3,4},{5,6,-7,8},{-9,-10,-11,-12},{13,14,-15,16}
};

ll KandaneEast(ll r,ll c,ll n)
{
	if (c==n)
	{
		return matrix[r][c];
		
	}
	
	if (booldpEast[r][c])
		{
			return dpEast[r][c];
		}
	else if(booldpEast[r][c+1])
	{
		
		dpEast[r][c] = min(matrix[r][c],matrix[r][c]+dpEast[r][c+1]);
		return dpEast[r][c];
		
	}else
	{
		 dpEast[r][c+1]=KandaneEast(r,c+1,n);
		 dpEast[r][c] = min(matrix[r][c],matrix[r][c]+dpEast[r][c+1]);
		return dpEast[r][c];
	}

	
}

ll KandaneWest(ll r,ll c,ll n)
{
	if (c==0)
	{
		return matrix[r][c];
		
	}
	
	if (booldpWest[r][c])
		{
			return dpWest[r][c];
		}
	else if(booldpWest[r][c-1])
	{
		
		dpWest[r][c] = min(matrix[r][c],matrix[r][c]+dpWest[r][c-1]);
		return dpWest[r][c];
		
	}else
	{
		 dpWest[r][c-1]=KandaneEast(r,c-1,n);
		 dpWest[r][c] = min(matrix[r][c],matrix[r][c]+dpWest[r][c-1]);
		return dpWest[r][c];
	}

	
}

ll KandaneNorth(ll r,ll c,ll n)
{
	if (r==0)
	{
		return matrix[r][c];
		
	}
	
	if (booldpEast[r][c])
		{
			return dpEast[r][c];
		}
	else if(booldpEast[r-1][c])
	{
		
		dpEast[r][c] = min(matrix[r][c],matrix[r][c]+dpEast[r-1][c]);
		return dpEast[r][c];
		
	}else
	{
		 dpEast[r-1][c]=KandaneEast(r-1,c,n);
		 dpEast[r][c] = min(matrix[r][c],matrix[r][c]+dpEast[r-1][c]);
		return dpEast[r][c];
	}

	
}

ll KandaneSouth(ll r,ll c,ll n)
{
	if (r==n)
	{
		return matrix[r][c];
		
	}
	
	if (booldpSouth[r][c])
		{
			return dpSouth[r][c];
		}
	else if(booldpSouth[r+1][c])
	{
		
		dpSouth[r][c] = min(matrix[r][c],matrix[r][c]+dpSouth[r+1][c]);
		return dpSouth[r][c];
		
	}else
	{
		 dpSouth[r+1][c]=KandaneSouth(r+1,c,n);
		 dpSouth[r][c] = min(matrix[r][c],matrix[r][c]+dpSouth[r+1][c]);
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
	Min_Sum_Subarray(0,0,'E',3,3);
	Min_Sum_Subarray(0,3,'W',3,3);
	Min_Sum_Subarray(0,0,'S',3,3);
	Min_Sum_Subarray(3,0,'N',3,3);
	for (int i = 0; i < 4; ++i)
		{
			for(int j=0;j<4;++j)
			{
				cout<<dpSouth[i][j] <<"		";
			}
			cout<<endl;
		}	
	
	return 0;
}