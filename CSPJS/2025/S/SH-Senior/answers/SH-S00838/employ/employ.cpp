#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define repn(i,n) for(int i=0;i<(n);++i)
#define fir first
#define sec second

constexpr int N = 505, mod = 998244353;

int n,m;
char s[N];
int c[N];

int dp[2][N][N];
int fac[N];

void Add(int &x,int y){if((x+=y)>=mod)x-=mod;} 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m,m=n-m;
	rep(i,1,n)cin>>s[i];
	rep(i,1,n){int x;cin>>x,++c[x];}
	rep(i,1,n)c[i]+=c[i-1];
	dp[0][0][0]=1;
	rep(i,1,n){
		int t=i&1;
		memset(dp[t],0,sizeof(dp[t]));
		if(s[i]=='0'){
			rep(j,0,i-1)rep(k,0,i-1)dp[t][j+1][k]=dp[t^1][j][k];
		}else{
			rep(j,0,i-1)rep(k,0,i-1){
				Add(dp[t][j+1][k+1],(ll)dp[t^1][j][k]*max(c[j]-k,0)%mod);
				Add(dp[t][j][k+1],mod-(ll)dp[t^1][j][k]*max(c[j]-k,0)%mod);
				Add(dp[t][j][k],dp[t^1][j][k]);
			}
		}
	}
	fac[0]=1;rep(i,1,n)fac[i]=(ll)fac[i-1]*i%mod;
	int ans=0;
	rep(i,0,m)rep(j,0,n)Add(ans,(ll)dp[n&1][i][j]*fac[n-j]%mod);
	cout<<ans<<'\n'; 
}
// Really?
