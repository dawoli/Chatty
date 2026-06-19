#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gc getchar()
#define pc(x) putchar(x)
inline ll gt(){ll r=0;char c=gc;while(c<48||c>57) c=gc;while(c>47&&c<58) r=r*10+(c^48),c=gc;return r;}
inline void ot(ll x){if(x<10) pc(x^48);else ot(x/10),pc((x%10)^48);}
struct Node{ll f,e;inline bool operator<(const Node &other) const{return e>other.e;};};
struct Node2{ll u,v,w;inline bool operator<(const Node2 &other) const{return w>other.w;};};
ll n,m,k,l,t,r,ans,c[15],a[15][10019],pa[10019];
bool o[15];
Node2 d,f[10009];
priority_queue<Node2> w;
vector<Node> g[10019];
priority_queue<Node> q;
bool vst[10019];
inline int find(int x){return x==pa[x]?x:pa[x]=find(pa[x]);}
int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	n=gt(),m=gt(),k=gt(),ans=0x3f3f3f3f3f3f3f3fll,t=(1<<k);
	for(int i=0;i<m;++i) d.u=gt(),d.v=gt(),d.w=gt(),w.push(d);
	for(int i=1;i<=k;++i){
		c[i]=gt();
		for(int j=1;j<=n;++j) a[i][j]=gt(); 
	}
	iota(pa+1,pa+n+1,1);
	while(l<n-1){
		d=w.top();
		w.pop();
		if(find(d.u)!=find(d.v)) pa[pa[d.v]]=pa[d.u],f[l]=d,++l;
	}
	for(int _=0;_<t;++_){
		for(int i=1;i<=k;++i) o[i]=((_>>(i-1))&1);
		r=0,memset(vst,0,sizeof(vst));
		int h=0,v=0;
		while(!q.empty()) q.pop();
		for(int i=1;i<=n+k;++i) g[i].clear();
		for(int i=0;i<n-1;++i) g[f[i].u].push_back((Node){f[i].v,f[i].w}),g[f[i].v].push_back((Node){f[i].u,f[i].w});
		for(int i=1;i<=k;++i) if(o[i]){
			r+=c[i],++v;
			for(int j=1;j<=n;++j) g[i+n].push_back((Node){j,a[i][j]}),g[j].push_back((Node){i+n,a[i][j]}); 
		}
		q.push((Node){1,0});
		while(h<n+v){
			Node b=q.top();
			q.pop();
			if(vst[b.f]) continue;
			vst[b.f]=1,r+=b.e,++h;
			for(int i=0;i<g[b.f].size();++i) if(!vst[g[b.f][i].f]) q.push(g[b.f][i]);
		}
		ans=min(ans,r);
	}
	ot(ans);
	return 0;
}
