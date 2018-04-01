#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll unit=1;



int main()
{
  int t;
  cin>>t;
  for (ll cases = 0; cases < t; ++cases)
  {
  	ll k;
  	cin>>k;
  	ll mid = (k+1)/2;
  	ll num;

  	
  	for (int i = 1; i <=k; ++i)
  	{
  		if (i<=mid)
  		{
  			num = mid-i+1;
  		}else
  			num = k-(i-mid-1);
  		

  		for (int j = 1; j <=k; ++j)
  		{

  			cout<<num <<" ";
  			if (j!=k)
  			{
  				if (num==1)
		  		{
  				num=k;
  				}else num--;
  			}

  		}
  			
  		cout<<endl;
  		
  	}
  	
  }
/*
  place of 1 column_wise = mid,mid-1,mid-2,mid-3,mid+3,mid+2,mid+1

  first cell (1,1) = mid-1+1
  			 (2,1) = mid-2+1
  			 (3,1) = mid-3+1
  			 (4,1) = mid-4+1
  			 (5,1) = k-1 +1
  			 (6,1) = k-2 +1
  			 (7,1) = k-3 +1

  - - - 1 - - - 
  - - 1 - - - - 
  - 1 - - - - - 
  1 - - - - - - 
  - - - - 1 - - 
  - - - - - 1 - 
  - - - - - - 1 


  - - - 1 - - - 
  - - 1 - - - - 
  - 1 - - - - - 
  1 - - - - - - 
  - - - - - - 1 
  - - - - - 1 - 
  - - - - 1 - -

  4 - - 1 - - - 
  3 - 1 - - - - 
  2 1 - - - - - 
  1 - - - - - - 
  - - - - - - 1 
  - - - - - 1 - 
  - - - - 1 - -
*/
  	
  return 0;
}