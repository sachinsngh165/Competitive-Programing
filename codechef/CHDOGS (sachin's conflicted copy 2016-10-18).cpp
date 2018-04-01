#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
		{
			double s,v;
			cin>>s >>v;
			
			double distance = (s*2*sqrt(3))/4;
			cout<<"distance= " <<distance <<endl;
			double time = (distance)/v;
			
			cout<<time <<endl;
		
		
		}

return 0;
}
