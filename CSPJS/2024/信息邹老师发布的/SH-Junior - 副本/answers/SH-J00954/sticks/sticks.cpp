#include <bits/stdc++.h>
using namespace std;
long long t,n,ans;
long long match[]={6,2,5,5,4,5,6,3,7,6};
long long dp[100005];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0x3f,sizeof(dp));
		cin>>n;
		if(n%7==0){
			for(long long i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}else if(n%7==1){
			cout<<10;
			for(long long i=1;i<=n/7-1;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		dp[0]=0;
		for(long long i=2;i<=n;i++){
			for(long long j=0;j<=9;j++){
				if(i<match[j])continue;
				if(dp[i-match[j]]*10+j==0)continue;
				dp[i]=min(dp[i],dp[i-match[j]]*10+j);
			}
		}
		if(dp[n]==4557430888798830399)cout<<-1<<endl;
		else cout<<dp[n]<<endl;
	}
}
