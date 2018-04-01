#include <bits/stdc++.h>
using namespace std;
void printPowerSet(char *set, int set_size);
class Graph
{
   public:
 
    int V;    // No. of vertices
   list<int>  *adj;    // Pointer to an array containing adjacency lists
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isGood(int n);
    bool dfs(set<int> grey,int curr,int n );
    void update(Graph &g2,int index);
    void print(){
        
        
       
        for (int i=0; i<V; ++i) 
        {
            
            
            list<int>::iterator itList;
            cout<<i <<" is connected to: "; //or we can use distance(vec.begin(), it);
            
            for (itList= adj[i].begin(); itList!=adj[i].end(); ++itList) 
            {
                cout<<(*itList) <<"     ";
            }
            cout<<endl;
            
        }
    }

};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

bool Graph::isGood(int n)
{
	set<int> grey;
	grey.insert(0);
	return dfs(grey,0,n);

}

bool Graph::dfs(set<int> grey,int curr,int n)
{
	list<int>::iterator it;	

	for (it = adj[curr].begin();it!=adj[curr].end();++it)
	{
		//if index under processing is again encounter or visited again
		if (grey.find(*it)!=grey.end())
		{
			continue;
		}
		// if last index is encounter and all nodes are nodes travesed once
		if (*it==n-1 && grey.size()==n-1)
		{
			return true;
		}

		grey.insert(*it);
		// search more deeper
		return dfs(grey,*it,n);

	}
	return false;
}

void Graph::update(Graph &g2,int index)
{

	(this->adj[index]).swap(g2.adj[index]);
	/*list<int>::iterator temp= adj[index].begin();
	adj[index].begin() = g2.adj[index].begin();
	g2.adj[index].begin()= temp;
	*/
}


int main()
{
	int t;
	cin>>t;
	for (int cases = 0; cases < t; ++cases)
	{
		int count=0;
		string a,b;
		cin>>a >>b;
		int n = a.size();

		Graph g1(n),g2(n);
		int u,v1,v2;
//create a graph of a
		for (int i = 0; i < n; ++i)
		{
			u = i;
			if (a[i]=='1')
			{
				v1=i-1;
				v2=i+1;

			}else{
				v1 = i-2;
				v2 = i+2;
			}

			if (v1>=0 && v1<n)
			{
				g1.addEdge(u,v1);
			}
			if(v2>=0 && v2<n){
				g1.addEdge(u,v2);
			}
		}

		//create a graph of a
		for (int i = 0; i < n; ++i)
		{
			u = i;
			if (b[i]=='1')
			{
				v1=i-1;
				v2=i+1;

			}else{
				v1 = i-2;
				v2 = i+2;
			}

			if (v1>=0 && v1<n)
			{
				g2.addEdge(u,v1);
			}
			if(v2>=0 && v2<n){
				g2.addEdge(u,v2);
			}
		}

	unsigned int pow_set_size = pow(2,n);
    int counter;
 	
 	
 	Graph temp1(n),temp2(n);
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
    	temp1=g1;
    	temp2=g2;
    	/*Run from counter 000..0 to 111..1*/
    
      for(int j = 0; j < n; j++)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
       	
          if(counter & (1<<j))
            {
            	int index = 4-j-1;
            	//cout<<index;
            	if (a[index]==b[index])
       			{
       				continue;
       			}
            	temp1.update(temp2,(index));
            }
       }

       cout<<endl;
       if (temp1.isGood(n) && temp2.isGood(n))
       {
       	temp1.print();
       	cout<<endl;
       	temp2.print();
       	cout<<"counter =" <<counter <<endl;
       	count++;
       }

    	
	}

	cout<<count <<endl;
	
}
return 0;
}
