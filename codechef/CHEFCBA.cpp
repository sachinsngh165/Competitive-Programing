//
//  CHEFCBA.cpp
//  
//
//  Created by SACHIN SINGH on 24/07/16.
//
//

#include<iostream>
#include<limits.h>
#define endl '\n'
using namespace std;
int main()
{

    float a,b,c,d;
    cin>>a >>b >>c >>d;
    

    
    
    
    
    
    
    
   
   
    
    
    if (a/b==d/c || b/a==c/d ||a/b==c/d || b/a==d/c
        || a/c==b/d || b/d==c/a ||  a/c==d/b || c/a==b/d
        || a/d==c/b || d/a==b/c  || a/d==b/c || d/a==c/b)
    {
        cout<<"Possible" <<endl;
    }else cout<<"Impossible" <<endl;
   
    
    
    return 0;
}