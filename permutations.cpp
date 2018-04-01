#include<iostream>
#include<algorithm>
using namespace std;

void permutations(string str,int st,int end);
int main() {
	
	string str;
	cin>>str;
	permutations(str,0,str.length());
    cout<<endl;
	return 0;
}

void permutations(string str,int st,int end)
{
    if (st==end-1)
    {
        cout<<str <<'\t';
        return;
    }
   
    for(int i=st;i<end;i++)
    {
        swap(str[st],str[i]);
        permutations(str,st+1,end);
        
        swap(str[st],str[i]);
    }
    
    
}