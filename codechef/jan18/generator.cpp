#include<iostream>
#include <cstdlib>
#include  <ctime>

using namespace std;
int main()
{
	int t = 10;
	cout<<t <<endl;
	for (int i = 0; i < t; ++i)
	{
		srand((int)i);
		int n  = (rand()%5) +1;
		cout<<n <<endl;
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				cout<<(rand()%10
					) +1<<" ";
			}
			cout<<endl;
		}
		
	}

	cout<<endl;
	return 0;
}


