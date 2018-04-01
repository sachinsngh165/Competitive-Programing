#include<iostream>
#include<algorithm>
#define MOD 1000000007
#define endl '\n'
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int tcs;
    cin>>tcs;
    while(tcs--){
        string a,b;
        cin >> a;
        sort(a.begin(), a.end());
        for(int i=0; i<a.length(); i++){
            for(int j=i; j<a.length(); j++){
                b.clear();
                for(int k=i; k<j+1; k++){
                    
                    if (k>=a.length()) {
                        break;
                    }
                    
                    b.push_back(a[k]);
                    
                }
                //sort(b.begin(), b.end());
                cout << b << endl;
                
            }
           
        }
      
    }
    return 0;
}
