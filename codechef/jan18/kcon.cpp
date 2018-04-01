// C++ program to print largest contiguous array sum
#include<iostream>
#include<climits>
#define endl '\n'
typedef long long ll;

using namespace std;
 


ll maxSubArraySumk(ll a[], ll size,ll k)
{
    ll max_so_far = INT_MIN, max_ending_here = 0;

    for (ll i = 0; i < k*size; i++)
    {
        max_ending_here = max_ending_here + a[i%size];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

ll arraySum(ll* a,ll size)
{
    ll sum =0;

    for (ll i = 0; i < size; ++i)
    {
        sum +=a[i];
    }

    return sum;
}

ll maxLeftSum(ll* a,ll size)
{
    ll sum = 0;
    ll maxSum = INT_MIN;
    for (int i = 0; i < size; ++i)
    {
        sum = sum + a[i];
        maxSum = max(maxSum,sum);

    }

    return maxSum;
}

ll maxRightSum(ll* a,ll size)
{
    ll sum =0;
    ll maxSum = INT_MIN;
    for(int i=size-1;i>=0;i--)
    {
        sum = sum + a[i];
        maxSum = max(maxSum,sum);
    }
    return maxSum;
}


 
/*Driver program to test maxSubArraySum*/
int main()
{
    int t;
    cin>>t;

    for (int cases = 0; cases < t; ++cases)
    {
        ll n,k;
        cin>>n >>k;
        ll a[n];
        for (int i = 0; i < n; ++i)
            cin>>a[i];

        
        ll maxarrsum = INT_MIN;

        maxarrsum = maxSubArraySumk(a,n,1);

        if (k>=2)
        {
            ll sum3 = maxSubArraySumk(a,n,2);
            maxarrsum = max(maxarrsum,sum3);
        }
        if (k>=3)
        {
            ll leftSum  = maxLeftSum(a,n);
            ll rightSum = maxRightSum(a,n);
            ll arrSum   = arraySum(a,n);
            // cout<<"leftSum: " <<leftSum <<endl;
            // cout<<"rightSum: "<<rightSum <<endl;
            // cout<<"arrSum: "<<arrSum <<endl;

            if (arrSum>0)
            {
                arrSum = arrSum*(k-2);
            }

            ll sum = (rightSum + arrSum + leftSum); 
            // cout<<"sum: "<<sum <<endl;
            maxarrsum = max(maxarrsum,sum);
        }


        cout<<maxarrsum <<endl;
       
        
    }
    return 0;
}