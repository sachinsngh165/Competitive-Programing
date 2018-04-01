#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
	
	int t;
	cin>>t;

	
	
	for(int c=0;c<t;c++)
	{
	    string n;
	    cin>>n;

	    string ans = "";

	    ll len = n.length();
	    list<int> l[11];

	    for (int i = 0; i < len; ++i)
	    {
	    		int temp = n[i] - '0';
	    		l[temp].push_back(i);
	    }

	    bool alpha[26] = { false };

	    list <int>::iterator it;
	    for (int i = 6; i <=9; ++i)
	    {
	    	

	    	if (l[i].begin()!=l[i].end())
	    	{
	    		int num = *(l[i].begin());

	    		for (int j = 0; j <=9; ++j)
	    		{
	    			for(it=l[j].begin();it!=l[j].end();it++)
	    			{
	    				if (num!=*it)
	    				{
	    					int temp = i*10+j;
	    					if (temp>=65 && temp<=90)
	    					{
	    						alpha[temp -65] = true;;
	    					}
	    				}
	    			}
	    		}
	    	}
	    }

	    for (int i = 0; i < 26; ++i)
	    {
	    	if (alpha[i])
	    	{
	    		char temp =  'A' + i;
	    		ans +=temp;
	    	}
	    }
	    
	    cout<<ans <<endl;
	    
	}
	
	
	return 0;
}