#include <iostream>
#include<limits.h>
using namespace std;


bool minTurn(int n,int m,string* grid,int* min_turn,
            int count,int currX,int currY);

int main()
{
    int n,m;
    cin>>n >>m;

    string grid[n];

    
    for(int i=0;i<n;i++)
    {
         cin>>grid[i];
    }
    
    int min_turn = INT_MAX;
    bool status  = minTurn(n,m,grid,&min_turn,0,0,0);
    
    if(status)
        cout<<min_turn <<endl;
    else
        cout<<-1 <<endl;
    
    return 0;
}

bool minTurn(int n,int m,string* grid,int* min_turn,int count,int currX,int currY,char prevMove,char currMove)
{
    if(currX >= n || currY >= m)
        return false;
    
    if(grid[currX][currY]=='H')
    {
    	*min_turn = min(*min_turn,count);
        return true;
    }
    
    else if(grid[currX][currY]=='*')
        return false;
    
    
    return minTurn(n,m,grid,min_turn,count,currX,currY,prevMove,prevMove);
    
             
}
