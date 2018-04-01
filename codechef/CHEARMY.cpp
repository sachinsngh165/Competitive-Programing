#include<iostream>
#define endl '\n'
using namespace std;

int isMagical(int var)
{
    int num[size],i=0;
    while (var > 0) {
        num[i]=var%10;
        var/=10
        i++;
    }
    
    
    
	int odd=0;
 	       for(int i=0;i<size;i++ )
	       {
		for(int j=i;j<size;j++)
		{
            if(num[i]%2==0)
                return 1;

			  odd++;
		}
		
	       }
	     
	       if(odd%2==0)
		  return 1;
	else return 0;

}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	
	int k[100000];

	for(int cases=0;cases<t;cases++)
	{

		cin>>k[cases];
		int count=0,i=0;

		while(count<=k[cases])
		{
			if(isMagical(i))
				count++;

			if(count == k[cases])
                cout<<i <<endl;
            
            i++;
		}


	}
	return 0;
}
