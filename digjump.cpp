#include <iostream>
#include <list>
#include <limits.h>
using namespace std;

typedef long long ll;

class Graph
{
	ll v;
	list<ll> *adj;
	ll *dis ;
	bool *sptSet ;

public:

	Graph(ll v);
	~Graph();

	void addEdge(ll u,ll v);
	ll dijkstra_path_len();
	list<ll>::iterator k;
	void prll_graph()
	{
		for (ll i = 0; i < v; ++i)
		{
			cout<<i <<" =>  ";

			for(k = adj[i].begin();k!=adj[i].end();k++)
			{
				ll v = *k;

				cout<< v <<" , ";
			}
			cout<<endl;
		}
	}

};


Graph::Graph(ll v)
{
	this->v = v;
	adj  = new list<ll>[v];
	dis = new ll[v];
	sptSet = new bool[v];
}

Graph::~Graph()
{
	delete [] dis;
	delete [] sptSet;
}


void Graph::addEdge(ll u,ll v)
{
	adj[u].push_back(v);
}

ll Graph::dijkstra_path_len()
{
	

	for (ll i = 0; i < v; ++i)
	{
		dis[i] = ll_MAX;
		sptSet[i] = false;
	}


	dis[0] = 0;

	

	for (ll i = 0; i < v-1; ++i)
	{
		
		// Extract vertices with minimum distance and and is present in set
		ll vetx = -1;
		ll min_dis = ll_MAX;
		for (ll j = 0; j < v; ++j)
		{
			if ( sptSet[j]==false && (dis[j] < min_dis))
			{
				vetx = j;
			}
			
		}

		sptSet[vetx] = true;

		if (vetx==-1)
		{
			return dis[v-1];
		}


		// update distance of all the neighbouring vertices of min vertex
		list<ll>::iterator k;

		for( k = adj[vetx].begin();k!=adj[vetx].end();k++)
		{
			ll temp = *k;

			if (dis[temp] > (dis[vetx] + 1 ))
			{
				dis[temp] = dis[vetx] + 1 ;
			}
		}

	}


	return dis[v-1];
}


ll main()
{

	string s;
	cin>>s;

	ll len = s.length();

	if (len == 1 || len==2)
	{
		cout<<len-1 <<endl;
		return 0;
	}


	Graph g(len);
	g.addEdge(0,1);
	for (ll i = 1; i < len-1; ++i)
	{
		g.addEdge(i,i+1);
		g.addEdge(i,i-1);
	}
	g.addEdge(len-1,len-2);


	for (ll i = 0; i < len; ++i)
	{
		for (ll j = 0; j < len; ++j)
		{
			if (s[i] == s[j] && i!=j && i+1!=j && i-1!=j)
			{
				g.addEdge(i,j);
			}
		}
	}


	ll dis = g.dijkstra_path_len();
	cout<<dis <<endl;


	


	return 0;
}





























