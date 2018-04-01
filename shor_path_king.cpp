#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{

	string s,t;
	cin>>s >>t;

	if (s == t)
	{
		cout<<0 <<endl;
		return 0;
	}

	char x = s[0],t_x = t[0];
	int y = s[1] -'0',t_y = t[1] - '0';

	vector<string> mv;
	ll count =0;

	while(x != t_x || y !=t_y)
	{
		// cout<<"x = " <<x <<" y= " <<y <<endl;
		if (x < t_x && y < t_y)
		{
			count++;
			mv.push_back("RU");
			x++;
			y++;
		}
		else if(x < t_x && y > t_y)
		{
			count++;
			mv.push_back("RD");
			x++;
			y--;
		}
		else if(x > t_x && y < t_y)
		{
			count++;
			mv.push_back("LU");
			x--;
			y++;
		}else if (x > t_x && y > t_y)
		{
			count++;
			mv.push_back("LD");
			x--;
			y--;
		}else if(x == t_x)
		{
			count++;
			if (y < t_y)
			{
				
				y++;
				mv.push_back("U");

			}else if (y > t_y)
			{
				y -- ;
				mv.push_back("D");
			}
		}else if (y == t_y)
		{
			count++;
			if (x < t_x)
			{
				
				x++;
				mv.push_back("R");

			}else if (x > t_x)
			{
				x -- ;
				mv.push_back("L");
			}
		}
	}


	cout<<count <<endl;
	for (int i = 0; i < mv.size(); ++i)
	{
		cout<<mv[i] <<endl;
	}



	return 0;
}