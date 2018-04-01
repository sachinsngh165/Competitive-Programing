#include<iostream>
#include<math.h>
#define endl '\n'
using namespace std;


int is_prime(int num)
{
    for (int i=2; i<num; i++)
    {
        
        if (num%i==0)
        {
            return 0;
        }
        
    }
    return 1;
}

int no_of_prime_factor(int num){
    
    int count=0;
    
    for (int i=2; i<=num && num>1; i++)
    {
        
        if ( is_prime(i) && num%i == 0)
        {
            count++;
            
        }
    }
        
    return count;
    
}



int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{

        int   n;
    int flag=0,i=1;
      cin>>n;
        
        while (n!=0)
        {
            
            
                if (no_of_prime_factor(i)==1 &&  no_of_prime_factor(n-i)>1)
                {
                    flag++;
                    n=n-i;
                }else
                {
                    
                    flag+=2;
                    break;
                    
                    
                }
                
            i++;
            
            
        }
        
       
        if (flag%2==0) {
            cout<<"Chef" <<endl;
        } else {
            cout<<"Misha" <<endl;
        }
       
        


	}
	return 0;
}