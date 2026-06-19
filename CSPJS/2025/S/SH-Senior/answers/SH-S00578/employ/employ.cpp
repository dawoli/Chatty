#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=505,mod=998244353;
ll n,m,a[N],c[N],suma[N];
string s;
bool vst[13*12*1024];
ll mem[13*12*1024];
ll dfs(ll i,ll j,ll x){
	if(i>n){
		if(j>=m)return 1;
		return 0;
	}
	if(suma[n]-suma[i-1]+j<m)return 0;
	ll nwid=i*11*1024+j*1024+x;
	if(vst[nwid])return mem[nwid];
	ll ret=0;
	for(ll k=1;k<=n;++k)if(((1<<(k-1))&x)==0){
		if(i-1-j<c[k]&&a[i]>0)ret+=dfs(i+1,j+1,(x|(1<<(k-1))));
		else ret+=dfs(i+1,j,(x|(1<<(k-1))));
		ret%=mod;
	}
	ret=(ret%mod+mod)%mod;
	vst[nwid]=1;
	mem[nwid]=ret;
	return ret;
}
void solveBF(){
	ll ans=dfs(1,0,0);
	ans=(ans%mod+mod)%mod;
	cout<<ans<<"\n";
}
ll f[2][20][(1<<18)+1];
ll cntbit(ll x){
	ll ret=0;
	while(x){
		if(x&1)ret++;
		x>>=1;
	}
	return ret;
}
void solve18(){
	for(ll j=m;j<=n;++j)f[0][j][(1<<n)-1]=1;
	for(ll i=n;i>=1;--i){
		for(ll j=0;j<=n;++j){
			for(ll x=0;x<(1<<n);++x){
				f[1][j][x]=f[0][j][x];
				f[0][j][x]=0;
			}
		}
		for(ll x=0;x<(1<<n);++x)if(cntbit(x)==i-1)for(ll j=0;j<i;++j){
			for(ll k=1;k<=n;++k)if(((1<<(k-1))&x)==0){
				if(i-1-j<c[k]&&a[i]>0)f[0][j][x]+=f[1][j+1][x|(1<<(k-1))];
				else f[0][j][x]+=f[1][j][x|(1<<(k-1))];
				f[0][j][x]%=mod;
			}
		}
	}
	cout<<f[0][0][0]<<"\n";
}
ll g[N],gm1[N][N];
bool vstm1[N][N];
ll solm1(ll i){
	if(i>n)return 1;
	ll ret=0;
	if(a[i]){
		for(ll k=0;k<i;++k){
			if(g[i]){
				g[i]--;
				ret+=solm1(i+1);
				g[i]++;
			}
		}
	}
	else{
		for(ll k=0;k<=n;++k){
			if(g[i]){
				g[i]--;
				ret+=solm1(i+1);
				g[i]++;
			}
		}
	}
	return ret;
}
void solvem1(){
	ll ans=1;
	for(ll i=2;i<=n;++i){
		ans=(ans*i)%mod;
	}
	for(ll i=1;i<=n;++i){
		g[c[i]]++;
	}
	ans-=solm1(1);
	ans=(ans%mod+mod)%mod;
	cout<<ans<<"\n";
}
void solvemn(){
	for(ll i=1;i<=n;++i)if(a[i]==0||c[i]==0){
		cout<<"0\n";
		return;
	}
	ll ans=1;
	for(ll i=1;i<=n;++i){
		ans=(ans*i)%mod;
	}
	cout<<ans<<"\n";
}
void solveA(){
	sort(c+1,c+1+n);
	ll ans=1;
	for(ll i=2;i<=n;++i){
		ans=(ans*i)%mod;
	}
	for(ll i=1;i<=n;++i){
		g[c[i]]++;
	}
	if(g[0]>0){
		if(n-g[0]<m)ans=0;
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans<<"\n";
}
void solve(){
	;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool ifA=1;
	suma[0]=0;
	for(ll i=1;i<=n;++i){
		a[i]=s[i-1]-'0';
		suma[i]=suma[i-1]+a[i];
		if(a[i]!=1)ifA=0;
	}
	for(ll i=1;i<=n;++i){
		cin>>c[i];
	}
	if(n<=10){
		solveBF();
	}
	else if(n<=18){
		solve18();
	}
	else if(m==n){
		solvemn();
	}
	else if(ifA){
		solveA();
	}
	else if(m==1){
		solvem1();
	}
	else{
		solve();
	}
	return 0;
}
