#include <iostream>
using namespace std;


int fact(int n);

int main()
{

	int t;
	for(int i=0;i<t;i++)
	{
		int n,m;
		cin>> n >>m;

		int comb = fact(n+m);
		float prob = (float)m/comb;
		cout<<prob <<endl;


	}


	return 0;
}

int fact(int n)
{
	if(n==0 || n==1)
		return 1;

	else 
		return n*fact(n-1);
}