#include <bits/stdc++.h>
using namespace std;

bool *prime= new bool[1000000001];
int *parr=new int[10000000];


int main()
{
	
	long long m,q;
	cin>>m >>q;

	

	for (int i = 0; i < m; ++i)
	{
		cin>>parr[i];
	}

	sort(parr,parr+m);

	

	
		memset(prime,false,1000000001);
		//fill_n(prime, 1000000001, false);


	for (int i = 0; i < q; ++i)
	{
		
		long long x,y;
		cin>>x >>y;

		long long count=0;
	
		for (long long j=0;j<m;j++)
            {
            
                for (long long k=parr[j]; k<=y; k+=parr[j])
                    {

                    	if (prime[k]==false)
                    	{
                    		prime[k]= true;
                    		count++;
                    	}
                    
                    }
                
            }

           cout<<count <<endl;





	}



	return 0;
}
