#include<iostream>
#define endl '\n'
#define long long ll
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	
	for(int cases=0;cases<t;cases++)
	{
		int sum=0;
      string str;
      cin>>str;
      for (int i = 0; i < str.size(); ++i)
      {
      	int ascii=(int)str[i];
      	if (str[i]>=48 && str[i]<=57)
      	{
      		sum+=(int)(str[i]-'0');
      	}
      }
      cout<<sum <<endl;

	}
	return 0;
}