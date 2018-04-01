#include<iostream>
using namespace std;

int main(){

	int t;
	cin>>t;

	for(int i=0;i<t;i++)
	{
	int n;
	string region;
	cin>>n >>region;
	
	string activity[100];
	int score=0;
	unsigned int rank=-1,severity=-1;
	
        for(int j=0;j<n;j++)
	{
		cin>>activity[j];
		if(activity[j].compare("CONTEST_WON")==0)
		{
			cin>>rank;
			if(rank>20)
			score+= 300;
			else{
				score+=300+20-rank;
			}

		}
		else if(activity[j].compare("TOP_CONTRIBUTOR")==0){
                     score+=300;
		}else if(activity[j].compare("BUG_FOUND")==0)
		{
			cin>>severity;
			score+=severity;

		}
		else
			score+=50;

	}

	
			
	if(region=="INDIAN")
	{
		cout<< score/200 <<endl;

	}else
	{
		cout<<score/400 <<endl;
		
	}


	}


	return 0;
}
