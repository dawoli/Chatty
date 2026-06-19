#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=105,mod=998244353;

int n,m,c[N],dp[N][N][N],frac[N],inv_frac[N],cnt[N],sum[N];
string s;

int quickpow(int a,int b) {
	int res=1;
	while(b) {
		if(b&1) (res*=a)%=mod;
		(a*=a)%=mod;b>>=1;
	}return res;
}

int C(int n,int m) {
	if(!n) return 1;
	return ((frac[m]*inv_frac[m-n])%mod*inv_frac[n])%mod;
}

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	frac[0]=inv_frac[0]=1;
	for(int i=1;i<=n;i++) frac[i]=(frac[i-1]*i)%mod;
	inv_frac[n]=quickpow(frac[n],mod-2);
	for(int i=n-1;i>=1;i--) inv_frac[i]=(inv_frac[i+1]*(i+1))%mod;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i],cnt[c[i]]++;
	sum[0]=cnt[0];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+cnt[i];
	bool flag=0;
	for(int i=0;i<n;i++) {
		if(s[i]=='0') {flag=1;break;}
	}
		dp[0][0][0]=1;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<=i;j++) {
				if(cnt[i-j]==0) {
					for(int k=0;k<=i;k++) {
						dp[i][j][k+1]=dp[i-1][j][k]*(sum[i-j]-k)%mod;
						if(j!=0) dp[i][j][k]+=dp[i-1][j-1][k]*(n-sum[i-j]-(i-1-k))%mod;
						dp[i][j][k]%=mod;
					}
				}else {
					for(int k=0;k<=i;k++) {
						for(int x=0;x<=min(cnt[i-j],k-1);x++) {
							dp[i][j][k]+=((dp[i-1][j][k-x-1]*(sum[i-j-1]-(k-x-1))%mod*C(x,i-k+x))%mod*C(x,cnt[i-j]))%mod;
							dp[i][j][k]%=mod;
						}
						if(j!=0) (dp[i][j][k]+=dp[i-1][j-1][k]*(n-sum[i-j]-(i-1-k)))%=mod;
						dp[i][j][k]%=mod;
					}
				}
				//for(int k=0;k<=i;k++) cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<'\n'; 
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++) {
			for(int j=0;j<=n;j++) (ans+=max(dp[n][i][j],0ll))%=mod;
		}cout<<ans<<'\n';
	return 0;
}
