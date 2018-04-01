#include <iostream>
#include<limits.h>
#include<math.h>
#include<algorithm>
using namespace std;

int* tree;
int* lazytree;
int prime[1000001] = {0};
int range=1000001;

int LeastPrimeDivisor(int n);
int maxm(int num1,int num2)
{
    int result =num1>num2?num1:num2;
    return result;
}

int sizeoftree(int n)
{
    
    int height = ceil(log2(n));
        //cout<<"Height= " <<height <<endl;
    return (pow(2,height)*2-1);
    
}
int maxquery(int *tree,int qlow,int qhigh,int low,int high,int pos)
{
        //total overlap
    if (qlow <=low && qhigh >=high)
        {
        return tree[pos];
        }
    
        //if no overlap
    if (qlow > high || low > qhigh) {
        return INT_MIN;
    }
    
    
    int mid = (low+high)/2;
    
    return max(maxquery(tree,qlow,qhigh,low,mid,2*pos+1),maxquery(tree,qlow,qhigh,mid+1,high,2*pos+2));
    
    
}

void constructSegTree(int *input,int low,int high,int *tree, int pos)
{
    
    
    if (low==high) {
        tree[pos] = input[low];
        return ;
    }
    
    constructSegTree(input,low,(low+high)/2,tree,2*pos+1); //left child
    constructSegTree(input,(low+high)/2+1,high,tree,2*pos+2); //right child
    if (LeastPrimeDivisor(tree[2*pos+1]) > LeastPrimeDivisor(tree[2*pos+2])) {
        tree[pos] = tree[2*pos+1];
    }else
        tree[pos]= tree[2*pos+2]
   
    
}

void constructLeastPrimeDivisorList()
{
    for (int i=2;i<=range;i++)
        {
        if (prime[i]==0)
            {
            
            for (int j=2*i; j<range; j+=i)
                {
                if (prime[j]==0)
                    prime[j]=i;
                }
            }
        }
}


void update(int *input,int qlow,int qhigh,int low,int high,int pos)
{
        //if any pending update is there
     if(lazytree[pos]!=1)
        {
        tree[pos]/ = lazytree[pos];
        }
        
            //  if leaf node is not encounter
        if (low!=high)
            {
            int a=tree[2*pos+1];
            int b= tree[2*pos+2];
            
            a/=lazytree[2*pos+1];
            b/=lazytree[2*pos+2];
            
            lazytree[2*pos+1]*=LeastPrimeDivisor(a);
            lazytree[2*pos+2]*=LeastPrimeDivisor(b);
            }
        
        
}
    
    
    
            //if complete overlap
    if (qlow <=low && qhigh >=high && low!=high) {
        
        int a = tree[2*pos+1];
        int b = tree[2*pos+2];
        
        a/=lazytree[2*pos+1];
        b/=lazytree[2*pos+2];
        
        if(LeastPrimeDivisor(a)>LeastPrimeDivisor(b))
            tree[pos]= a;
        else tree[pos]=b;
        
        lazytree[2*pos+1]*=LeastPrimeDivisor(a);
        lazytree[2*pos+2]*=LeastPrimeDivisor(b);
        return ;
    }
    
    
        //if no overlap
    if (qlow > high || low > qhigh) {
        return ;
    }

    //if partial overlap
    int mid = (low+high)/2;
    update(input,tree,qlow,qhigh,low,mid,2*pos+1);
    update(input,tree,qlow,qhigh,mid+1,high,2*pos+2);
    
    tree[pos]= max(tree[2*pos+1],tree[2*pos+2]);
}

int get(int *a,int n,int L,int R)
{
        return maxquery(tree,L-1,R-1,0,n-1,0);
    
}


int main()
{
    constructLeastPrimeDivisorList();
    
    
    int test;
    cin>>test;
    for (int cases=0; cases<test; cases++) {
        int n,L,R,type,no_of_op;
        cin>>n >>no_of_op;
        
        int a[100000];
        
                       //input the array
        for (int i=0; i<n; i++)
            cin>>a[i];
        
        
            //create a segment tree
        int size = sizeoftree(n);
        tree = new int[size];
        constructSegTree(a,0,n-1,tree,0);
        
            //create a lazy tree
        lazytree = new int[size];
        memset(lazytree,1,size);
        
        
        for (int i=0; i<no_of_op; i++)
            {
            cin>>type;
            cin>>L >>R;
            
            if (type==0)
                update(a,tree,L-1,R-1,0,n-1,0);
            
            else{
                int result = get(a,n,L,R);
                cout<<result <<" ";
            }
            }
        cout<<endl;
    }
    return 0;
}


int LeastPrimeDivisor(int n)
{
    
    if (prime[n]==0) {
        return n;
    } else {
        return prime[n];
    }
    
}

