#include<iostream>
#define endl '\n'
#define long long ll
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int cases=0;cases<t;cases++)
    {
        
        int n;
        cin>>n;
        
        int map[100][7]={{0}},temp;
        int score[100]={0};
        
        for(int i=0;i<n;i++)
        {
            int no_of_cookies;
            cin>>no_of_cookies;
            score[i]+=no_of_cookies;
            
            for (int j = 0; j < no_of_cookies; j += 1 )
            {
                cin>>temp;
                map[i][temp]++;
                
            }
        }
        
        int type;
        for (int i = 0; i < n; i += 1 )
        {
            //pack cokies in the box
            while (map_size(map[i],6) >=4) {
                
                type = map_size(map[i],6);
                if(type==6)
                {
                    score[i]+=4;
                    update(map[i]);
                }else if(type==5) {
                    score[i]+=2;
                    update(map[i]);
                }
                else if(type==4) {
                    score[i]+=1;
                    update(map[i]);
                }
                
            }
            
            
            
        }
        int max=0,flag=1;
        
        for (int i = 0; i < n; i += 1 )
        {
            
            if(flag==0) break;
            
            if(score[i]>score[max])
                max=i;
            //handle all tie cases
            for (int j = 0; j < n; j += 1 )
            {
                if(score[i]==score[j] && i!=j)
                {   cout<<"tie" <<endl;
                    flag=0;
                    break;
                }
            }
        }
        
        if(flag==1)
        {
            if(max==0) cout<<"chef" <<endl;
            else cout<<(max+1) <<endl;
            
            
        }
        
    }
    return 0;
}
