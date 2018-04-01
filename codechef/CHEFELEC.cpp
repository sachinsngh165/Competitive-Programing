//
//  CHEFELEC.cpp
//  
//
//  Created by SACHIN SINGH on 04/07/16.
//
//

#include<iostream>
#define endl '\n'
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int cases=0;cases<t;cases++)
    {
       ll n,e1=0,wire=0;
       string village;
       cin>>n;
       cin>>village;
       
       ll x[100000];
       for(ll i=0;i<n;i++) cin>>x[i];
       
       
       for(ll i=0;i<n;i++)
       {
       	if(village[i]=='1')
        {  e1=i;
            break;
        }
       }
        
        wire+= x[first]-x[0];
        
        
        for (ll i=e1+1; i<n; i++)
        {
        
            if (village[i]=='1')
            {
                
                wire += min( (x[i-1]-x[e1]) , (x[i]-x[e1+1]) );
                e1=i;
            }
           
        }
        
        wire += x[n-1] -x[e1];
        
            cout << wire <<endl;
            
            
            
        }
    
    return 0;
}