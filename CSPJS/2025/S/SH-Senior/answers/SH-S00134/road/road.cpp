#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 7;
char buf[1<<21],*p1,*p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1<<20,stdin),p1 == p2) ? 0 : *p1++)
template <typename T>
inline void read(T& x){
	int f = 1;
	x = 0;
	char ch = gc();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = gc();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = gc();
	}
	x *= f;
}
int n,m,k;
struct node{
	int u,v,w;
	bool operator <(const node& kkk)const{
		return w < kkk.w;
	}
}bb[1000010],cop[1000010];
node A[1024][10020];
int sz[1024];
int tot = 0,totcop = 0;
int fa[20010],SZ[20010];
int Find(int i){
	return fa[i] == i ? i : fa[i] = Find(fa[i]);
}
int cnt;
void Unite(int u,int v){
	u = Find(u),v = Find(v);
	if(u == v) return;
	if(SZ[u] < SZ[v]) swap(u,v);
	fa[v] = u,SZ[u] += SZ[v],cnt--;
}
int c[12],a[12][20010];
node oooo[20010];
int szz = 0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i = 1,u,v,w; i <= m; i++){
		read(u),read(v),read(w);
		bb[i] = {u,v,w};
	}
	sort(bb + 1,bb + m + 1);
	for(int i = 1; i <= n; i++) fa[i] = i,SZ[i] = 1;
	cnt = n;
	for(int i = 1; i <= m; i++){
		int u = bb[i].u,v = bb[i].v;
		if(Find(u) == Find(v)) continue;
		Unite(u,v);
		oooo[++szz] = bb[i];
		if(cnt == 1) break;
	}
	for(int i = 1; i <= k; i++){
		read(c[i]);
		for(int j = 1; j <= n; j++) read(a[i][j]),A[1LL << (i - 1)][j] = {n + i,j,a[i][j]};
		sort(A[1LL << (i - 1)] + 1,A[1LL << (i - 1)] + n + 1);
		sz[1LL << (i - 1)] = n;
	}
	for(int s = 1; s < (1LL << k); s++){
		if(__builtin_popcount(s) == 1) continue;
		int t = s ^ (s & (-s)),o = (s & (-s));
		vector<node>vc;
		for(int i = 1; i <= n + k; i++) fa[i] = i,SZ[i] = 1;
		int tar = k - __builtin_popcount(s) + 1;
		cnt = n + k;
		int i = 1,j = 1;
		while(i <= sz[t] && j <= sz[o]){
			if(A[t][i] < A[o][j]) vc.push_back(A[t][i++]);
			else vc.push_back(A[o][j++]);
		}
		while(i <= sz[t]) vc.push_back(A[t][i++]);
		while(j <= sz[o]) vc.push_back(A[o][j++]);
		sz[s] = 0;
		for(auto oo : vc){
			int u = oo.u,v = oo.v;
			if(Find(u) == Find(v)) continue;
			Unite(u,v);
			A[s][++sz[s]] = oo;
			if(cnt == tar) break;
		}
	}
	ll ans = INF;
	for(int s = 0; s < (1LL << k); s++){
		ll tmp = 0;
		for(int i = 1; i <= k; i++) if(s >> (i - 1) & 1LL) tmp += c[i];
		cnt = n + k;
		for(int i = 1; i <= n + k; i++) fa[i] = i,SZ[i] = 1;
		int tar = k - __builtin_popcount(s) + 1;
		vector<node>vc;
		int i = 1,j = 1;
		while(i <= sz[s] && j <= szz){
			if(A[s][i] < oooo[j]) vc.push_back(A[s][i++]);
			else vc.push_back(oooo[j++]);
		}
		while(i <= sz[s]) vc.push_back(A[s][i++]);
		while(j <= szz) vc.push_back(oooo[j++]);
		for(auto ooo : vc){
			int u = ooo.u,v = ooo.v,w = ooo.w;
			if(Find(u) == Find(v)) continue;
			Unite(u,v);
			tmp += w;
			if(cnt == tar) break;
		}
		ans = min(ans,tmp);
	} 
	printf("%lld",ans);
	return 0; 
}
