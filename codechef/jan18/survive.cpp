#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,k,s;
		cin>>n >>k >>s;

		int s2 = s - (s/7) ;


		float total = k*s;
		int numPurchases= ceil(total/n);

		if (numPurchases <= s2)
		{
			cout<<numPurchases <<endl;
		}else
			cout<<-1 <<endl;

	}
}