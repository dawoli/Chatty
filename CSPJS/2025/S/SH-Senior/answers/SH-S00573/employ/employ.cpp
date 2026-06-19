#include<bits/stdc++.h>
#define int long long
#define N 505
#define MOD 998244353
using namespace std;
int n,m,c[N],a[N],pc[N],cnt[N],s[N],C[N][N],f[N][N][N],fc[N];
int F[19][(1<<18)][19];
void adt(int &x,int y){
	if((x+=y)>=MOD){
		x-=MOD;
	}
}
void solve(){
	cin>>n>>m;
	char ch;
	for(int i=1;i<=n;i++){
		cin>>ch;
		a[i]=ch-'0';
	}
	for(int i=1,ccc;i<=n;i++){
		cin>>ccc;
		++cnt[ccc];
	}
	s[0]=cnt[0];
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+cnt[i];
		pc[i]=pc[i-1]+a[i];
	}
	f[0][0][0]=1;
	for(int i=0;i<n;i++){for(int j=0;j<=pc[i];j++){for(int t=0;t<=j;t++){
		if(!f[i][j][t])continue;
		int ff=f[i][j][t];
		if(a[i+1]==0){
			for(int x=0;x<=j-t;x++){
				adt(f[i+1][j][t+x],ff*C[cnt[i-j+1]][x]%MOD*fc[x]%MOD);
			}
		}
		else{
			adt(f[i+1][j+1][t],ff);
			for(int x=0;x<=j-t;x++){
				adt(f[i+1][j][t+x],ff*(s[i-j]-t-(pc[i]-j))%MOD*C[cnt[i-j+1]][x]%MOD*fc[x]%MOD);
			}
		}
	}}}
	int ans=0;
	for(int j=m;j<=n;j++){
		for(int t=0;t<=j;t++){
			adt(ans,f[n][j][t]*C[s[n]-s[n-j]][j-t]%MOD*fc[j-t]%MOD);
		}
	}
	cout<<ans*fc[n-pc[n]]%MOD<<'\n';
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	fc[0]=1;
	for(int i=0;i<N;C[i][i]=C[i][0]=1,i++){
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
		}
	}
	for(int i=1;i<N;i++){
		fc[i]=fc[i-1]*i%MOD;
	}
	int T=1;
	// cin>>T;
	while(T--){
		// solve();
		// return 0;
	}
	
	cin>>n>>m;
	char ch;
	for(int i=1;i<=n;i++){
		cin>>ch;
		a[i]=ch-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		++cnt[c[i]];
	}
	s[0]=cnt[0];
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+cnt[i];
		pc[i]=pc[i-1]+a[i];
	}
	F[0][0][0]=1;
	for(int s=0;s<(1<<n);s++){
		int i=__builtin_popcount(s);
		for(int k=0;k<=i;k++){
			// cerr<<i<<' '<<s<<' '<<i<<' '<<F[i][s][k]<<'\n';
			for(int j=1;j<=n;j++){
				if(((s>>(j-1))&1)==0){
					if(a[i+1]==1&&c[j]>(i-k)){
						adt(F[i+1][s|(1<<(j-1))][k+1],F[i][s][k]);
					}
					else{
						adt(F[i+1][s|(1<<(j-1))][k],F[i][s][k]);
					}
				}
			}
		}
	}
	int ans=0;
	for(int k=m;k<=n;k++){
		adt(ans,F[n][(1<<n)-1][k]);
	}
	cout<<ans<<'\n';
	return 0;
}