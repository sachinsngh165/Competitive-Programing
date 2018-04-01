#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct cmd	
{
	int type;
	int l;
	int r;
};

cmd qs[100001];
ll arr[100001];

void updateLazy(int* lazy,int l,int r,int low,int high,int pos);
void execute(int l,int r);
int sizeoftree(int n);
void updateArray(int l,int r);



int main() {
	
	int t;
	cin>>t;
	
	for(int c=0;c<t;c++)
	{
	    int n,m;
	    cin>>n >>m;

		for (int i = 0; i < n; ++i)
			arr[i] =0 ;
			

	    for (int i = 0; i < m; ++i)
	    	cin>>qs[i].type >>qs[i].l >>qs[i].r;
	    
	    execute(0,m-1);   

		for (int i = 0; i < n; ++i)
			cout<<arr[i] <<' ';	

		cout<<endl;
	}


	return 0;
}


void updateArray(int l,int r)
{
	for (int i = l; i <=r; ++i)
	{
		arr[i]++;
	}
}



void execute(int l,int r)
{
	for (int i = l; i <=r; ++i)
	    {
	    	if (qs[i].type == 1)
	    	{
	    		updateArray(qs[i].l-1,qs[i].r-1);
	    	}else
	    	{
	    			execute(qs[i].l-1,qs[i].r-1);
	    	}
	    }
}


