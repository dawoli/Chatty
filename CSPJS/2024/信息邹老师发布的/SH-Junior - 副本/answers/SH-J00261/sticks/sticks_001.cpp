#include<bits/stdc++.h>
using namespace std;
int t;
int a[55],stick[10010];
int dp[21]={
	0,
	-1,1,7,4,2,6,8,10,18,22,
	20,28,68,88,108,188,288,208,608,808 
	
	
};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		if(n%7==0){
			for(int i=1;i<=n/7;i++)
				cout<<8;
		}
		else if(n%7==1){
			cout<<10;
			for(int i=1;i<=(n-8)/7;i++)
				cout<<8; 
		}
		else if(n<=20)
			cout<<dp[n];
		else cout<<"Man,what can I say.";
		cout<<endl;
	}
	return 0;
}
