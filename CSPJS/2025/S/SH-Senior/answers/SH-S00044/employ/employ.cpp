#include<bits/stdc++.h>
using namespace std;
const int maxn=503,mod=998244353;
char s[maxn];
int n,m,dp[maxn][maxn][maxn],ans[maxn],nums[maxn],out,sum[maxn];
bool vis[maxn];
void dfs(int c){
	if(c==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1' && i-1-cnt<nums[ans[i]]){
				cnt++;
			}
		}
		if(cnt>=m)out++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			ans[c]=i;
			dfs(c+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool flag=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		sum[i]=sum[i-1]+s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>nums[i];
		if(nums[i]!=1)flag=false;
	}
	sort(nums+1,nums+n+1);
	if(n>10){
		if(sum[n]<m){
			cout<<"0";
			return 0;
		}
		if(flag){
			if(s[1]=='0')cout<<"0";
			else if(m>1)cout<<"0";
			else cout<<n;
			return 0;
		}
		if(s[1]=='0'){
			for(int i=1;i<=n;i++)dp[1][0][i]=i;
		}else{
			for(int i=1;i<=n;i++){
				dp[1][1][i]=i;
			}
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=sum[i];j++){
				int p=n;
				for(int k=i;k<=n;k++){
					dp[i][j][k]=dp[i-1][j][k];
					if(s[i]=='1' && i-1-j<nums[k]){
						p=min(p,k);
						dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-1][k-1]*max(k-p,1)%mod)%mod;
					}
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++){
			ans=(ans+dp[n][i][n])%mod;
		}
		cout<<ans;
	}else{
		dfs(1);
		cout<<out;
	}
	return 0;
}
