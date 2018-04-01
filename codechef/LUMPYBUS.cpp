#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    long long t;
    cin>>t;
    for(long long cases=0;cases<t;cases++)
    {
        
        long long n,satisfied=0;
        cin>>n;
        
        long long p,q;
        cin>>p >>q;
        
        long long payee[100000];
        for (long long i=0; i<n; i++)
        {
            cin>>payee[i];
        }
        
        sort(payee,payee+n);
        
        if (q==0)
        {
            
            for (long long i=0; i<n && p>0; i++) {
                if (payee[i]<=p) {
                    
                    p-=payee[i];
                    satisfied++;
                    
                }
            }
           
        }
        else if(p==0)
        {
            for (long long i=0; i<n; i++)
            {
                if (payee[i]%2==0 && payee[i]<=(2*q))
                {
                    q-=(payee[i]/2);
                    satisfied++;
                    
                }
            }
            
            
        }
        cout<<satisfied <<endl;
        }
    
    return 0;
}