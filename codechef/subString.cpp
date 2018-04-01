// #include<bits/stdc++.h>
#include <iostream>
#include <unordered_map>
using namespace std;

bool isSubstring(string A,string B,int start,int end)
{
    unordered_map<char,int> present;
    
    for(int i=start;i<end;i++)
    {
        if(present.find(A[i])!=present.end())
        {
            present[A[i]]++;
        }else
          present[A[i]] = 1;
    }
    
    for(int i=0,len=B.length();i<len;i++)
    {


        if(present.find(B[i])==present.end())
        {
            return false;

        }else if (present[B[i]]==1)
        {
          present.erase(B[i]);
        }else
          present[B[i]] = present[B[i]]-1;
    }
    
    return true;
}


string FindSubString (string A, string B) {
   string ans = "";
   int minLen = INT_MAX;
   for(int i=1,len=A.length();i<=len;i++)
   {
       for(int j=0;j<len-i;j++)
       {
           if(isSubstring(A,B,j,j+i-1))
           {
                string temp = A.substr(j,j+i-1);
               // cout<<temp <<endl;
               if (temp.length() < minLen)
               {
                  ans = temp;
                  minLen = temp.length();
               }
                
           }
       }
   }
   if(ans == "")
        ans= "-1";

    return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        string A;
        cin>>A;
        string B;
        cin>>B;

        string out_;
        out_ = FindSubString(A, B);
        cout << out_;
        cout << "\n";
    }
}