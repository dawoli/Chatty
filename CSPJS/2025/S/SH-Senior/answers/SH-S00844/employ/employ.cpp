#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
std::ifstream fin("employ.in");
std::ofstream fout("employ.out");
using ll=long long;
const ll mod=998244353;
int n,m,c[505];
ll dp[19][19][1<<18];
bool s[505];
/*ll fpow(ll x,ll a){
	if(x==1||a==0) return 1;
	if(x==0||a==1) return x;
	ll res=fpow(x,a/2);
	res*=res;
	res%=mod;
	if(a%2) res*=x;
	return res%mod;
}*/
int popcnt(int x){
	int res=0;
	while(x>0){
		if(x&1) res++;
		x>>=1;
	}
	return res;
}
void solve1(){
	dp[0][0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i;++j){
			for(int s=0;s<(1<<n);++s){
				if(popcnt(s)!=i) continue;
				int t=s,g=s,pl=0;
				while(g>=0){
					if(s[i]==0){
						dp[i][j][s]+=dp[i-1][j-1][g];
						dp[i][j][s]%=mod;
					} 
					else if(c[pl]!=j){
						dp[i][j][s]+=dp[i-1][j-(c[pl]<j)][g];
						dp[i][j][s]%=mod;
					}
					if(g==0) break;
					t+=pl;
					t-=lowbit(g);
					pl=lowbit(g);
					g-=lowbit(g);
				}
			}
		}
	}
	ll ans=0;
	for(int j=m;j<=n;++i){
		ans+=dp[n][j][(1<<n)-1];
		ans%=mod;
	}
	fout<<ans<<std::endl;
}
int main(){
	fin>>n>>m;
	int s1s=0;
	for(int i=1;i<=n;++i){char cc;fin>>cc;s[i]=cc-'0';s1s+=s[i];};
	for(int i=1;i<=n;++i){fin>>c[i];if(c[i]==0) --sls;}
	if(s1s<m){
		fout<<"0\n";
		return 0;
	}
	solve1();
	return 0;
}
