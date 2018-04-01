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

        long long n,satisfied=0,paid=0;
        cin>>n;
        
        long long p,q;
        cin>>p >>q;
        
        long long payee[100000];
        for (long long i=0; i<n; i++)
        {
            cin>>payee[i];
        }
        
        sort(payee,payee+n);
      
        
            
            
            
            while (paid<n) {
                
                
                if (p==0 && q==0) {
                    break;
                }
                
                
                if (q==0) {
                    
                    for (long long i=paid; i<n; i++) {
                        if (payee[i]<=p) {
                            
                            p-=payee[i];
                            satisfied++;
                            
                        }
                    }
                    break;
                }else if(p==0)
                {
                    for (long long i=paid; i<n && q>0; i++)
                    {
                        if (payee[i]%2==0 && payee[i]<=2*q)
                        {
                            
                            q-=payee[i]/2;
                            satisfied++;
                            
                        }
                    }
                    
                    break;
                    
                }
                
                //if even amount to be pay
                if (payee[paid]%2==0) {
                
                    // if we have required number of 2's coins
                    if (payee[paid]/2 <= q)
                    {
                        
                        q-=payee[paid]/2;
                        paid++;
                        satisfied++;
                    }else if(payee[paid] <= (q*2+p))
                    {
                        q=0;
                        p-= payee[paid]-2*q;
                        paid++;
                        satisfied++;
                    }else
                    {
                        break;
                        
                    }
                    
                   
                }else //if odd amount to be pay
                {
                 
                    //first use 2's coins
                    if (payee[paid]/2 <=q) {
                        
                        
                        q-=payee[paid]/2;
                        p--;
                        satisfied++;
                        paid++;
                    
                    }else if(payee[paid] <= (q*2+p))
                    {
                      
                        q=0;
                        p-= payee[paid]-2*q;
                        satisfied++;
                        paid++;
                    }else
                    {
                        break;
                        
                    }
                    
                    
                }
          
        
        
            }
        
        cout<<satisfied <<endl;
        
    }
    
            
    
        
        

	
	return 0;
}