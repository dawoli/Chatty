#include<bits/stdc++.h>
#define lb(x) ((x)&(-x))
#define il inline
#define int long long
using namespace std;
const int N=550,mod=998244353;
int n,m;
int c[N];
char ss[N];
int p[N];
int ans;
int pw[N];
int cntz;
//For:8pts
void dfs(int nw,int zt,int nwcnt){
	if(nwcnt>=m){
		ans=(ans+pw[n-nw+1]);
		if(ans>=mod)ans-=mod;
		return;
	}
	if(nw>n){
		return;
	}
	for(int i=1;i<=n;i++){
		if((zt&(1<<(i-1)))!=0){
			p[nw]=i;
			if(nw-1-nwcnt<c[i] && ss[nw]=='1')dfs(nw+1,zt-(1<<(i-1)),nwcnt+1);
			else dfs(nw+1,zt-(1<<(i-1)),nwcnt);
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=505;i++){
		pw[i]=(pw[i-1]*i)%mod;
//		cout<<pw[i]<<'\n';
	}
	cin>>n>>m>>(ss+1);
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cntz++;
	}
	if(n-cntz<m){
		cout<<"0";
		return 0;
	}
	dfs(1,(1<<n)-1,0);
	cout<<ans%mod;
	return 0;
}
