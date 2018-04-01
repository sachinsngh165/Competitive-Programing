#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int 	ll;
typedef pair<ll,ll>   ii;
typedef vector< ii >   vii;
typedef vector<ll>     vi;
typedef vector< vi >   vvi;

#define mm 100005
#define nn 1005
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(a) (ll)(a.size())
#define all(a) a.begin(),a.end()
#define forn(i, n) for(ll i = 0; i < ll(n); ++i)
#define rep(i, a, b) for(ll i = ll(a); i <= ll(b); ++i)
#define cases ll t;  cin>>t;   while(t--)
#define check(a,n) forn(iiii,ll(n)) cout<<ll(a[iiii])<<" "; cout<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
list<ll> l;

    ll n,m,k,b[2*mm],j=0;
    ll ans=1e18,ans2=0;
int main()
{
    fast_io;
    cin>>n>>m>>k;
    forn(i,n) cin>>b[i];
    ll x=1,c;
    forn(i,n)
    {
        if(b[i]==1)
        {
            if(j<m)
            {
                if(sz(l)==0) c=i;
                else c=i-*l.rbegin();
                l.pb(i);
                ans2+=c*x;
                x=(j+1)*k;
                if(m==1) return cout<<ans2,0;
               // cout<<ans2<<endl;
                if(j==m-1) ans=min(ans,ans2);
            }
            else
            {
                ll ans1=ans2-(*l.rbegin()-*l.begin())*k;
                ll z=*l.begin();
                l.pop_front();
                ans1+=*l.begin()-z;
                ans1+=(i-*l.rbegin())*(m-1)*k;
                //cout<<ans1<<endl;
                ans=min(ans,ans1);
                l.pb(i);
                ans2=ans1;
            }
            j++;
        }
    }
    if(j<m) cout<<-1;
    else cout<<ans;
    return 0;
}

