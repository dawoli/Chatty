#include<bits/stdc++.h>
using namespace std;
int t,a[25]={-1,-1,1,7,4,2,0,8,10,18,22,20,28,68,88,108,188,228,208,288,688};
unsigned long long dp[100005];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==6){
			cout<<6;
			cout<<endl;
			continue;
		}
		if(n<=20){
			cout<<a[n]<<endl;
			continue;
		} 
		if(n%7==0){
			while(n){
				cout<<8;
				n-=7;
			}
			cout<<endl;
			continue;
		}
		if(n%7==1) {
			cout<<"10";
			while(n>=14){
				cout<<8;
				n-=7;
			}
			cout<<endl;
			continue;
		}
		for(int i=1;i<=20;i++) dp[i]=a[i];
		for(int i=21;i<=n;i++) {
			int mod=i%7;
			if(mod==0||mod==1){
				dp[i]=dp[i-7]*10+8;
			}
			if(mod==2){
				long long sum=dp[i-2],cnt=1;
				while(sum){
					sum/=10;
					cnt*=10;
				}
				dp[i]=dp[i-2]+cnt;
			}
			if(mod==3||mod==4||mod==5){
				long long sum=dp[i-5],cnt=2;
				while(sum){
					sum/=10;
					cnt*=10;
				}
				dp[i]=dp[i-5]+cnt;
			}
			if(mod==6){
				long long sum=dp[i-6],cnt=6;
				while(sum){
					sum/=10;
					cnt*=10;
				}
				dp[i]=dp[i-6]+cnt;
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
} 
