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
void execute(int* lazy,int l,int r,int lsize);
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


	    int size = sizeoftree(n);
	    int* lazy= new int[size];


	    for (int i = 0; i < size; ++i)
	    	lazy[i] =0;

	    
	    execute(lazy,0,m-1,n);


	    for (int i = 0; i < size; ++i)
	       {
	       	cout<<i <<' ';
	       }
	       cout<<endl;

	    for (int i = 0; i < size; ++i)
	       {
	       	cout<<lazy[i] <<' ';
	       }   

		// for (int i = 0; i < n; ++i)
		// 	cout<<arr[i] <<' ';	

		cout<<endl;
	}

	return 0;
}


int sizeoftree(int n)
{    
    int height = ceil(log2(n));
    return (pow(2,height)*2-1);
}

void updateLazy(int* lazy,int l,int r,int low,int high,int pos)
{
	if (low>high || high<0)
	{
		return;
	}

	// No overlap
	if(l>high || r<low)
		return;

	//complete overlap
	if ((low<=l && high<=r))
	{
			lazy[pos]+=1;
			return;	
	}


		
		if (low!=high && lazy[pos]!=0)
		{
			
			lazy[2*pos+1] = lazy[pos];
			lazy[2*pos+2] = lazy[pos];
			lazy[pos] = 0;
		}

		int mid = (low+high)/2;
		
		updateLazy(lazy,l,r,low,mid,2*pos+1);
		updateLazy(lazy,l,r,mid+1,high,2*pos+2);
		
		
	
}



void updateArray(int l,int r)
{
	for (int i = l; i <=r; ++i)
	{
		arr[i]++;
	}
}



void execute(int* lazy,int l,int r,int lsize)
{
	for (int i = l; i <=r; ++i)
	    {
	    	if (qs[i].type == 1)
	    	{
	    		updateLazy(lazy,qs[i].l-1,qs[i].r-1,0,lsize-1,0);
	    	}else
	    	{
	    			execute(lazy,qs[i].l-1,qs[i].r-1,lsize);
	    	}
	    }
}


