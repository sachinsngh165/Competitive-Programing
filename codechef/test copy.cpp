#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void add_one_bit(bitset<10> &bin)
{

	bool s,c=0,a,b=1;
	ull size = bin.size();

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

	if (c!=false)
	{
		bin[size]=1;
		size++;
	}
cout<<bin <<endl;

}





int main()
{
	string l;
	cin>>l;
	bitset<10UL>bin(l);	
	add_one_bit(bin);
	cout<<bin <<endl;
	return 0;
}