#include<iostream>
#include <math.h>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int num_of_bits(ull num)
{
	float lg = log2(num);

	int bits = ceil(lg);

	ull pnum = pow(2,bits);
	if (pnum==num)
	{
		bits++;
	}


	return bits;
}

int num_set_bits(ull n, ull b)
{
	if (b >= n)
	{
		return n;
	}

	return b;
}


int main()
{
	ios::sync_with_stdio(false);
	
	ull a,b;
	cin>>a >>b;

	
	ull n= num_of_bits(a);
	ull k = num_set_bits(n,b);

	//cout<<n <<' '<<k <<endl;
	ull p =2 ;
	ull num;
	
	if(b==1) 
		num = a;
	else
	{
		num = pow(p,n);
		num -=1;
	}

	

	

	
	cout<<num <<endl;



	return 0;
}