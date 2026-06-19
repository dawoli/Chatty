#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll T,n,k,a[N],s[N];
ll f[N][2],g[N][2];
ll cal(ll l,ll r){
	if(l>r)return 0;
	return s[r]-s[l-1];
}
const ll M=1e6+5;
vector<ll> pos[M];
ll tp[M];
ll mx=0,ans;
bool col[N];
void dfs(ll x){
	if(x==n+1){
		ll lst[2]={0,0};
		ll cur=0;
		for(ll i=1;i<=n;i++){
			if(a[i]==a[lst[col[i]]]){
				cur+=a[i];
			}
			lst[col[i]]=i;
		}
		ans=max(ans,cur);
		return;
	}
	col[x]=0;dfs(x+1);
	col[x]=1;dfs(x+1);
}
void man(){
	cin>>n;
	memset(s,0,sizeof s);
	for(ll i=1;i<=mx;i++)
		pos[i].clear(),tp[i]=0;
	mx=0;ans=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		s[i]=s[i-1]+(a[i]==a[i-1])*a[i];
		pos[a[i]].emplace_back(i);
		tp[i]=pos[a[i]].size()-1;
	}
//	for(ll i=1;i<=n;i++)cout<<s[i]<<' ';puts("");
	if(n<=20){
		dfs(1);
		cout<<ans<<'\n';
		return;
	}
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<i;j++)for(ll k=0;k<2;k++){
			//f[i][k]=f[i-1][k];
			//g[i][k]=g[i-1][k];
			ll cur=f[j][k]+(a[i]==a[j])*a[i]+cal(j+1,i-1)+(a[j+1]==a[g[j][k]])*a[j+1];
//			if(i==7&&j==6){
//				cout<<i<<","<<j<<" : ";
//				cout<<f[j][k]<<" "<<(a[i]==a[j])*a[i]<<" "<<cal(j+1,i-1)<<" "<<cal(j+1,i-1)<<'\n';
//			}
			if(cur>f[i][k]){
				f[i][k]=cur;
				g[i][k]=(j==i-1?g[j][k]:i-1);
			}
			if(f[i][k]==0){
				g[i][k]=i-1;
			}
		}
	}
//	for(ll i=1;i<=n;i++)cout<<f[i][0]<<' ';puts("");
//	for(ll i=1;i<=n;i++)cout<<f[i][1]<<' ';puts("");
//	for(ll i=1;i<=n;i++)cout<<g[i][0]<<' ';puts("");
//	for(ll i=1;i<=n;i++)cout<<g[i][1]<<' ';puts("");
//	for(ll i=1;i<=n;i++,puts(""))for(ll j=0;j<=1;j++)cout<<g[i][j]<<' ';
	cout<<max(f[n][0],f[n][1])<<'\n';
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)man();
	return 0;
}
