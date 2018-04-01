#include<iostream>
#define endl '\n'
#define long long ll
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{
		
		string str;
		cin>>str;
	int size=str.size();	

	int valid=1;
	
	
			for(int i=0;i<size;i++)
				{
				
					if(str[i]=='.')
					{
						if(str[size-1-i]=='.')
							str[i]='a';
						else
					  		str[i]=str[size-1-i];
					}
					else
					{
						
					if(str[i]!='.' && str[(size-1)-i]!='.' && str[i]!=str[(size-1)-i])
					{   cout<<-1 <<endl;
                        valid=0;
                        break;
                    }
                    
                    }
             }
   
	
	
	if(valid) cout<<str <<endl;
	
	}
	return 0;
}
