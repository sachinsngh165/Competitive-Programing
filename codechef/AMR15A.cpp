#include<iostream>
#define endl '\n'
#define long long ll
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int even=0,odd=0,temp;
	for(int cases=0;cases<t;cases++)
	{

     cin>>temp;
     if (temp%2==0)
     {
     	even++;
     }else odd++;

	}

	if (even>odd)
	{
		cout<<"READY FOR BATTLE\n";
	}else cout<<"NOT READY\n";
	return 0;
}