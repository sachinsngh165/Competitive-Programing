#include<iostream>
#include<limits.h>
#include<math.h>
#define endl '\n'
using namespace std;
/*
struct Map{
    int number;
    int occurence = 0;
};
*/

struct SegTree{
    int dominante;
    int freq[100];
};


void merge(SegTree* st,int* a,int low,int high,int pos)
{
    int mid=(low+high)/2;
    int i=mid+1,j=0;
    
   
             while (low < mid) {
                j = low;
                 st[pos].freq[a[j]] += st[2*pos+1].freq[a[j]];
                 low++;

             }
             while (i < high) {
                 j= i;
                 st[pos].freq[a[j]] += st[2*pos+2].freq[a[j]];
                 i++;
                 
                 
             }
             
   
}





void ConstructSegTree(int* a,SegTree* st,int low,int high,int pos)
{
    
    
    if (low==high) {
        st[pos].dominante=a[low];
        st[pos].freq[a[low]]+=1;
        
        return ;
    }
    
    //call left half
    ConstructSegTree(a,st,low,(low+high)/2, 2*pos+1);
    
    //construct right half
    ConstructSegTree(a,st,(low+high)/2+1,high,2*pos+2);
    
    //merg both the halves
    merge(st,a,low,high, pos);
    
    int length = (high-low+1);
    
    //if dominante number is in left
    if (st[pos].freq[st[2*pos+1].dominante] > 0 && st[pos].freq[st[2*pos+1].dominante]>length/2)
             {
        
        st[pos].dominante=st[2*pos+1].dominante;
    }
    //if dominante number is in right
    else if (st[pos].freq[st[2*pos+2].dominante] > 0 && st[pos].freq[st[2*pos+2].dominante]>length/2) {
        
        st[pos].dominante=st[2*pos+2].dominante;
    }
    
    //if no dominante number in left and righ node
    else st[pos].dominante=-1;
    
    
}




int main()
{
	ios::sync_with_stdio(false);
    
    int N,Query;
    cin>>N >>Query;
    
    int a[100000];
   
    
    
    for (int i=0; i<N; i++) {
        cin>>a[i];
    }
    
    
    int height = ceil(log2(N));
    int max_size= 2*pow(2,height)-1;

  
    SegTree st[max_size];
    
    ConstructSegTree(a,st,0,N-1,0);
    
    
    
 	return 0;
}