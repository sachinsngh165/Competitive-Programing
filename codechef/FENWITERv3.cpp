#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
bitset<10000000UL> bin ;
bitset<10000000UL> bin2;
void add_one_bit(ull size)
{

	
	bool s,c=0,a,b=1;


	for (ull i = 0; i <size; ++i)
	{
		a = bin[i];
		s = a^b^c;
		bin[i] = s;
		c = (a&b)|(b&c)|(a&c);
		if (c==false && i!=0)
		{
			break;
		}
		b=0;
	}
//cout<<bin <<endl;

}


void sub_one_bit(ull size)
{

	
//subraction using 2's complement
	
	bool s,c=0,a,b=1;

	for (ull i = 0; i <size; ++i)
	{
		a = bin[i];
		s = a^b^c;
		bin[i]=s;
		c = (a&b)|(b&c)|(a&c);
		b=1;
	}
	//cout<<"sub   = " <<bin <<endl;
	
}


int main()
{

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
	
	for (ull i = 0; i < n; ++i)
			l+=l2;
	

	l+= l3;
		
	ull ct=0;

	
		ull count=0;
  
		//bin = *(new bitset<10000000UL>(l));
		//bin2 = *(new bitset<10000000UL>(l));
		
		ull size = l.size();

		std::vector<bool> bin;
		for (ull i = size-1; i>=0 ; --i)
		{
			temp bool = (l[i]-'0')
			bin.push_back(temp);
		}


		
		while(!bin.
		{
			// find F(L)

			bin2  = bin;
			add_one_bit(size);
			
			for (ull i = 0; i < size; ++i)
			{
				bin[i]= bin2[i]&bin[i];
			}



			ct++;
			if (bin.none())
			{
				break;
			}

			sub_one_bit(size);
					
		}

	cout<<ct <<endl;
}
	
return 0;
}