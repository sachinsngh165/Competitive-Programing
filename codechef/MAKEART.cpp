#include<iostream>
#define endl '\n'
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{

      int n;
      cin>>n;
      int a[n];

      for (int i = 0; i < n; ++i)
      {
      	cin>>a[i];
      }

int flag=0;
      for (int j = 0; j < n; ++j)
      {
      	if((j+2)>=n)
      		break;

      	if((a[j]==a[j+1]) && (a[j+1]==a[j+2]))
      		{ cout<<"Yes" <<endl;
      	         flag=1;
                break;   
          }
      
      }
        if(flag==0)
        	cout<<"No" <<endl;
	}
	return 0;
}