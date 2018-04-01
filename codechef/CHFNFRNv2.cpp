    //use http://www.geeksforgeeks.org/bipartite-graph/ tutorial

#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<queue>
using namespace std;

class Graph
{
protected:
	int V;
	int **metrix;

public:
	Graph(int n)
	{
		this->V=n;
		
		//initialize dynamic metrix of v*v
		metrix= new int*[V];

		for (int i = 0; i < V; i += 1 ) {
			metrix[i]=new int[V];	
		
		}

		
		for (int i = 1; i < V; i += 1 ) {

			for (int j = 1; j < V; j += 1 ) {
				metrix[i][j]=0;
			}
		}

	}

	void addEdge(int u,int v)
	{
	  metrix[u][v]=1;
	}
	void print()
    {
    for (int i = 1; i < V; i += 1 ) {
        cout<<i <<"connected to:- ";
        for (int j = 1; j <=V; j += 1 ) {
            if (metrix[i][j]==1) {
                cout<<j <<"     ";
            }
        }
        cout<<endl;
    }
    
    
    }
    bool isBipartite(int src);
    void complement();
};


bool Graph::isBipartite(int src)
{
        // Create a color array to store colors assigned to all veritces. Vertex
        // number is used as index in this array. The value '-1' of  colorArr[i]
        // is used to indicate that no color is assigned to vertex 'i'.  The value
        // 1 is used to indicate first color is assigned and value 0 indicates
        // second color is assigned.
    
    int colorArr[V];
    for (int i = 1; i < V; ++i)
        colorArr[i] = -1;
    
        // Assign first color to source
    colorArr[src] = 1;
    
        // Create a queue (FIFO) of vertex numbers and enqueue source vertex
        // for BFS traversal
    queue <int> q;
    q.push(src);
    
        // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
        {
            // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        int u = q.front();
        q.pop();
        
            // Find all non-colored adjacent vertices
        for (int v = 1; v < V; ++v)
            {
                // An edge from u to v exists and destination v is not colored
            if (metrix[u][v] && colorArr[v] == -1)
                {
                    // Assign alternate color to this adjacent v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
                }
            
                //  An edge from u to v exists and destination v is colored with
                // same color as u
            else if (metrix[u][v] && colorArr[v] == colorArr[u])
                return false;
            }
        }
    
        // If we reach here, then all adjacent vertices can be colored with
        // alternate color
    return true;
}

void Graph:: complement()
{
    
    for (int i = 1; i < V; i += 1 ) {
        
        for (int j = 1; j < V; j += 1 ) {
            if (metrix[i][j]==1) {
                metrix[i][j]=0;
            } else {
                metrix[i][j]=1 ;
            }
        }
    }
    
}

int main()
{
	ios::sync_with_stdio(false);
	
    Graph g(7);
	/*for(int cases=0;cases<t;cases++)
	{

     int n,u,v;
	 long long m;
	 cin>>n >>m;
	 
        //create a graph using metrix
        Graph g(n+1);
	 for (long long i = 0; i < m; i += 1 )
	 {
	 	
		 cin>>u >>v;
		 g.addEdge(u,v);
		 g.addEdge(v,u);
	 
	 }}
    */
    g.addEdge(1,2);
    g.addEdge(1,1);
    g.addEdge(1,3);
    g.addEdge(2,2);
    g.addEdge(2,4);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,3);
    g.addEdge(3,2);
    g.addEdge(3,1);
    g.addEdge(4,4);
    g.addEdge(4,2);
    g.addEdge(4,5);
    g.addEdge(5,5);
    g.addEdge(5,4);
    g.addEdge(4,6);
    g.addEdge(6,6);
    g.addEdge(6,4);
    
    g.complement();
   if (g.isBipartite(1)) {
        cout<<"NO" <<endl;
    }
	else cout<<"YES" <<endl;
	
    g.print();
	
	return 0;
}
