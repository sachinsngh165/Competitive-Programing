#include<iostream>
#define endl '\n'
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{

      int n,k;
      cin>>n >>k;
        int a[100],count=0;
        
        for (int i=1; i<=n; i++) {
            cin>>a[i];
        }
        
        
        int hash[100]={0};
        
        for (int i=1; i<=n; i++) {
            
            
            if (a[i]==i) {
                hash[a[i]]=-1;
            }else if(hash[a[i]]!=-1){
                hash[a[i]]++;
            }
            
        }
        
        
        for (int i=1; i<=n; i++) {
            
            if (hash[i]!=-1 && hash[i]>=k) {
                count++;
            }
            
        }
        cout<<count <<endl;
        
        

	}
	return 0;
}