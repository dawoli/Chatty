#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll c=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		c=(c<<1ll)+(c<<3ll)+(ch^48ll);
		ch=getchar();
	}
	return c*f;
}
inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
const ll N=20009;
const ll M=2000009;
ll fa[N],sz[N];
inline ll find(ll x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline void unite(ll u,ll v){
	u=find(u),v=find(v);
	if(u==v) return;
	if(sz[u]<sz[v]) swap(u,v);
	fa[v]=u,sz[u]+=sz[v];
}
struct edge{
	ll u,v,w;
	bool operator<(const edge&x)const{
		return w<x.w;
	}
} ee[M],e[M];
ll a[12][N],c[12];
ll vst[12];
ll nE;
ll n,m,k;
vector<ll> ori_e;
inline ll kruskal(ll tot,bool tag){
	for(ll i=1;i<=n+k;i++){
		fa[i]=i,sz[i]=1;
	}
	ll cnt=0,res=0;
	for(ll i=1;i<=nE;i++){
		ll u=e[i].u,v=e[i].v,w=e[i].w;
		if(v>n){
			if(!vst[v-n]) continue;
		}
		u=find(u),v=find(v);
		if(u==v) continue;
		unite(u,v);
		cnt++;
		res+=w;
		if(tag){
			ori_e.emplace_back(i);
		}
		if(cnt==tot-1){
			break;
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(ll i=1;i<=m;i++){
		ll u=read(),v=read(),w=read();
		e[i]=(edge){u,v,w};
	}
	sort(e+1,e+m+1);
	nE=m;
	kruskal(n,1);
	nE=0;
	for(ll i:ori_e){
		ee[++nE]=e[i];
	}
	for(ll i=1;i<=m;i++) e[i]=(edge){0,0,0};
	for(ll i=1;i<=nE;i++){
		e[i]=ee[i];
	}
	
	for(ll j=1;j<=k;j++){
		c[j]=read();
		for(ll i=1;i<=n;i++){
			a[j][i]=read();
			e[++nE]={i,n+j,a[j][i]};
		}
	}
	sort(e+1,e+nE+1);
	ll ans=1e18;
	for(ll s=0;s<(1<<k);s++){
		ll res=0,tot=n;
		for(ll i=1;i<=k;i++){
			if(s&(1ll<<(i-1))){
				res+=c[i];
				tot++;
				vst[i]=1;
			}
		}
		res+=kruskal(tot,0);
		ans=min(ans,res);
		for(ll i=1;i<=k;i++){
			if(s&(1ll<<(i-1))){
				vst[i]=0;
			}
		}
	}
	write(ans),puts("");
	return 0;
}

