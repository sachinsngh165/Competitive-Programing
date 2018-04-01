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

      string a,b;
      cin>>a >>b;
      int len=a.size(),flag=0;
      int count_1=0,count_0=0;
      
      for(int i=0;i<len;i++)
      {
		  
		if(a[i]!=a[i+1] && i+1<len)
		 {	flag=1;
			 break;
		 }  
		  
	  }
	  
	  
	  
	  
	  if(flag==0)
	  {
		  cout<<"Unlucky Chef" <<endl;
	  }else
	  {
			for(int i=0;i<len;i++)
			{
		  
			if (a[i]!=b[i])
			{
				if(a[i]=='1')
			{	
				count_1++;
			}  else count_0++;
			
			}
			
		  
			}
			
			if (count_0 <count_1)
			{
				cout<<"Lucky Chef" <<endl <<count_1 <<endl;
			}else cout<<"Lucky Chef" <<endl <<count_0 <<endl;
			
			
	  }
			
			
	}
	  
	return 0;
}
