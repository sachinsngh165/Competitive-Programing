#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



class Graph
{
    int V;
    list<int> *adj;
    bool* special;
public:

    Graph(int v);
    void addEdge(int u,int v,bool s);
    bool dfsUtil(int i,bool* visited,bool* special,int* n);
    int dfs();
    
};

Graph::Graph(int v)
{
    this->V  = v;
    adj = new list<int>[v];
    special = new bool[v];
    
    for (int i = 0; i < v; ++i)
    {
        special[i] = false;
    }

}

void Graph::addEdge(int u,int v,bool s)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    special[v] = special[v]|s;
    special[u] = special[u]|s;
}

bool Graph::dfsUtil(int src,bool* visited,bool* special,int* n)
{

    visited[src] = true;
    list<int>::iterator i = adj[src].begin();

    if (adj[src].size()==1 && (special[*i] || visited[*i]))
    {
        (*n)++;
    }


    for(i=adj[src].begin(); i!=adj[src].end();i++)
    {
        int v = *i;
        if (special[v] && *n==0)
        {
            continue;
        }
        if (!visited[v] && !special[v])
        {
            *n +=1; 
            if(dfsUtil(v,visited,special,n)==false)
                return false;
        }
    }

    
    return true;
}

int Graph::dfs()
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i)
    {
        visited[i] = false;
    }

    int count = 1;

    for (int i = 0; i < V; ++i)
    {
        if (!visited[i] && !special[i])
        {
            int n=0;
            if(dfsUtil(i,visited,special,&n))
            {
                count += n;
            }
            // cout<<"for vertex " <<i+1 <<" depth is "<<n <<endl;
        }
    }

    return count;
}


int main()
{
    int t;
    cin>>t;
    for (int q = 0; q < t; ++q)
    {
        int n;
        cin>>n;

        Graph g(n);
        int u,v;
        bool s;

        for (int i = 0; i < n-1; ++i)
        {
            cin>>u >>v >>s;
            g.addEdge(u-1,v-1,s);
        }
        cout<<g.dfs()<<endl;
    }
}