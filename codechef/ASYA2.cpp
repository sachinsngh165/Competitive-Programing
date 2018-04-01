//
//  ASYA2.cpp
//  
//
//  Created by SACHIN SINGH on 25/09/16.
//
//

#include<iostream>
using namespace std;


bool isAlph(string str)
{
    int alph[26]={0};
    
    for (int k=0,size=strlen(str);k<size ; k++) {
        alph[]
    }
}




int main()
{
    ios::sync_with_stdio(false);
    
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    
    string box1[10000];
    string box2[10000];
    
    for (int i=0; i<n1; i++) {
        cin>>box1[i];
    }
    
    for (int i=0; i<n2; i++) {
        cin>>box2[i];
    }
    
    int flag=0;
    string str;
    for (int i=0; i<n1; i++) {
        for (int j=0; j<n2; j++) {
            flag=0;
            str=box1[i]+box2[j];
            
            
        }
    }
    
    
    
    
    
    
    return 0;
}