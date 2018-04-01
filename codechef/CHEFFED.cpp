#include<iostream>
#define endl '\n'
using namespace std;


int digitSum(int num)
{
   int sum=0;
    if (num<10) {
        return num;
    }
   
    
    while (num >0) {
        sum+=num%10;
        num/=10;
    }
    return sum;
    
   

}


int main()
{
	ios::sync_with_stdio(false);
	int n,sum1,sum2,count=0;
	cin>>n;
    if (n%3==0)
    {
        int digits=1;
        
        if (n < 10)  digits=1;
        else  if (n < 100) digits=2*9;
        else if (n < 1000) digits=3*9;
        else if (n < 10000) digits=4*9;
        else if (n < 100000) digits=5*9;
        else if (n < 1000000) digits=6*9;
        else if (n < 10000000) digits=7*9;
        else if (n < 100000000) digits=8*9;
        else if (n < 1000000000) digits=9*9;
        
        
        
        int range = n- digits - digitSum(digits);
        
        
        for(int cases=range;cases<=n;cases++)
        {
            sum1=digitSum(cases);
            sum2=digitSum(sum1);
            
            
            
            if ((cases + sum1 + sum2)== n)
            {
                count++;
            }
            
        }

    }
    
    cout<<count <<endl;
	return 0;
}