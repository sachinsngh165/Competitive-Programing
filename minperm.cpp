#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
	
	int t;
	cin>>t;
	
	for(int c=0;c<t;c++)
	{
	    int n;
	    cin>>n;
	    int i;
	    if ((n&1) == 0)
	    {
	    	for (i = 1; i <=n-1; i+=2)
	    	{
	    		cout<<i+1 <<' ' <<i <<' ';
	    	}
	    }else
	    {
	    	for (i = 1; i <=n-3; i+=2)
	    	{
	    		cout<<i+1 <<' ' <<i <<' ';
	    	}

	    	cout<<i+1 <<' ' <<i+2 <<' ' <<i;
	    }
	    cout<<endl;
	}
	
	
	return 0;
}