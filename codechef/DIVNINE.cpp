#include<iostream>
#include<string.h>
#define endl '\n'
#define ll unsigned long int
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
	    char num[1000000];
		cin>>num;
		int len=strlen(num),sum=0;
		for (ll j = 0; j < len; ++j)
			sum+=(int)(num[j]-48);
	
		int S = sum%9;
        	    if(S==0)
             		cout<<0 <<endl;

          else if(sum>9 || len==1)
          {
          	cout<<(((9-S)<S)?(9-S):S) <<endl;

          }
          else
          	{
          		  cout<<(9-S) <<endl;
          	}
   } 

	return 0;
}
