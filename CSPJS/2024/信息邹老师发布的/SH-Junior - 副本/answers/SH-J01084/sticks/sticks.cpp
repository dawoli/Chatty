#include<bits/stdc++.h>
using namespace std;

int sticks[11]={6,2,5,5,4,5,6,3,7,6};
int tstk[21]={-1,1,7,4,2,6,8,10,24,22,20,28,68,688,108,188,228,208,608,688};
int dp[5000];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int num;cin>>num;
		if(num%7==0){
			for(int i=0;i<num/7;i++){
			cout<<8;
			}
		}else{
			if(num<20){
				cout<<tstk[num-1];
			}else{
				cout<<-1;
			}
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
	
}
