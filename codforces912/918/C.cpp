#include<iostream>
#include<vector>
#include <algorithm>
#include<unordered_map>
#include <stack>

#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

bool isPretty(string str)
{
	stack<char> st;
	int len = str.length();
	int count=0;

	for(int i=0;i<len;i++)
	{
		if(str[i]=='(')
			st.push(str[i]);
		else if(str[i]==')')
		{
			if (st.empty())
			{
				if (count<=0)
				{
					return false;
				}else
					count++;
			}else
			{
				st.pop();
			}
		}else
			count++;
	}

	if (st.size()==count)
	{
		return true;
	}else if(st.size()==0)
		{
			if (count%2==0)
			{
				return true;
			}else
				return false;
		}
	else
		return false;

}


int main()
{
	string msg;
	cin>>msg;

	int len = msg.length();
	ll count = 0;

	for(int L=2;L<=len;L++)
	{
		for (int j = 0; j <=len-L; ++j)
		{
			string str = msg.substr(j,L);
			// cout<<j <<endl;
			if (isPretty(str))
			{
				cout<<"Right: "<<str<<endl;
				count++;
			}else
			{
				cout<<"Wrong: "<<str <<endl;
			}
		}
	}

	cout<<count <<endl;


}