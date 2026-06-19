#include<bits/stdc++.h>
using namespace std;
#define int long long
int read() {
	char c = getchar();
	int cc = 0,ccc = 1;
	while(c < '0' || c > '9') {
		if(c == '-') ccc = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		cc = cc * 10 + c - '0';
		c = getchar();
	}
	return cc * ccc;
}
const int maxn = 10010;
const int maxm = 1e6 + 10;
int n,m,k;
struct node{
	int u,v,w;
}e[maxm];
int fa[maxn];
bool cmp(node a,node b) {
	return a.w < b.w;
}
int find(int x) {
	if(x == fa[x]) {
		return x;
	}
	else return fa[x] = find(fa[x]);
}
void solve1() {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
////		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	int cnt = 0,sum = 0;
	sort(e + 1,e + m + 1,cmp);
	for (int i = 1; i <= m; i++) {
		int u = e[i].u,v = e[i].v;
		u = find(u),v = find(v);
		if(u == v) {
			continue;
		}
		sum += e[i].w;
		cnt++;
		fa[u] = v;
		if(cnt >= n - 1) break;
	}
	cout << sum << "\n";
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	m = read();
	k = read();
//	cout << n << " " << m << " " << k << "\n";
	if(k == 0) {
		solve1();
		return 0;
	}
	else solve1();
	return 0;
}
/*
5 8 0
1 5 9
5 4 8
4 3 7
3 1 8
3 2 6
2 1 3
2 4 5
2 5 2
*/
