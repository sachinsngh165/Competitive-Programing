#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<iostream>
#include<cstdlib>
#include<set>
#include<sstream>
#include<stack>
#include<list>
using namespace std;

typedef long long ll;
typedef pair<long long,long long> lll;
typedef pair<long long,int> lli;
typedef pair<int,int> ii;

#define EL printf("\n")
#define OK printf("OK")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a,x) memset(a, x, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define Get getchar_unlocked()
int getInt() { int a=0,s=1; char c=0; while(c<33) c=Get; if(c=='-') {s=-1; c=Get;} while(c>33) {a=(a<<3)+(a<<1)+c-'0'; c=Get;} return a*s; }

/*long long abs(long long x)
 {
 return x>=0?x:-x;
 }
 */

int main() {
    //freopen("practice.in","r",stdin);
    int t;
    t = getInt();
    //t=1;
    while(t--)
    {
        int n;
        int arr[100002];
        int visited_till[100002];
        int finally_visited[100002];
        n = getInt();
        for(int i=0;i<n;i++)
        {
            arr[i] = getInt();
            visited_till[i]=0;
            finally_visited[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            if(finally_visited[i]==0)
            {
                //find_cycle(i,visited_till,finally_visited,arr,n);
                int val = i;
                int index = val;
                int val2 = val;
                while(visited_till[index]==0&&finally_visited[index]==0)
                {
                    visited_till[index]=1;
                    index = (arr[index]+1+index)%n;
                }
                if(visited_till[index]&&index==val)
                {
                    while(finally_visited[index]==0)
                    {
                        finally_visited[index]=1;
                        index = (arr[index]+1+index)%n;
                    }
                }
                else
                {
                    while(val2!=index&&finally_visited[val2]==0)
                    {
                        finally_visited[val2]=-1;
                        val2 = (arr[val2]+1+val2)%n;
                    }
                }
                while(visited_till[val])
                {
                    visited_till[val]=0;
                    val = (arr[val]+1+val)%n;
                }
                /*printf("%d\n",i+1);
                 for(int j=0;j<n;j++)
                 {
                 printf("%d ",finally_visited[j]);
                 }
                 printf("\n");*/
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(finally_visited[i]==1)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
