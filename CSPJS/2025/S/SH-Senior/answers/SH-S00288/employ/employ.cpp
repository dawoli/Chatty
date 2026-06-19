#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int N=505;
ll f[2][N][N],ch[N][N],fc[N],tx;
int n,m,c[N],s[N],sl[N],cl[N];
#define ck(x) ((tx=x)>=mod?tx-mod:tx)

void solve(){
	cin>>n>>m;char in;int x;
	for(int i=1;i<=n;i++)
		cin>>in,s[i]=(in=='0'),sl[i]=sl[i-1]+s[i];
	fc[0]=1;for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
	for(int i=0;i<=n;i++){ch[i][0]=1;
		for(int j=1;j<=i;j++)ch[i][j]=ck(ch[i-1][j]+ch[i-1][j-1]);
	}
	for(int i=1;i<=n;i++)cin>>x,c[x]++;
	cl[0]=c[0];
	for(int i=1;i<=n;i++)cl[i]=cl[i-1]+c[i];
	f[0][0][0]=1;
	for(int i=1;i<=n;i++){x=i&1;
		for(int j=0;j<=i;j++)
			for(int k=0;k<=i;k++)f[x][j][k]=0;
		for(int j=0;j<i;j++)
			for(int k=0;k<=min(i,(s[i]?n:cl[j]-1));k++)
				f[x][j+1][k+(s[i]^1)]=ck(f[x][j+1][k+(s[i]^1)]+f[x^1][j][k]*(s[i]?1:cl[j]-k)%mod);
		// for(int j=0;j<=i;j++)
		// 	for(int k=0;k<=i;k++)
		// 		cerr<<i<<" "<<j<<" "<<k<<" "<<f[x][j][k]<<"\n";
		for(int j=0;j<=i;j++)
			for(int k=i-sl[i];k>=0;k--)
				for(int l=1;l<=min(c[j],k);l++)
					f[x][j][k]=ck(f[x][j][k]+f[x][j][k-l]*ch[c[j]][l]%mod*ch[i-(k-l+sl[i])][l]%mod*fc[l]%mod);
		if(s[i]==0){
			for(int j=0;j<=i;j++)
				for(int k=0;k<=i;k++)
					f[x][j][k]=ck(f[x][j][k]+f[x^1][j][k]);
		}
		// for(int j=0;j<=i;j++)
		// 	for(int k=0;k<=i;k++)
		// 		cerr<<i<<" "<<j<<" "<<k<<" "<<f[x][j][k]<<"\n";
	}x=n&1;ll ans=0;
	for(int j=0;j<=n-m;j++)
		for(int k=0;k<=n;k++)
			if(f[x][j][k]){
				int l=n-sl[n]-k;
				if(l>cl[n]-cl[j])continue;
				ans=ck(ans+f[x][j][k]*ch[cl[n]-cl[j]][l]%mod*fc[l]%mod);
			}
	cout<<ans*fc[sl[n]]%mod<<"\n";
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	// freopen("err.err","w",stderr);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T=1;while(T--)solve();
}