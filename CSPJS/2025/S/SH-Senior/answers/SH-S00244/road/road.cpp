#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define M 1111111
#define N 11111
int n,m,k,V,p[N],val[M],c[N],a[12][N];
bool ok[M];
struct edge{ int u,v,w; } e[M];
bool cmpw(edge a,edge b){ return a.w < b.w; }
inline int find(int x){ return p[x] == x ? x : p[x] = find(p[x]); }
inline void init(){
	for(int i = 1;i <= n;++i) p[i] = i;
	sort(e + 1,e + m + 1,cmpw);
	for(int i = 1;i <= m;++i){
		int u = find(e[i].u),v = find(e[i].v);
		if(u == v) continue;
		p[u] = v;
		ok[i] = 1;
	}
}
vector<edge> qwq[M];
int pos[M];
inline ull kruskal(int num){
	for(int i = 1;i <= n + k;++i) p[i] = i;
	//  sort(e + 1,e + m + 1,cmpw);  CSP-S RP++!!!
	for(int i = 1;i <= V;++i) pos[i] = 0;
	for(int i = 1;i <= m;++i){
		if(num == n + k) qwq[e[i].w].emplace_back(e[i]);
		else qwq[e[i].w][pos[e[i].w]++] = e[i];
	}
	if(num == n + k)
		for(int i = 1;i <= m;++i) pos[i] = qwq[i].size();
	
	int tmp = m,cnt = 0;
	ull ans = 0;
	for(int i = 1;i <= V;++i){
		if(tmp > pos[i]){
			for(int j = 0;j < pos[i] && cnt < num - 1;++j){
				int u = find(qwq[i][j].u),v = find(qwq[i][j].v),w = qwq[i][j].w;
				if(u == v) continue;
				++cnt;
				p[u] = v;
				ans += val[w];
			}
			tmp -= pos[i];
		}else{
			for(int j = 0;j < tmp && cnt < num - 1;++j){
				int u = find(qwq[i][j].u),v = find(qwq[i][j].v),w = qwq[i][j].w;
				if(u == v) continue;
				++cnt;
				p[u] = v;
				ans += val[w];
			}
			break;
		}
	}
	return ans;
}
inline void read(int &x){
	x = 0;
	char c = getchar();
	while(c > '9' || c < '0') c = getchar();
	while('0' <= c && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48),c = getchar(); 
}
inline void work(){
	cin>>n>>m>>k;
	for(int i = 1;i <= m;++i){
		cin>>e[i].u>>e[i].v>>e[i].w;
		// read(e[i].u); read(e[i].v); read(e[i].w);
	}	
	for(int i = 1;i <= k;++i){
		cin>>c[i];
		// read(c[i]);
		for(int j = 1;j <= n;++j){
			cin>>a[i][j];
			// read(a[i][j]);
		}	
	}
	init();
	int qwq = 0;
	for(int i = 1;i <= m;++i)
		if(ok[i]) e[++qwq] = e[i];
	m = n - 1;
	
	for(int i = 1;i <= m;++i) val[++V] = e[i].w;
	for(int i = 1;i <= k;++i)
		for(int j = 1;j <= n;++j) val[++V] = a[i][j];
	sort(val + 1,val + V + 1);
	V = unique(val + 1,val + V + 1) - val - 1;
	for(int i = 1;i <= m;++i) e[i].w = lower_bound(val + 1,val + V + 1,e[i].w) - val;
	for(int i = 1;i <= k;++i)
		for(int j = 1;j <= n;j++) a[i][j] = lower_bound(val + 1,val + V + 1,a[i][j]) - val;
	ull ans = 9e18;
	for(int p = (1 << k) - 1;p >= 0;--p){
		m = n - 1;
		ull sum = 0; int cnt = 0;
		for(int i = 1;i <= k;++i){
			if(!(p & (1 << (i - 1)))) continue;
			sum += c[i];
			cnt++;
			for(int j = 1;j <= n;++j) e[++m] = (edge){n + i,j,a[i][j]};
		}
		// cout<<p<<" "<<sum<<" ";
		sum += kruskal(n + cnt);
		ans = min(ans,sum);
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	work();
}
