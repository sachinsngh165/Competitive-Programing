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

      int x1,y1,x2,y2;
      cin>>x1 >>y1 >>x2 >>y2;

      if (x1==x2)
      {
      	if (y1 <y2)
      	{
      		cout<<"up\n";
      	}else cout<<"down\n";
      }else if (y1==y2)
      {
      	if (x1 < x2)
      	{
      		cout<<"right\n";
      	}else cout<<"left\n";
      }else
      cout<<"sad\n";	
	}
	return 0;
}