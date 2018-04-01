#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Graph
{
	int V;
	list<int> *adj;
public:

	Graph(int v);
	void addEdge(int u,int v);
	bool dfsCycle();
	bool dfsCycleUtil(int src,int par,bool* visited);
};


Graph::Graph(int v)
{
	this->V = v;
	adj = new list<int> [v];
}

void Graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}


bool Graph::dfsCycleUtil(int src,int par,bool* visited)
{
	list<int>::iterator i;
	visited[src] = true;
	for(i = adj[src].begin();i!=adj[src].end();i++)
	{
		int v = *i;
		if (!visited[v])
		{
			 if(dfsCycleUtil(v,src,visited))
			 	return true;
		
		}else if(v != par)
		{
			return true;
		}
	}

	return false;

}

bool Graph::dfsCycle()
{
	
	bool *visited = new bool[V];
	for (int i = 0; i < V; ++i)
		visited[i] = false;

	for (int i = 0; i < V; ++i)
	{	
		
		if (!visited[i])
		{
			
			 if (dfsCycleUtil(i,-1,visited))		 
		 		return true;
		}
		
		 
	}
	return false;
}

int main()
{

	int n,m;
	cin>>n >>m;

	char str[n][m];
	string s[n];

	for (int i = 0; i < n; ++i)
		cin>>s[i];

	Graph g(n*m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (s[i][j] == s[i+1][j] && (i+1)<n)
			{
				g.addEdge(i*m+j,(i+1)*m+j);
			}
			if (s[i][j] == s[i][j+1] && (j+1)<m)
			{
				g.addEdge(i*m+j,i*m+(j+1));
			}
		}
	}

	bool res = g.dfsCycle();
	if (res)
	{
		cout<<"YES" <<endl;
	}else
		cout<<"NO" <<endl;

}


