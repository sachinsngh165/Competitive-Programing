#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
	
	int t;
	cin>>t;
	
	for(ll c=0;c<t;c++)
	{
	    int n;
	    cin>>n;
	    
	    ll arr[n];
	    ll minItem=INT_MAX,ind=0;
	    
	    for(ll i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        if (arr[i] < minItem)
	        {
	        	minItem = arr[i];
	        	ind = i;
	        }
	        
	    }
	    

	    cout<<ind+1 <<endl;

	}
	
	
	return 0;
}