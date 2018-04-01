#include<iostream>
#define endl '\n'
#define long long ll
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{

      int n,temp;
      cin>>n;
        string player;
        cin>>player;
        
        int arr[100];
        for (int i=0; i<n; i++) {
            cin>>arr[i];
        }
        
        temp= arr[0];
        
        if(n==1 && player=="Dee" && temp%2==0){
            
            cout<<"Dee" <<endl;
            
        }else cout<<"Dum" <<endl;
        

	}
	return 0;
}