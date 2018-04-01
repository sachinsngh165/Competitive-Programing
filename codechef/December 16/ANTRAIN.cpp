#include <iostream>
using namespace std;

string printBerth(int num)
{
	string str
	if (num==3 || num==6)
	{
		str = "UB";
	}else if (num==2 || num==5)
	{
		str = "MB";
	}else if (num==1 || num==4)
	{
		str = "LB";
	}else if (str==7)
	{
		str = "SU";
	}else str = "SL";

	return str;
}
bool TrainPartner(int num)
{
	if (num<=3)
		{
			cout<<num+3 <<printBerth(num);
			return TRUE;
		}else if (num<7)
		{
			cout<<num-3 <<printBerth(num);
			return TRUE;
		}else if (num%8==0)
		{
			cout<<num-1 <<printBerth(num);
			return TRUE;
		}else if((num+1)%8==0)
			{cout<<num+1 <<printBerth(num);
			return TRUE;
			}
	return FALSE;
}
int main()
{
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		int num;
		cin>>num;

		
	}
}