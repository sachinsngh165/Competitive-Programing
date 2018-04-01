#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
#define long long ll
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
    string str;
    cin>>str;
    
    vector <char> S(str.begin(),str.end());
    
    sort(S.begin(),S.end());
    
    
    int n;
    cin>>n;
    string str2;
    for (int i=0; i<n; i++) {
        cin>>str2;
        vector <char> W(str2.begin(),str2.end());
        
        int flag;
        
        for (int j=0; j<W.size(); j++) {
            flag=1;
            
            if (!binary_search(S.begin(), S.end(), W[j]))
            {
                cout<<"No" <<endl;
                flag=0;
                break;
            }
            
        }
        
        if (flag!=0) {
            cout<<"Yes" <<endl;
        }
      
    }
    
	return 0;
}