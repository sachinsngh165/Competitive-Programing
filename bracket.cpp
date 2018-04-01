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

using namespace std;

bool is_balanced(string expression) {
     
    stack<char> st;
    char c;
    int len = expression.length();
    
    if(len == 1)
        return false;
    
    for (char b : expression)
    {   
        
        
        if(b=='(' ||b=='[' || b=='{' )
            st.push(b);
        else
        {
            c = st.top();
            st.pop();
            
             if( (c =='(' && b==')') || ( c == '[' && b == ']' ) || (c == '{' && b =='}'))
                 continue;
             else
             {
                 while(!st.empty())
                     st.pop();
                  return false;
             }
                
        }
    }
     
    if(!st.empty())
    {
        while(!st.empty())
           st.pop();
        
        return false;
    }
       
    
    return true;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
