#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao=1e6+10,mod=998244353;
ll n,m,ans,a[biao],vis[biao],c[biao],b[biao];

bool judge(){
	ll cnt=0,tot=0;
	for(ll i=1;i<=n;i++){
		if(!b[i] || c[a[i]]<=cnt) cnt++;
		else tot++;
	}
	if(tot>=m) ans=(ans+1)%mod;
//	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<'\n';
//	cout<<cnt<<" "<<tot<<'\n'; 
}

void dfs(ll node){
	if(node==n+1){
		judge();
		return;
	}
	
	for(ll i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1,a[node]=i;
		dfs(node+1);
		vis[i]=a[node]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		char c;
		cin>>c;
		b[i]=c-'0';
	}
	for(ll i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	
	return 0;
}
