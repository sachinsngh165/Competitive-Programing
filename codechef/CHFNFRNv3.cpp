#include<iostream>
#include<vector>
#include<list>
#include<set>
#define endl '\n'
#define long long ll
using namespace std;

class Graph
{
	int V;
	vector<list<int> > *adj;

public:
	Graph(int n)
	{
		this->V=n;
		adj= new vector<list<int> > (V);
	}

	void addEdge(int u,int v)
	{
		adj->at(u).push_back(v);
	}
	bool isConnected(int u,int v)
	{
		
		list<int>::iterator it;
		
		for ( it = adj->at(u).begin(); it!=adj->at(u).end(); ++it)
		{
			if(*it==v)
				return true;
		
		}

		return false;

	}
};



bool isConnected_to_set(Graph g,int u,set<int> &S)
{
    set<int>::iterator it;
    
    for ( it = S.begin(); it!=S.end(); ++it) 
    {
	if(!g.isConnected(u,*it))
		return false;
    }
    return true;
}



int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{

         int n,m,u,v;
	 cin>>n >>m;
	 Graph g(n+1);
	 for (int i = 0; i < m; i += 1 ) 
	 {
	 	
		 cin>>u >>v;
		 g.addEdge(u,v);
		 g.addEdge(v,u);
	 
	 }
      
	set<int> table1,table2;
	

	//handle special case
	int temp1,temp2,f=1;
	for(int i=1;i<=n;i++)
	{
		  set<int>::iterator it;
    
    for ( it = table1.begin(); it!=table1.end(); ++it) 
    {
	if(!g.isConnected(i,*it))
    	 f=0	
    }
	if(f==1)  temp1=*it;
	else {

	}
	}
	
	
	
	
	int flag=1;
	
	for (int i = 1; i <=n; i += 1 )
	{

		if(isConnected_to_set(g,i,table1))
			table1.insert(i);
		else if(isConnected_to_set(g,i,table2)){
			table2.insert(i);
		}
		else 
		{	
		flag=0;
		break;
	          }



	}
	
	if(flag==0) cout<<"NO" <<endl;
	else cout<<"YES" <<endl;
	
	}
	return 0;
}
