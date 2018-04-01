#include <iostream>
using namespace std;


int fact(int n);

int main()
{

	int t;
	cin >>t;
	for(int i=0;i<t;i++)
	{
		float ve,vy,l,Time,t,t_walk,rem_t;
		cin>> ve >>vy >>l >> Time;

		t = l/ve;

		t_walk = l/(ve + vy);

		rem_t = t - t_walk;

		float prob = rem_t/Time;

		if(prob > 1.00)
			prob = 1.00;

		cout << prob <<endl;
	}


	return 0;
}