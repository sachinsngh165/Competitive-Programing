// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
#include <map>
#include <list>
using namespace std;
 
// Prototype of a utility function to swap two integers
void swap(int *x, int *y);
 

struct node
{
	int v;
	int wt;
};



// A class for Min Heap
class MinHeap
{
    node *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
    map<int,int> m; // to check if it contains cetain item in tree;


public:
    // Constructor
    MinHeap(int capacity);
 
    // to heapify a subtree with root at given index
    void MinHeapify(int );
 
    int parent(int i) { return (i-1)/2; }
 
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
 
    // to extract the root which is the minimum element
    int extractMin();
 
    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);
 
    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0].wt; }
 
    // Deletes a key stored at index i
    void deleteKey(int i);
 
    // Inserts a new key 'k'
    void insertKey(int k,int w);

    // heap empty status
    bool empty() { return heap_size>0?false:true; }

    //to check if particular vertex is in heap or not
    bool contains(int v) ;

    // to return weight of path by vertex
    int get_wt(int v) { return harr[m[v]].wt ;}


    //print map values & heap
    void print()
    {

    	map<int,int>::iterator it;

    	for(int i=0; i<heap_size; i++)
    	{
    		cout<<'(' <<harr[i].v <<" , " <<harr[i].wt <<")" << '\t';
    	}

    	cout<<'\n';

    	for (it=m.begin(); it!=m.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
    }

};
 
// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new node[cap];
}
 
// Inserts a new key 'k'
void MinHeap::insertKey(int k,int w)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
 
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i].v = k;
    harr[i].wt = w;

    m[harr[i].v] = i;

 
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)].wt > harr[i].wt)
    {
       int temp_wt = harr[(parent(i))].wt;
       int temp_v = harr[(parent(i))].v;
       harr[(parent(i))].wt = harr[(i)].wt;
       harr[(parent(i))].v = harr[i].v;

       harr[i].wt = temp_wt;
       harr[i].v = temp_v;

       m[harr[i].v] = i;
       m[harr[parent(i)].v] = parent(i);

       i = parent(i);
    }
}
 
// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int v, int new_val)
{

	int i = m[v];

    harr[i].wt = new_val;
    while (i != 0 && harr[parent(i)].wt > harr[i].wt)
    {

		m[harr[i].v] = i;
		m[harr[parent(i)].v] = parent(i);

       int temp_wt = harr[(parent(i))].wt;
       int temp_v = harr[(parent(i))].v;
       harr[(parent(i))].wt = harr[(i)].wt;
       harr[(parent(i))].v = harr[i].v;

       harr[i].wt = temp_wt;
       harr[i].v = temp_v;
       i = parent(i);
    }

    
}
 
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0].v;
    }
 
    // Store the minimum value, and remove it from heap
    int root = harr[0].v;
    map<int,int>::iterator it;
    it=m.find(harr[0].v);
  	m.erase (it); 



    harr[0] = harr[heap_size-1];

     

  	m[harr[heap_size-1].v] = 0;

    heap_size--;
    MinHeapify(0);
 
    return root;
}
 
 
// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].wt < harr[i].wt)
        smallest = l;
    if (r < heap_size && harr[r].wt < harr[smallest].wt)
        smallest = r;
    if (smallest != i)
    {
        m[harr[i].v] = i;
		m[harr[smallest].v] = smallest;

       int temp_wt = harr[(parent(i))].wt;
       int temp_v = harr[(parent(i))].v;
       harr[(parent(i))].wt = harr[(i)].wt;
       harr[(parent(i))].v = harr[i].v;

       harr[i].wt = temp_wt;
       harr[i].v = temp_v;
       i = parent(i);

        MinHeapify(smallest);
    }
}

bool MinHeap::contains(int v) 
{
	
	if (m.count(v)>0)
	{
		return true;
	}

	return false;

	
}


// Graph class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<node> *adj;    // Pointer to an array containing adjacency lists
    map<int,int>::iterator it;
    map<int,int> map;

public:
    Graph(int V);   // Constructor

    MinHeap *h;

    void addEdge(int u,int v, int w);   // function to add an edge to graph
    void dijsktra(int src);
    void dijsktra_path();

    void print();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<node>[V];
    h = new MinHeap(V+1);
}
 
void Graph::addEdge(int u,int v, int w)
{
	node newNode ;
	newNode.v = v;
	newNode.wt = w;
    adj[u].push_back(newNode); // Add w to v’s list.

    // since graph is undirected
	newNode.v = u;
	newNode.wt = w;
    adj[v].push_back(newNode); // Add w to v’s list.

}
 

void Graph::dijsktra(int source)
{
	for (int i = 0; i < V; ++i)
	{
		h->insertKey(i,INT_MAX);
	}

	h->insertKey(source,0);


	while(!h->empty())
	{
		int min_vt = h->extractMin();
		map[min_vt] = h->get_wt(min_vt);

		list<node>::iterator i;
		int src_wt = h->get_wt(min_vt);

		for(i = adj[min_vt].begin();i!=adj[min_vt].end();i++)
		{
			int v = i->v;
			int wt = i->wt;

			if (h->contains(v))
			{
				
				int des_wt = h->get_wt(v);

				if ( (src_wt + wt) < des_wt)
				{
					h->decreaseKey(v,(src_wt + wt));
				}
			}
		}
	}
}

void Graph::print()
{
	h->print();
	for (it=map.begin(); it!=map.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
}


int main()
{
	Graph g(9);
	g.addEdge( 0, 1, 4);
    g.addEdge( 0, 7, 8);
    g.addEdge( 1, 2, 8);
    g.addEdge( 1, 7, 11);
    g.addEdge( 2, 3, 7);
    g.addEdge( 2, 8, 2);
    g.addEdge( 2, 5, 4);
    g.addEdge( 3, 4, 9);
    g.addEdge( 3, 5, 14);
    g.addEdge( 4, 5, 10);
    g.addEdge( 5, 6, 2);
    g.addEdge( 6, 7, 1);
    g.addEdge( 6, 8, 6);
    g.addEdge( 7, 8, 7);

	g.dijsktra(0);
	g.print();

	return 0;
}






