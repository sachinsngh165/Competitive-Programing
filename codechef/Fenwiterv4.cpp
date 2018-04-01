#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ull;

void add_one_bit(bitset<1000> &bin)
{

	bool s,c=0,a,b=1;
	for (ull i = 0; i <bin.size(); ++i)
	{
		a = bin[i];
		s = a^b^c;
		bin[i] = s;
		c = (a&b)|(b&c)|(a&c);

		if (c==false && i!=0)
		{
			return;
		}
		b=0;
	}


}



int main()
{

ios::sync_with_stdio(false);
ull t;
cin>>t;
for (ull cases = 0; cases < t; ++cases)
{

	string l1,l2,l3;
	ull n;
	cin>>l1;
	cin.ignore();
	cin>>l2;
	cin.ignore();
	cin>>l3 >>n;
	string l = l1;
	
	
		
	ull ct=0;
  
		bitset<1000> bin1(l1);
		bitset<1000> bin2(l2);
		bitset<1000> bin3(l3);
		
		//if all bits of 3rd string is 1
		if (bin3.count()==l3.size() && bin2.count()==l2.size() && bin1.count()==l1.size())
		{
			ct=1;
		}else if(bin3.count()==l3.size() && bin2.count()==l2.size())
		{
			add_one_bit(bin1);
			ct= bin1.count();
			

		}else if(bin3.count()==l3.size())
		{
			ct = bin1.count() + (n-1)*bin2.count();
			add_one_bit(bin2);
			ct+=bin2.count();
		}else
		{
			add_one_bit(bin3);
			ct = bin1.count()+n*bin2.count()+bin3.count();
		}
			
cout<<ct <<endl;
}
		
		
	
return 0;
}