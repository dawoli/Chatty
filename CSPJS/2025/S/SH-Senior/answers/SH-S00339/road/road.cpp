#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+5;
const int M = 1e6+5;
struct Edge{int u,v,w;} e[M];
struct Node{int u,w;};
int n,m,k,w,c[N],f[N+100],ans,cnt,a[15][N],used[M],fa[N],l,r;
vector<pair<int,int>> tmp[15];
vector<int> g[N];
bitset<N> be[N],t;
bool A=true;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
bool merge(int a,int b){
	a=find(a),b=find(b);
	if(a!=b){
		f[a]=b;
		return true;
	}
	return false;
}
bool cmp(Edge a,Edge b){return a.w<b.w;}
void solve1(){
	int ans=0,cnt=0;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;++i){
		if(merge(e[i].u,e[i].v)){
			ans+=e[i].w;
			cnt++;
		}
		if(cnt+1==n) continue;
	}
	cout<<ans<<"\n";
}
void solve2(){
	cout<<0;
}
void dfs(int x,int f){
	be[x][x]=1; fa[x]=f;
	for(auto u:g[x]){
		if(u==f) continue;
		dfs(u,x); be[x]|=be[u];
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;++i) f[i]=i;
	for(int i=1;i<=m;++i) cin>>e[i].u>>e[i].v>>e[i].w;
	if(k==0){
		solve1();
		return 0;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		if(c[i]) A=false;
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j]) A=false;
		}
	}
	if(A){
		solve2();
		return 0;
	}
	int ans=0,cnt=0;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;++i){
		if(merge(e[i].u,e[i].v)){
			ans+=e[i].w;
			cnt++; used[i]=1;
			g[e[i].u].push_back(e[i].v);
			g[e[i].v].push_back(e[i].u);
		}
		if(cnt+1==n) continue;
	}
	dfs(1,0);
	for(int x=1,p=0;x<=m;++x){
		if(!used[x]) continue;
		for(int j=1;j<=k;++j){
			l=r=INT_MAX;
			for(int i=1;i<=n;++i){
				if(fa[e[x].v]==e[x].u) swap(e[x].u,e[x].v);
				t[i]=1;
				t&=be[e[x].u];
				if(t.count()){
					l=min(l,a[j][i]);
				}else{
					r=min(r,a[j][i]);
				}
				t[i]=0;
			}
			if(l+r<cnt){
				cnt=l+r;
				p=j;
			}
			tmp[j].push_back({l+r-e[x].w,x});
		}
	}
	cnt=0;
	memset(used,0,sizeof(used));
	for(int i=1;i<=k;++i){
		cnt=c[i];
		sort(tmp[i].begin(),tmp[i].end());
		for(auto u:tmp[i]){
			if(used[u.second]) continue;
			used[u.second]=1;
			if(cnt+u.first>=0) break;
			cnt+=u.first;
		}
		if(cnt<0) ans+=cnt;
	}
	cout<<ans;
	return 0;
}
