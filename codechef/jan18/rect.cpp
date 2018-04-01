#include<iostream>
#define endl '\n'
typedef long long ll;
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{

      int a[4];
      for (int i = 0; i < 4; ++i)
      {
      	cin>>a[i];
      }

      int count = 0;

      for (int i = 0; i < 4; ++i)
      {
      	int num = a[i];

      	for (int j = 0; j < 4; ++j)
      	{
      		if (num==a[j] && i!=j)
      		{
      			count++;
      			break;
      		}
      	}
      }

      if (count>=4)
      {
      	cout<<"YES"<<endl;
      }else
      	cout<<"NO" <<endl;

	}
	return 0;
}