#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1011,inf=1e18;
int T,n,m,ans;
int st[10]={6,2,5,5,4,5,6,3,7,6};
int dp[N];//dp 处理到第 i 位 ，用掉 j 根木棍 
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=inf;
		for(int j=1;j<=n;j++){
			dp[j]=inf;
		}
		for(int j=0;j<=n;j++){
			for(int k=0;k<10;k++){
				if(k==0&&dp[j]==0) continue;
				if(j+st[k]<=n&&dp[j]!=inf){
					dp[j+st[k]]=min(dp[j+st[k]],dp[j]*10+k);
				}
			}
		}
		for(int i=1;i<=n/2;i++) ans=min(ans,dp[n]);
		if(ans==inf) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
//我永远喜欢珂朵莉
/*

*/ 
