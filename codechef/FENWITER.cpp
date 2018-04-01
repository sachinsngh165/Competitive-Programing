#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string add_one_bit(string bin_num)
{
	string bin  = bin_num;
	ll bits = bin.size();
	short s,c=0,a,b=1;

	for (ll i = bits-1; i >=0; --i)
	{
		a = bin[i]-'0';
		s = a^b^c;
		bin[i] = (char)(s +'0');
		c = (a&b)|(b&c)|(a&c);
		b=0;
	}
cout<<"add    =" <<bin <<endl;
	return bin;

	
}

void sub_one_bit(string &bin)
{

	
//subraction using 2's complement
	ll bits = bin.size();
	short s,c=0,a,b=1;

	for (ll i = bits-1; i >=0; --i)
	{
		a = bin[i]-'0';
		s = a^b^c;
		bin[i] = (char)(s +'0');
		c = (a&b)|(b&c)|(a&c);
		b=1;
	}
	cout<<"sub   = " <<bin <<endl;
	
}

string F(string bin)
{
	int size = bin.size();
	char result[size];
	cout<<"size =" <<bin.size() <<endl;
	string bin2 = add_one_bit(bin); //i+1
	
	int c,a,b;

	for (int i = size-1; i>=0; --i)
	{
		a = bin[i]-'0';
		b = bin2[i]-'0';
		c = (a&b);
		result[i] = (char)(c+'0');
	}
cout<<"start = " <<result <<endl;
return string(result);
}


bool isZero(string bin)
{
	//cout<<"I'm here\n";

	for (ll i = 0; i < bin.size(); ++i)
	{
		if (bin[i]=='1')
		{
			return false;
		}
	}
return true;

}

int main()
{

int t;
cin>>t;
for (int cases = 0; cases < t; ++cases)
{
	
	string l1,l2,l3;
	ll n;
	cin>>l1;
	cin.ignore();
	cin>>l2;
	cin.ignore();
	cin>>l3 >>n;
	string l = l1;
	
	for (ll i = 0; i < n; ++i)
		l+=l2;
	

	l+= l3;
	//cout<<l <<endl;

	ll count=8;
		//while binary number >0
	while(count)
	{
		l=F(l);
		sub_one_bit(l);
		//cout<<l <<endl;
		count--;
	}
cout<<count <<endl <<endl;

}



return 0;
}