#include<bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define memo(a,v) memset(a,v,sizeof(a))
#define CLR(a) memo(a,0)
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps (1e-9)
#define inf (1<<29)
#define i64 long long
#define u64 unsigned i64
#define AIN(a,b,c) (a<=b && b<=c)

int d[100005];
vector<int> adj[10];
char a[100005];
int main(){
    int i,x,u,v,sz,n;
	//while(scanf("%s",a)==1){
	scanf("%s",a);
        for(i = 0;i<10;i++) adj[i].clear();
		for(i = 0;a[i];i++){
			AIN('0',a[i],'9');
			d[i] = -1;
		//	if(i && a[i-1]==a[i] && i<n-1 && a[i+1]==a[i]) continue;
			adj[a[i]-'0'].pb(i);

		}
		AIN(1,i,100000);
		n = i;
		queue<int> q;
		q.push(0);
		d[0] = 0;
		while(!q.empty()){
            u = q.front();
            if(u == n - 1) break;
            q.pop();
            x = a[u] - '0';
            sz = adj[x].size();
            for(i = 0;i<sz;i++){
                v = adj[x][i];
                if(d[v] == -1){
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
            adj[x].clear();
            if(u && d[u-1] == -1){
                d[u-1] = d[u] + 1;
                q.push(u-1);
            }
            if(d[u+1] == -1){
                d[u+1] = d[u] + 1;
                q.push(u+1);
            }
		}
		assert(u==n-1 && d[u]!=-1);
		printf("%d\n",d[u]);
	//}
	return 0;
}
