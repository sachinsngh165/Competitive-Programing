//
//  CHFNFRNv4.cpp
//  
//
//  Created by SACHIN SINGH on 08/09/16.
//
//

    // C++ program to find out whether a given graph is Bipartite or not
#include <iostream>
#include <queue>
#include<vector>
using namespace std;



    // This function returns true if graph G[V][V] is Bipartite, else false
bool isBipartite(vector<vector<int> > &G,long long V,long long src)
{
        // Create a color array to store colors assigned to all veritces. Vertex
        // number is used as index in this array. The value '-1' of  colorArr[i]
        // is used to indicate that no color is assigned to vertex 'i'.  The value
        // 1 is used to indicate first color is assigned and value 0 indicates
        // second color is assigned.
    long long colorArr[V];
    for (long long i = 1; i < V; ++i)
        colorArr[i] = -1;
    
        // Assign first color to source
    colorArr[src] = 1;
    
        // Create a queue (FIFO) of vertex numbers and enqueue source vertex
        // for BFS traversal
    queue <long long> q;
    q.push(src);
    
        // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
        {
            // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        long long u = q.front();
        q.pop();
        
            // Find all non-colored adjacent vertices
        for (long long v = 1; v < V; ++v)
            {
                // An edge from u to v exists and destination v is not colored
            if (G[u][v] && colorArr[v] == -1)
                {
                    // Assign alternate color to this adjacent v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
                }
            
                //  An edge from u to v exists and destination v is colored with
                // same color as u
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
            }
        }
    
        // If we reach here, then all adjacent vertices can be colored with
        // alternate color
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
        
        if(isBipartite(G,V,1))
            cout << "YES" <<endl;
            else cout << "NO" <<endl;
    
    }
    return 0;
}


