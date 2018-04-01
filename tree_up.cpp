#include <iostream>
using namespace std;


void add(int* p,int x,int y);
void add_up(int* p ,int x,int y);

int main()
{

	int t;
	cin >>t;
	for(int i=0;i<t;i++)
	{
		int n,m,q;
		cin>> n >>m >>q;

		int p[n];

		for (int j = 0; j < n; ++j)
		{
			cin>>p[i];
		}

		for (int j = 0; j < m; ++j)
		{
			string op;
			int x,y;
			cin >>string >>x >>y;

			if (op == "ADD")
			{
				add(p,x,y);
			}else if (op == "ADDUP")
			{
				add(p,x,y);
			}
		}

		


	}


	return 0;
}

void add(int* p ,int x,int y)
{
	p[x] += y;

}

void add_up(int* p ,int x,int y)
{
	if(x ==0)
		{ 
			p[x] += y;
			return;
		}

	p[x] + = y;
	add_up(int* p,int p[x],y);
}