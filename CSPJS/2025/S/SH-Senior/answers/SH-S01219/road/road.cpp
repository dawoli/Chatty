#include<bits/stdc++.h>
#define N 10010
#define M 1000010
#define K 100
using namespace std;
int readint(){
	char c = getchar();
	while(c<'0'||c>'9') c = getchar();
	int num = 0;
	while('0'<=c&&c<='9'){
		num = num*10+(int)(c-'0');
		c = getchar();
	}
	return num;
}
long long readll(){
	char c = getchar();
	while(c<'0'||c>'9') c = getchar();
	long long num = 0;
	while('0'<=c&&c<='9'){
		num = num*10+(long long)(c-'0');
		c = getchar();
	}
	return num;
}
long long st[20];
void write(long long x){
	int cnt = 0;
	do{
		st[++cnt] = x%10;
		x /= 10;
	}while(x);
	while(cnt){
		putchar(st[cnt--]+'0');
	}
}

int n,m,k,id[N*2];
long long c[K],ans;
struct Edge{int u,v;long long w;};
vector<Edge> E,e,a[K],E2;
int root(int x){
	if(id[x]==x) return x;
	return id[x] = root(id[x]);
}
bool cmp(Edge a,Edge b){
	return a.w < b.w;
}
long long kruskal(bool flag){
	long long ans = 0;
	for(int i = 1;i <= n+k;++i) id[i] = i;
	for(int i = 0;i < E.size();++i){
		int u = E[i].u,v = E[i].v;long long w = E[i].w;
		int fu = root(u),fv = root(v);
		if(fu==fv) continue;
		if(flag) e.push_back(E[i]);
		id[fu] = fv;
		ans += w;
	}
	return ans;
}
void merge(int i){
	int n = E.size(),m = a[i].size();
	E2.clear();
	int x = 0,y = 0;
	while(x<n&&y<m){
		if(E[x].w<a[i][y].w){
			E2.push_back(E[x++]);
		}
		else E2.push_back(a[i][y++]);
	}
	while(x<n) E2.push_back(E[x++]);
	while(y<m) E2.push_back(a[i][y++]);
	E = E2;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = readint();
	m = readint();
	k = readint();
	for(int i = 1;i <= m;++i){
		int u,v;long long w;
		u = readint();v = readint();
		w = readll();
		E.push_back((Edge){u,v,w});
	}
	sort(E.begin(),E.end(),cmp);
	ans = kruskal(1);
	for(int i = 1;i <= k;++i){
		c[i] = readll();
		for(int j = 1;j <= n;++j){
			long long x;
			x = readll();
			a[i].push_back({n+i,j,x});
		}
		sort(a[i].begin(),a[i].end(),cmp);
	}
	for(int i = 1;i < (1<<k);++i){
		E = e;
		long long tmp = 0;
		for(int j = 1,w = 1;j <= k;++j,w *= 2){
			if(w&i){
				tmp += c[j];
				merge(j);
			}
		}
		tmp += kruskal(0);
		ans = min(ans,tmp);
	}
	write(ans);
	return 0;
}
