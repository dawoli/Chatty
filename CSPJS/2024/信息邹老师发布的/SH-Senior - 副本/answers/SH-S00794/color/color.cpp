#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
ll n,a[N],f[N],s[N];
ll dp[2009][2009];
ll dp2[200009][202]; 
ll calc(ll l,ll r){
	return s[r-1]-s[l-1];
}
ll g[N],g2[N];
void solveBF(){
	//dp[i][j] 表示考虑到第 i 个，上个红的是第 j 个，最大值。
	ll ans=0;
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=i;j++) dp[i][j]=0;
		g[i]=0; g2[i]=0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<i-1;j++){
			dp[i][j]=calc(j+1,i-1)+g[j+1]+(a[i]==a[j])*a[i];
			g[i]=max(g[i],dp[i][j]);
		}
		dp[i][i-1]=(a[i]==a[i-1])*a[i];
		if(i>1) dp[i][i-1]+=g2[i-2];
		g2[i]=max(g[i],dp[i][i-1]);
	}
	ans=0;
	for(ll i=0;i<=n;i++){
		ans=max(ans,dp[n][i]);
	}
	cout<<ans<<endl;
}
void solveGL(){	//dp[i][j] 表示考虑到第 i 个，上个红的是第 j 个，最大值。
	ll ans=0;
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=200;j++) dp2[i][j]=0;
		g[i]=0; g2[i]=0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=max(0ll,i-200);j<i-1;j++){
			dp2[i][i-j]=calc(j+1,i-1)+g[j+1]+(a[i]==a[j])*a[i];
			g[i]=max(g[i],dp2[i][i-j]);
		}
		dp2[i][1]=(a[i]==a[i-1])*a[i];
		if(i>1) dp2[i][1]+=g2[i-2];
		g2[i]=max(g[i],dp2[i][1]);
	}
	ans=0;
	for(ll i=max(0ll,n-200);i<=n;i++){
		ans=max(ans,dp2[n][n-i]);
	}
	cout<<ans<<endl;
}
void solve(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		f[i-1]=(a[i-1]==a[i])*a[i-1];
		s[i-1]=s[i-2]+f[i-1];
//		cout<<f[i]<<" "<<s[i]<<endl;
	} 
	ll b=*max_element(a+1,a+1+n);
	if(n<=2000) solveBF();
	else solveGL();
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
