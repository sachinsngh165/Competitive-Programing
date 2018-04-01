#include<iostream>
#include<stack>

#define endl '\n'
typedef long long ll;

ll sumN(ll n)
{
	ll sum = (n*(n+1))/2;
	return sum;
}

ll sumTillNow(ll n,ll x)
{
      ll sum = sumN(n);
      if (x<=n)
      {
            sum -=x;
      }

      return sum;
}

bool isImpossible(ll n,ll x)
{     
      if (n==2)
      {
            return true;
      }
	ll sum = sumN(n);
	sum = sum - x;

	if (sum%2!=0)
	{
		return true;
	}

	return false;
}

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int cases=0;cases<t;cases++)
	{

      ll x,n;
      cin>>x >>n;

      // cout<<cases+1 <<'.';
      if (isImpossible(n,x))
      {
      	cout<<"impossible" <<endl;
      }else{

      	ll sumleft = sumN(n);
      	sumleft = sumleft - x;
      	ll num = n;
            ll last = n;
      	sumleft = sumleft/2;

            ll count = 100;
            bool flag = true;

      	stack<ll> s;
      	while(sumleft!=0)
      	{     
                  // cout<<"sumleft: "<<sumleft <<endl;
                  // cout<<"num: "<<num <<endl;
                  
                  // if (!s.empty())
                  // {
                  //       cout<<"top: "<<s.top() <<endl;
                  // }
                  
                  // if (num<0 || count<0) 
                  // {
                  //       break;
                  // }
                  
                  
                  if (sumleft > sumTillNow(num,x))
                  {
                        if (!s.empty())
                        {
                              ll top = s.top();
                              s.pop();
                              sumleft +=top;
                              num = top -1;
                        }else
                        {
                              cout<<"impossible" <<endl;
                              flag = false;
                              break;
                        }
                        
                  }


      		if (sumleft >=num && num!=x)
      		{
      			s.push(num);
      			sumleft -=num;
      		}

                  num = num -1;

      	}

            if (flag)
            {
              for (ll i = 1; i <=n; ++i)
                  {
                        if (i==x)
                        {
                              cout<<2;
                        }else if (!s.empty() && i == s.top())
                        {
                              cout<<1;
                              s.pop();
                        }else {
                              cout<<0;
                        }
                  }

                  cout<<endl;
            }

      


      }
      
      

	}
	return 0;
}