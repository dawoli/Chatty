#include<bits/stdc++.h>
using namespace std;
const int N=18+5;
const int M=(1<<18)+5;
int n,m;
int s[N],c[N];
int vis[N];
long long dp[M][N],mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char cs;
	for(int i=1;i<=n;i++){
		cin>>cs;
		if(cs=='0')	s[i]=0;
		else	s[i]=1;
	}	
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dp[0][0]=1;
	for(int i=1;i<(1<<n);i++){
		int tot=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1)))	vis[j]=1,tot++;
			else	vis[j]=0;
		}
		for(int j=0;j<=n;j++){
			for(int z=1;z<=n;z++){
				int x=0;
				if(vis[z]==0)	continue;
				x=i-(1<<(z-1));
				if(j>=1 && tot-j<c[z] && s[tot]==1)	dp[i][j]+=dp[x][j-1];
				if(tot-1-j>=c[z] || s[tot]==0) dp[i][j]+=dp[x][j];
				dp[i][j]%=mod;
			}
		}
	}
	long long ans=0;
	for(int i=m;i<=n;i++){
		ans+=dp[(1<<n)-1][i];
		ans%=mod;
	}
	cout<<(ans+mod)%mod;
	return 0;
}
