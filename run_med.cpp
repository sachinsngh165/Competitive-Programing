#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>

using namespace std;

void insert_number(int num, priority_queue<int,vector<int>, greater<int> > &lower,priority_queue<int> &higher)
{
    if(lower.empty())
        lower.push(num); 
    else if(num > lower.top())
        lower.push(num);
    else 
        higher.push(num);
}



void balance(priority_queue<int,vector<int>, greater<int> > &lower,priority_queue<int> &higher)
{
    int l_size = lower.size();
    int h_size = higher.size();
    

    if(l_size -2 >= h_size)
    {
        higher.push(lower.top());
        lower.pop();
    }else if(h_size -2  >= l_size)
    {
        lower.push(higher.top());
        higher.pop();
    }
    
    
    
}

double get_median(priority_queue<int,vector<int>, greater<int> > &lower,priority_queue<int> &higher)
{
    double med ;
    
    if(lower.size() == 1 && higher.size()==0 )
    {
        med = lower.top();
    }
    else if(lower.size() == higher.size())
    {
        med = ((float)lower.top() + higher.top())/2;
    }else
        med = lower.top();
    
    return med;
}



int main(){
    int n;
    cin >> n;
    int a[n];
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    cout << setprecision(1) << fixed;

    priority_queue<int,vector<int>, greater<int> > lower;
    priority_queue<int> higher;
    
    
    for(int a_i = 0;a_i < n;a_i++){
        
        int num = a[a_i];
        
        insert_number(num,lower,higher);
        balance(lower,higher);
        double med = get_median(lower,higher);
        cout << med <<endl;
        
    }
    
    return 0;
}
