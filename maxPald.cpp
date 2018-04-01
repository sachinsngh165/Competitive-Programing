#include <iostream>
#include<unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

long long mod = 1000000007;
long long  alpha[26] = {0};
typedef long long ll;

string str;
// Returns value of n! % p
//(a / b) mod p = ((a mod p) * (b^(-1) mod p)) mod p
//b^(p - 2) mod p

ll modFact(ll n, ll p=mod)
{
    if (n >= p)
       return 0;     
 
    ll result = 1;
    for (ll i=1; i<=n; i++)
        result = ((result%p) * (i%p)) % p;  
 
    return result;
}

// Function to find modulo inverse of a
// A naive method to find modulor multiplicative inverse of
// 'a' under modulo 'm'
// C++ program to find multiplicative modulo inverse using
// Extended Euclid algorithm.

 
// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y);
 
// Function to find modulo inverse of a
ll modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // m is added to handle negative x
        int res = (x%m + m) % m;
        return  res;
    }

    return 0;
}
 
// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
} 

ll getNumMaxLenPalds(ll pair,ll single,vector<ll> freq)
{
    // total numbers of max len 
    // palindroms = ((num_of_pairs!)*num_of_singles)/(mul of rep!)
    ll total = modFact(pair,mod);
    if(single>0)
        total = (total*(single%mod))%mod;

    // cout<<total <<endl;
    
    ll prod=1;
    for (int i = 0,len = freq.size(); i < len; ++i)
    {
        prod = ((prod%mod)*(modFact(freq[i]%mod)))%mod;
    }
    // cout<<prod <<endl;
    if(prod>1)
    {    ll inv = modInverse(prod,mod);
    
        ll res = (total*inv)%mod;
        return res;
    }
    return total;
}


void initialize(string s) {

   str = s;
}



int answerQuery(int l, int r) {
    
    unordered_map<char,ll> freq;
    ll pair=0,sg=0,key; 
    for(int i=l-1;i<r;i++)
    {
        key = str[i];
        // cout<<(char)key <<' ';
        if (freq.find(key) != freq.end())
            freq[key] +=1;
        else
            freq[key] =1;
    }
    // cout<<endl;
//wldsfubcsxrryqpqyqqxrlffumtuwy0mbybnpemdiwyqz    
    //    iterating over all value of umap
    unordered_map<char, ll>:: iterator itr;
    ll value;
    ll unique_twice =0;
    vector<ll> v;
    int i=0;
    for (itr = freq.begin(); itr != freq.end(); itr++)
    {
       value = itr->second;
       // cout<<(itr->first) <<": "<<value <<endl;
        if(value>=2)
        {
            v.push_back(value/2);
            unique_twice +=1;
        }
            
        pair +=value/2;
        sg +=value%2;
    }

   // cout<<"pair= "<<pair <<" single= " <<sg <<" unique_twice= " <<unique_twice<<endl;

   ll maxLenPalds = getNumMaxLenPalds(pair,sg,v);

   return maxLenPalds;
}

int main() {
    string s;
    cin >> s;
    initialize(s);
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int l;
        int r;
        cin >> l >> r;
        int result = answerQuery(l, r);
        cout << result << endl;
    }
    return 0;
}
