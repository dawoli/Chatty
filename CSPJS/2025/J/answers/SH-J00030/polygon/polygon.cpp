#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=5005,mod=998244353;
int n,a[N];
ll ans=0;
ll dp[2][N<<1][4][2];
void dfs(int id,int cnt,int maxx,int sum){
	if(cnt>=3 and sum>maxx*2){
		ans=(ans+1)%mod;
	}
	for(int i=id+1;i<=n;i++){
		dfs(i,cnt+1,max(maxx,a[i]),sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxV=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxV=max(maxV,a[i]);
	}
	if(n<=20){
		dfs(0,0,0,0);
		cout<<ans;
	}else if(maxV==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans<<=1;
			ans%=mod;
		}
		ans-=n*(n-1)/2+n+1;
		cout<<(ans+mod)%mod;
	}else{
		sort(a+1,a+n+1);
		dp[0][0][0][0]=1,dp[1][0][0][0]=1;
		int u=1;
		for(int i=1;i<=n;i++){
			int V=1e4+1;
			for(int k=0;k<=V;k++){
				dp[u][k][1][0]=(dp[u^1][k][1][0]+dp[u^1][k][1][1])%mod;
				dp[u][k][2][0]=(dp[u^1][k][2][0]+dp[u^1][k][2][1])%mod;
				dp[u][k][3][0]=(dp[u^1][k][3][0]+dp[u^1][k][3][1])%mod;
				dp[u][k][1][1]=0,dp[u][k][2][1]=0,dp[u][k][3][1]=0;
			}
			for(int k=V;k>=V-a[i];k--){
				dp[u][V][3][1]+=((dp[u^1][k][2][0]+dp[u^1][k][2][1])%mod+(dp[u^1][k][3][0]+dp[u^1][k][3][1])%mod)%mod; 
				dp[u][V][3][1]%=mod;
			}
			for(int k=V-1;k>=a[i];k--){
				dp[u][k][3][1]=((dp[u^1][k-a[i]][2][0]+dp[u^1][k-a[i]][2][1])%mod+(dp[u^1][k-a[i]][3][1]+dp[u^1][k-a[i]][3][0])%mod)%mod;
				dp[u][k][2][1]=(dp[u^1][k-a[i]][1][0]+dp[u^1][k-a[i]][1][1])%mod;
				dp[u][k][1][1]=dp[u^1][k-a[i]][0][0];
			}
			for(int k=a[i]*2+1;k<=V;k++){
				ans+=dp[u][k][3][1];
				ans%=mod;
			}
			u^=1; 
		}
		cout<<ans;
	}
	return 0;
}
