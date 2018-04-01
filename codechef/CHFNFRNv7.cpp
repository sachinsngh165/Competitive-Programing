    //
    //  CHFNFRNv7.cpp
    //
    //
    //  Created by SACHIN SINGH on 08/09/16.
    //
    //

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Graph
{
    int v,*color,*visited;
    list <int> *adj;
public:
    void addEdge(int,int);
    Graph(int);
    bool isBipartite();
};
void Graph:: addEdge(int s,int d)
{
    adj[s].push_back(d);
}
Graph::Graph(int n)
{
    v=n;
    color=new int[n];
    fill(color,color+v,-1);
    visited=new int[n];
    adj=new list<int>[v];
    fill(visited,visited+n,0);
}
bool Graph:: isBipartite()
{
    queue<int> q;
    
    for(int i=1; i<v; i++)
        {
        
        if(!visited[i])
            {
            
            
            q.push(i);
            color[i]=1;
            while(!q.empty())
                {
                int u=q.front();
                q.pop();
                if(!visited[u])
                    {
                    visited[u]=1;
                    for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
                        {
                        if(color[*it]==color[u])
                            return false;
                        color[*it]=1-color[u];
                        q.push(*it);
                        }
                    }
                }
            }
        }
    
    return true;
}

void Complement(vector<vector<int> > &G,long long V)
{
    for (long long i=1; i<V; i++) {
        for (long long j=1; j<V; j++) {
            if (G[i][j]==1) {
                G[i][j]=0;
            }else G[i][j]=1;
        }
    }
}

    // Driver program
int main()
{
    ios::sync_with_stdio(false);
    long long t;
    cin>>t;
    for (long long cases=0; cases<t; cases++)
        {
        long long V;
        cin>>V;
        ++V;
        
            //construct a Graph of size V*V
        vector<vector<int> > G;
        G.resize(V, vector<int>(V, 0));
        
        
            //since an element is related to itself
        for (long long i=1; i<V;i++)
            {
            G[i][i]=1;
            }
        
        long long m,u,v;
        cin>>m;
        for (long long i=0; i<m; i++)
            {
            cin>>u >>v;
            G[u][v]=1;
            G[v][u]=1;
            }
        
        Complement(G,V);
        
        
        Graph g(V);
        
        for (int i=1; i<V; i++) {
            for (int j=1; j<V; j++) {
                if (G[i][j]==1) {
                    g.addEdge(i, j);
                }
                
            }
        }
        
        
        
        if(g.isBipartite())
            cout<<"YES" <<endl;
        else cout<<"NO" <<endl;
        
        
        }
    return 0;
}