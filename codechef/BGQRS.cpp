#include <bits/stdc++.h>
//#define endl '\n'
typedef long long ll;
using namespace std;





struct node
{
	ll p;
	ll q;};

node sum(node n1,node n2)
{


	node temp;
	temp.p = n1.p+n2.p;
	temp.q = n1.q+n2.q;

	return temp;
}
void print(node* tree,ll size)
{
for (int i = 0; i < size;)
      	{
      		for (int j = 1; j <=pow(2,i) && i<size; ++j)
      		{
      			cout<<"(" <<tree[i].p <<"," <<tree[i].q <<")" <<"	";
      			i++;
      		}
      		cout<<endl <<endl;
      	}
}


ll evaluateTrailZeroes(ll p,ll q)
{
	if (p==q)	
	{
			return p;
	}else{

		return min(p,q);
	}
}

void findMultiplesOfTwoAndFive(ll num,ll* a,ll* b)
{
	*a=*b=0;
	while(num%2==0 || num%5==0)
	{
		if (num%2==0)
		{
			(*a)++;
			num/=2;
		}
		if (num%5==0)
		{
			(*b)++;
			num/=5;
		}
	}}

void constructSegTree(node* tree,ll pos,ll* arr,ll low,ll high)
{
	if (low==high)
	{
		ll a,b;
		findMultiplesOfTwoAndFive(arr[low],&a,&b);
		//cout<<"pos= " <<pos <<"		a= " <<a <<"	b= " <<b;
		tree[pos].p =a;
		tree[pos].q =b;
		return;
	}
	ll mid = (high+low)/2;
	constructSegTree(tree,2*pos+1,arr,low,mid);
	constructSegTree(tree,2*pos+2,arr,mid+1,high);

	ll a,b;
	a = tree[2*pos+1].p + tree[2*pos+2].p;
	b = tree[2*pos+1].q + tree[2*pos+2].q;

	tree[pos].p =a;
	tree[pos].q =b;}


void updateX(node* tree,ll pos,ll low,ll high,ll qlow,ll qhigh,ll a,ll b){
	

	if (a==0 && b==0)
	{
		return;
	}

	//no overlap overlap
	if (high < qlow || low > qhigh)
	{
		return;
	}


	if (low==high)
	{
		
		tree[pos].p+=a;
		tree[pos].q+=b;
		return;
	}

	ll mid = (low+high)/2;
	updateX(tree, 2*pos+1,low,mid, qlow,qhigh, a, b);
	updateX(tree, 2*pos+2,mid+1,high, qlow,qhigh, a, b);

	ll a1,b1;
	a1 = tree[2*pos+1].p + tree[2*pos+2].p;
	b1 = tree[2*pos+1].q + tree[2*pos+2].q;

	tree[pos].p =a1;
	tree[pos].q =b1;
}

void updateY(node* tree,ll pos,ll low,ll high,ll qlow,ll qhigh,ll a,ll b){
	

	//no overlap overlap
	if (high < qlow || low > qhigh)
	{
		return;
	}


	if (low==high)
	{
		ll val1,val2;
		//cout<<low <<"-" <<qlow <<"+1" <<" =" <<low-qlow+1<<endl;  
		findMultiplesOfTwoAndFive((low-qlow+1),&val1,&val2);
		a+=val1;
		b+=val2;
		tree[pos].p=a;
		tree[pos].q=b;
		return;
	}

	ll mid = (low+high)/2;
	updateY(tree, 2*pos+1,low,mid, qlow,qhigh, a, b);
	updateY(tree, 2*pos+2,mid+1,high, qlow,qhigh, a, b);

	ll a1,b1;
	a1 = tree[2*pos+1].p + tree[2*pos+2].p;
	b1 = tree[2*pos+1].q + tree[2*pos+2].q;

	tree[pos].p =a1;
	tree[pos].q =b1;
}

node SegTreeQuery(node* tree,ll pos,ll low,ll high,ll qlow,ll qhigh)
{

//no overlap
	if (high < qlow || low >qhigh)
	{
		node null;
		null.p=null.q=0;
		return null;
	}

//complete overlap
	if (qlow<=low && high <=qhigh)
	{
		return tree[pos];
	}

	ll mid = (low+high)/2;
	node left = SegTreeQuery(tree,2*pos+1,low,mid,qlow,qhigh);
	node right = SegTreeQuery(tree,2*pos+2,mid+1,high,qlow,qhigh);
	node result=sum(left,right);
	return result;

}


ll SegTreeSize(ll n)
{
	ll height = ceil(log2(n));
	return (2*pow(2,height)-1);
}


int main()
{
	ios::sync_with_stdio(false);
	ll t;
	cin>>t;
	for(ll cases=0;cases<t;cases++)
	{
		ll result=0;
      ll n,m;
      cin>>n >>m;
      ll a[n];
      for (ll i = 0; i < n; ++i)
      {
      	cin>>a[i];
      }

      ll size = SegTreeSize(n);
      node tree[size];
      
      //cout<<size <<endl;

      constructSegTree(tree,0,a,0,n-1);
     

      

      for (ll query = 0; query < m; ++query)
      {
      	
      		ll type,l,r;
      		cin>>type;
      		if (type==1)
      		{	
      			ll x;
      			cin>>l >>r >>x;

      			
      			ll a,b;
				findMultiplesOfTwoAndFive(x,&a,&b);
				updateX(tree,0,0,n-1,l-1,r-1,a,b);
      			
      		
      		}else if (type==2)
      		{
      			ll y;
      			cin>>l >>r >>y;
      			ll a,b;
      			findMultiplesOfTwoAndFive(y,&a,&b);
      			updateY(tree,0,0,n-1,l-1,r-1,a,b);
      			
      		}else{

      			cin>>l >>r;
      			node temp_result = SegTreeQuery(tree,0,0,n-1,l-1,r-1);
      			result+= evaluateTrailZeroes(temp_result.p,temp_result.q);
      			//cout<<"	temp_result =" <<evaluateTrailZeroes(temp_result.p,temp_result.q) <<endl; 
      		}

      }

      cout<<result <<endl;


	}
	return 0;
}