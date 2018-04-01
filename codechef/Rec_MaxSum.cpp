#include<iostream>
#include<climits>
using namespace std;
int maxsum(int* arr,int n);
int max(int a,int b);
int main()
{
	int arr[]={1,-2,7,4,-5};
	int sum = maxsum(arr,5);
	cout<<sum <<endl;
	return 0;
}
int max(int a,int b)
{
	int max;
	if(a>b)
		max=a;
	else
		 max=b;
	return max;
}

int maxsum(int arr[], int n)
{
  
  if(n==1)
  {
    return arr[0];

  }
   int m=n/2;

  int Left_MMS  = maxsum(arr,m);
  int Right_MMS  = maxsum(arr+m,n-m);
 int left_sum = INT_MIN,right_sum=INT_MIN, sum=0;
 for(int i=m;i<n;i++)
 {
  sum+=arr[i];
  right_sum = max(sum,right_sum);  
  
 }
 sum=0;
 for(int i=(m-1);i>=0;i--)
 {
  sum+=arr[i];
  left_sum=max(sum,left_sum);
 }

int ans=max(Left_MMS,Right_MMS);
return max(ans,left_sum+right_sum);

}