#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
int bst[1000006];
int pre[200005];
int f[200005];
int dp[200005];
int ans;
int ff(int x,int y){
	if(x>=y) return 0;
	return f[y]-f[x];
}
void solve(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) bst[a[i]]=0;
	for(int i=1;i<=n;i++){
		pre[i]=bst[a[i]];
		bst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(a[i]==a[i-1]) f[i]+=a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=0;
		if(pre[i]!=0&&pre[i]!=i-1) dp[i]=max(dp[i],dp[pre[i]+1]+a[i]+ff(pre[i]+1,i-1));
		if(pre[i]!=0&&pre[i]==i-1) dp[i]=max(dp[i],dp[i-1]+a[i]);
		else dp[i]=max(dp[i],dp[i-1]);
	}
	ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
//		cout<<dp[i]<<" ";
	}
//	cout<<endl;
	printf("%lld\n",ans);
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--) solve();
	return 0;
} 
