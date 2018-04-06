#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

list<int> adj[100001];
vector<ll> dp(100001,0);
bool visited[100001] = {false};
vector<ll> size(100001,0);


void addEdge(int u, int v)
{
        adj[u].push_back(v);
        adj[v].push_back(u);
}

void DFS(ll root,ll depth)
{
    if(!visited[root])
    {
        visited[root] = true;
        dp[root] = depth;
        size[root] = 1;
        for(auto it=adj[root].begin();it!=adj[root].end();it++)
        {
            if(!visited[*it])
            {
                DFS(*it,depth+1);
                size[root] += size[*it];
            }
        }
    }
}


void print(int n)
{
        int v;       
        for(int i=1;i<=n;i++)
        {
            cout<<i <<"--> ";
            for(auto it=adj[i].begin();it!=adj[i].end();it++)
            {
                v = *it;
                cout<<v <<" ";
            }
            cout<<endl;
        }
}

double Soln(ll n)
{
    DFS(1,0);
    
    ll k = 0;
    ll V = n;
    for(int i=1;i<=V;i++)
    {
        k += dp[i];
        cout<<"dp[" <<i <<"] : "<<dp[i]<<endl;
        cout<<"sz[" <<i <<"] : "<<size[i]<<endl;
    }
    
    cout<<"k= "<<k<<endl;
    double ans = 0.0;
    for(int i=2;i<=V;i++)
    {
        ans += (size[1]-size[i])*dp[i];
    }

    cout<<"ans= "<<ans<<endl;
    ans = ans/k;
    return ans;
}


int main() {
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n-1; a0++){
        int x;
        int y;
        cin >> x >> y;
        addEdge(x,y);
    }
    
    // print(n);
    cout << fixed << setprecision(10);
    cout<<Soln(n+1)<<endl;
    return 0;
}
