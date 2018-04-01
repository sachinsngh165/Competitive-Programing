#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
ll no_of_cycle;


class Graph
{
    int V;
    list<int> *adj;
    bool* special;
public:

    Graph(int v);
    void addEdge(int u,int v);
    void dfsUtil(int i,bool* visited);
    ll dfs(int v,int e);
    
};

Graph::Graph(int v)
{
    this->V  = v;
    adj = new list<int>[v];

}

void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::dfsUtil(int src,bool* visited)
{

    visited[src] = true;
    list<int>::iterator i = adj[src].begin();

    for(i=adj[src].begin(); i!=adj[src].end();i++)
    {
        int v = *i;
        if (!visited[v])
        {
            n++;; 
            dfsUtil(v,visited);
                
        }else
            no_of_cycle++;
    }

    
   
}

ll Graph::dfs(int n_v,int e)
{
    
    bool* visited = new bool[V];
    for (ll i = 0; i < V; ++i)
    {
        visited[i] = false;
    }

    ll count = 0;

    vector<ll> v;

    for (ll i = 0; i < V; ++i)
    {
        n=1;
        if (!visited[i])
        {
            dfsUtil(i,visited);
            if (n>=1)
            {
               // cout<<n <<endl;
               v.push_back(n);
            }
            
            
        }
    }

    ll cntd_cmp = v.size();
    no_of_cycle = e - (n_v - cntd_cmp) ;
    // cout<<cntd_cmp <<endl << no_of_cycle <<endl;
    // cout<<n_v <<'\t' <<e <<'\t' <<cntd_cmp <<'\t' <<"No of cylce = " <<no_of_cycle;

    sort(v.begin(),v.end());
    ll len = v.size();

    if (len==0)
    {
        return 0;
    }

    if (no_of_cycle<=0)
    {
        // cout<<"c =0 \n";
        if (len==1)
        {
            v[0] -= 2;
            if (v[0]<=1)
            {
                return 0;
            }
        }else
        {
            ll cnt =0,i=0;
            while(cnt!=2)
            {
                if (v[i]>1)
                {
                    v[i]--;
                    cnt++;
                }else
                    i++;
            }

            
        }

        for (ll i = 0; i < len; ++i)
        {
            count += v[i]*(v[i]-1);
        }

    }else if (no_of_cycle==1)
    {
        // cout<<"c =1 \n";
        if (len==1)
        {
            v[0]--;
            if (v[0]<=1)
            {
                return 0;
            }
        }else
        {
            ll cnt =0,i=0;
            while(cnt!=1)
            {
                if (v[i]>1)
                {
                    v[i]--;
                    cnt++;
                }else
                    i++;
            }
        }
        for (ll i = 0; i < len; ++i)
        {
            ll temp = v[i]*(v[i]-1);
            // cout<<"subgraph " <<i+1 <<" happiness = " <<temp <<" nodes = " <<v[i] <<endl;
            count += temp;
        }
    }else
    {
        // cout<<"c =2 \n";
        for (ll i = 0; i < len; ++i)
        {
            count += v[i]*(v[i]-1);
        }
    }
    // cout<<"ans= ";

    return count;
}


int main()
{
    
    
        ll n,e;
        cin>>n >>e;

        if (n<=2)
        {
            cout<<0 <<endl;
            return 0;
        }

        Graph g(n);


        ll u,v;

        for (ll i = 0; i < e; ++i)
        {
            cin>>u >>v;
            g.addEdge(u-1,v-1);
        }

        cout<<g.dfs(n,e)<<endl;
    
}