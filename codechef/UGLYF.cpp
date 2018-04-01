#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{

      string s1;
      string s2;
      cin>>s1 >>s2;
      int map1[27]={-1};
      int map2[27]={-1};

      int size1=s1.size(),size2=s2.size();

      //traverse 1st string
      for (int i = 0; i < size1; ++i)
      {
      		int ch = (int)(s1[i])-'A';
      		
      		if (map1[ch]<0)
      		{
      			map1[ch] = i;
      		}
      		else if(abs(size1/2-map1[ch])>abs(size1/2-i))
      		{

      			map1[ch] = i;
      		}
      }

      //traverse 2nd string
      for (int i = 0; i < size2; ++i)
      {
      		int ch = (int)(s2[i])-'A';
      		if (map2[ch]<0)
      		{
      			map2[ch] = i;
      		}
      		else if(abs(size2/2-map2[ch])>abs(size2/2-i))
      		{

      			map2[ch] = i;
      		}
      }
     /*
     for (int i = 0; i < 27; ++i)
      {
      	cout<<i <<". " <<map1[i] <<endl;
      }
      cout<<endl;

      for (int i = 0; i < 27; ++i)
      {
      	cout<<i <<". " <<map2[i] <<endl;

      }
      cout<<endl <<"------------------\n";
		*/

     int petals=INT_MAX;

     for (int i = 0; i <26; ++i)
     {
     	
     		if (map1[i]<0 || map2[i]<0)
     		{
     			continue;
     		}

     		int l1,l2,l3,l4;
     		l1 = map1[i];
     		l3 = size1-map1[i];
     		l2 = map2[i];
     		l4 = size2-map2[i];
     		int ugly = abs(l1-l2)+abs(l2-l3)+abs(l3-l4)+abs(l4-l1);
     		petals = min(petals,ugly);
     }

     cout<<petals <<endl;




	}
	return 0;
}