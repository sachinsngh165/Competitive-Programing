//
//  EGRANDR.cpp
//  
//
//  Created by SACHIN SINGH on 02/07/16.
//
//

#include<iostream>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int cases=0;cases<t;cases++)
    {
        
        int n;
        cin>>n;
        
        double a[100000];
        double sum=0;
        int maxMarks = 0,failed=0;
        
        for (int i=0; i<n; i++) {
            cin>>a[i];
            
            sum+=a[i];
            if (a[i] == 5) {
                maxMarks=1;
            }
            
            //if he get failed
            if (a[i]== 2) {
                failed = 1;
            }
        
        }
        //find average
        double avg = sum/n;
        
        
        if (failed == 1 || avg < 4.0 || maxMarks == 0) {
            cout<< "No" <<endl;
        }else
            cout <<"Yes" <<endl;
        
        
    }
    return 0;
}
