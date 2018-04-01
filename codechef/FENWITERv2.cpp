#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ull;
bitset<102001UL> bin ;
bitset<102001UL> bin2;

void add_one_bit(ull *ssize)
{

	bool s,c=0,a,b=1;

	ull size = *ssize;
	for (ull i = 0; i <size; ++i)
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

//if there is any carry put 1 to next MSB
	if (c!=false)
	{
		bin[size]=1;
		(*ssize)++;
	}
//cout<<bin <<endl;

}


void sub_one_bit(ull size)
{
	
	
//subraction using 2's complement

	for (ull i = 0; i <size; ++i)
	{
		if (bin[i]==1)
		{
			bin[i]=0;
			break;
		}else bin[i]=1;
	}
	//cout<<bin <<endl;
	
}



/*
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
	
}*/


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
	
	for (ull i = 0; i < n; ++i)
			l+=l2;
	

	l+= l3;
		
	ull ct=0;

	
		ull count=0;
  
		bin = *(new bitset<102001UL>(l));
		bin2 = *(new bitset<102001UL>(l));
		
		ull size = l.size();

		while(!bin.none())
		{

			if (bin.count()==size)	
			{		
				ct++;
				break;
			}

			// find F(L)

			bin2  = bin;
			add_one_bit(&size);
			
			for (ull i = 0; i < size; ++i)
			{
				bin[i]= bin2[i]&bin[i];
			}

			//bin = bin2&bin; 

			ct++;

			if (bin.none())
			{
				break;;
			}
			sub_one_bit(size);

			if (bin[size-1]==0)
			{
				--size;
			}
					
		}

	cout<<ct <<endl;
}
	
return 0;
}