//
//  LCOLLIS.cpp
//  
//
//  Created by SACHIN SINGH on 26/06/16.
//
//

#include<iostream>
#define endl '\n'
using namespace std;
int fact(int num);
int nCr(int n,int r);
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int cases=0;cases<t;cases++)
    {
        
        int n,m;
        char temp;
        cin>>n >>m;
        
        int girls[100]={0};
        for (int i= 0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                cin>>temp;
               
                if (temp=='1')
                    girls[j]++;
                
                
            }
            
        }
        
      
        int collision=0;
        for (int i=0; i<m; i++)
        {
            if (girls[i]>1) {
                collision+=nCr(girls[i],2);
            }
            
        }
        cout<< collision <<endl;
    }
    return 0;
}
int fact(int num)
{
    if(num<2)
        return 1;
    return num*fact(num-1);
}
    
int nCr(int n,int r)
{
    if (r > n) {
        return 0;
    }
    return fact(n)/(fact(r)*fact(n-r));
}