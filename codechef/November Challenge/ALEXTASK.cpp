#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll unit=1;

ll gcd(ll u, ll v)
{
    // simple cases (termination)
    if (u == v)
        return u;

    if (u == 0)
        return v;

    if (v == 0)
        return u;

    // look for factors of 2
    if (~u & unit) // u is even
    {
        if (v & unit) // v is odd
            return gcd(u >> unit, v);
        else // both u and v are even
            return gcd(u >> unit, v >> unit) << unit;
    }

    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> unit);

    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> unit, v);

    return gcd((v - u) >> unit, u);
}


ll lcm(ll a,ll b)
{
  return (a*b)/gcd(a,b);
}

int main()
{
  ll t;
  cin>>t;
  for (ll cases = 0; cases < t; ++cases)
  {
    ll n;
    cin>>n;
      ll a[n];
      for (ll i = 0; i < n; ++i)
      {
        cin>>a[i];
      }

      ll min_lcm = numeric_limits<ll>::max();;
      
      for (ll i = 0; i < n; ++i)
      {
        for (ll j = i; j < n; ++j)
        {
          if (i!=j)
          {
            min_lcm = min(min_lcm,lcm(a[i],a[j]));
          }
        
        }
      }

      cout<<min_lcm <<endl;
  }
  return 0;
}