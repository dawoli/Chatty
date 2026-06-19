#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
	ll u,v,w;
};
ll n,m,k,ans,cnt;
edge g[1100009];
vector<int> to[10019],len[10019];
ll c[19][10009],d[19];
ll fa[10019];
bool cmp(const edge&a,const edge&b){
	return a.w<b.w;
}
ll root(ll u){
	if(fa[u]==u){
		return u;
	}
	return root(fa[u]);
}
void solve1(){
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i][0];
		for(ll j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]==0){
				d[++cnt]=j;
			}
		}
		for(ll j=1;j<=n;j++){
			if(d[cnt]==j){
				continue;
			}
			g[++m]=(edge){d[cnt],j,c[i][j]};
		}
	}
	sort(g+1,g+1+m,cmp);
	for(ll i=1;i<=n;i++){
		fa[i]=i;
	}
	for(ll i=1;i<=m;i++){
		ll p=g[i].u,q=g[i].v;
		ll a=root(p);
		ll b=root(q);
		if(a==b){
			continue;
		}
		fa[a]=b;
		ans+=g[i].w;
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	cout<<ans;
	return 0;
}
