#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=509;
const int mod=998244353;
int n,m,fac[N],c[N][N],f[N][N][2],g[N][N][2],cnt[N],num[N],ans;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<=n;i++) c[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	s.insert(0,"#");
	for(int i=1;i<=n;i++){
		if(s[i]=='1') num[i]=num[i-1]+1;
		else num[i]=num[i-1];
	}
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}
	for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
	f[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=num[i];j++)
			for(int k=0;k<=i;k++){
				int num=cnt[i-j]-(i>j?cnt[i-j-1]:0);
				int x=s[i+1]-'0';
				for(int q=0;q<=min(k,num);q++){
					int val=fac[q]*c[k][q]%mod*c[num][q]%mod;
					g[j+x][k-q+1][x]=(g[j+x][k-q+1][x]+f[j][k][0]*val%mod)%mod;
					g[j][k-q][0]=(g[j][k-q][0]+f[j][k][0]*val%mod*max(cnt[i-j]-(i-k+q),0ll)%mod)%mod;
				} 
				g[j+x][k+1][x]=(g[j+x][k+1][x]+f[j][k][1])%mod;
				g[j][k][0]=(g[j][k][0]+f[j][k][1]*max(cnt[i-j]-(i-k),0ll)%mod)%mod;
			}
		//if(i==2) cout<<g[2][1][1]<<'\n';
		for(int j=0;j<=num[i+1];j++)
			for(int k=0;k<=i+1;k++)
				for(int z=0;z<=1;z++)
					f[j][k][z]=g[j][k][z],g[j][k][z]=0;
	}
	for(int i=m;i<=n;i++)
		for(int j=0;j<=1;j++)
			if(n-1-(i-j)>=0) ans=(ans+f[i][n-cnt[n-1-(i-j)]][j]*fac[n-cnt[n-1-(i-j)]]%mod)%mod;//cout<<f[i][n-cnt[n-1-(i-j)]][j]<<'\n';
	cout<<ans<<'\n';
	return 0;
}
