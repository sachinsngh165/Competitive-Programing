//
//  CHFNFRNv6.cpp
//  
//
//  Created by SACHIN SINGH on 08/09/16.
//
//


#include <iostream>
#include <queue>
#include<vector>
using namespace std;


/* A utility function to check if the current color assignment
 is safe for vertex v */

bool isSafe (int v, vector<vector<bool> > &graph, vector<int> &color, int c,int V,vector<int> &visited)
{
    
    for (int i = 1; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

/* A recursive utility function to solve m coloring problem */
bool graphColoringUtil(vector<vector<bool> > &graph, int m, vector<int> &color, int v,int V,vector<int> &visited)
{
    /* base case: If all vertices are assigned a color then
     return true */
    if (v == V)
        return true;
    if (!visited[v]) {
        /* Consider this vertex v and try different colors */
        for (int c = 1; c <= m; c++)
            {
            /* Check if assignment of color c to v is fine*/
            if (isSafe(v, graph, color, c,V,visited))
                {
                color[v] = c;
                visited[v]=1;
                /* recur to assign colors to rest of the vertices */
                if (graphColoringUtil (graph, m, color, v+1,V,visited) == true)
                    return true;
                
                /* If assigning color c doesn't lead to a solution
                 then remove it */
                color[v] = 0;
                }
            }
    }
    
    
    /* If no color can be assigned to this vertex then return false */
    return false;
}

/* This function solves the m Coloring problem using Backtracking.
 It mainly uses graphColoringUtil() to solve the problem. It returns
 false if the m colors cannot be assigned, otherwise return true and
 prints assignments of colors to all vertices. Please note that there
 may be more than one solutions, this function prints one of the
 feasible solutions.*/
bool graphColoring(vector<vector<bool> > &graph, int m,int V,vector<int> &visited)
{
        // Initialize all color values as 0. This initialization is needed
        // correct functioning of isSafe()
    vector<int> color(V,0) ;
    for (int i = 1; i < V; i++)
        color[i] = 0;
    
        // Call graphColoringUtil() for vertex 1
    if (graphColoringUtil(graph, m, color, 1,V,visited) == false)
        {
        return false;
        }
    return true;
}

void Complement(vector<vector<bool> > &G,long long V)
{
    for (long long i=1; i<V; i++) {
        for (long long j=1; j<V; j++) {
            if (G[i][j]==true) {
                G[i][j]=false;
            }else G[i][j]=true;
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
        vector<vector<bool> > G;
        G.resize(V, vector<bool>(V, false));
        
        
            //since an element is related to itself
        for (long long i=1; i<V;i++)
            {
            G[i][i]=true;
            }
        
        long long m,u,v;
        cin>>m;
        for (long long i=0; i<m; i++)
            {
            cin>>u >>v;
            G[u][v]=true;
            G[v][u]=true;
        }
        
        Complement(G,V);
        
        vector<int> visited(V,0);
        
        if(graphColoring(G,2,V,visited))
            cout << "YES" <<endl;
            else cout << "NO" <<endl;
    
    }
    return 0;
}


