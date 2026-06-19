#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18+7;
struct node{
	int u;
	long long c;
	bool operator < (const node a) const {
		return c > a.c;
	}
};
struct edge{
	int u,v;
	long long w;
}e[8000050],lin[8000050]; 
int n,m,k,c[15],plan[15],a[15][10050],u[1000050],v[1000050],w[1000050],sz,cnt,f[1000050];
long long vst[10050],d[10050],ans,mn = INF;
bool cmp(edge x,edge y){
	return x.w < y.w;
}
inline int fd(int x){
	if(f[x] == x) return x;
	return f[x] = fd(f[x]);
}
void unite(int x,int y){
	f[fd(x)] = fd(y);
}
void kruskal(){
	sort(e+1,e+cnt+1,cmp);
	for(int i = 1;i <= cnt;++i){
		if(fd(e[i].u) != fd(e[i].v)){
			unite(e[i].u,e[i].v);
			ans+=e[i].w;
		}
	}
}
void chgt(){
	for(int i = 1;i <= k;++i){
		if(plan[i] == 1){
			for(int j = 1;j <= n;++j){
				e[++cnt].u = j;
				e[cnt].v = n+i;
				e[cnt].w = a[i][j];
				e[++cnt].v = j;
				e[cnt].u = n+i;
				e[cnt].w = a[i][j];
			}
		}
	}
}
void dfs(int step,long long num){
	if(step > k){
		for(int i = 1;i <= n+k;++i) f[i] = i;
		chgt();
		kruskal();
		mn = min(mn,num+ans);
		ans = 0;
		for(int i = 1;i <= sz;++i){
			e[i].u = lin[i].u;
			e[i].v = lin[i].v;
			e[i].w = lin[i].w;
		}
		cnt = sz;
		return ;
	}
	plan[step] = 1;
	dfs(step+1,num+c[step]);
	plan[step] = 0;
	dfs(step+1,num);	
}
bool ok(){
	for(int i = 1;i <= k;++i){
		if(c[i] != 0) return false;
	}
	return true;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(register int i = 1;i <= m;++i){
		cin>>u[i]>>v[i]>>w[i];
		e[++cnt].u = u[i];
		e[cnt].v = v[i];
		e[cnt].w = w[i];
		lin[cnt].u = u[i];
		lin[cnt].v = v[i];
		lin[cnt].w = w[i];
		e[++cnt].u = v[i];
		e[cnt].v = u[i];
		e[cnt].w = w[i];
		lin[cnt].u = v[i];
		lin[cnt].v = u[i];
		lin[cnt].w = w[i];
	}
	sz = cnt;
	for(int i = 1;i <= k;++i){
		cin>>c[i];
		for(int j = 1;j <= n;++j) cin>>a[i][j];
	}
	if(ok()){
		for(int i = 1;i <= k;++i) plan[i] = 1;
		for(int i = 1;i <= n+k;++i) f[i] = i;
		chgt();
		kruskal();
		long long sss = 0;
		for(int i = 1;i <= k;++i) sss+=c[i];
		cout<<ans+sss;
		return 0;
	}
	dfs(1,0);
	cout<<mn;
	return 0;
}
