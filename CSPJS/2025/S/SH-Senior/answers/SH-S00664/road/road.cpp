#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10015, M = 1000005, K = 15;

namespace IO {
void read(int &x) {
	x = 0;
	int tag = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') tag = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = x*10 + ch - 48;
		ch = getchar();
	}
	x *= tag;
}

void print(ll x) {
	if(!x) {
		putchar(48);
		return;
	}
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	int stk[25], top = 0;
	for(; x; x /= 10) stk[++top] = x % 10;
	for(; top; --top) putchar(stk[top] + 48);
}
}

using IO::read;
using IO::print;

namespace BCJ {
int fa[N];

void init(int x) {
	for(int i = 1; i <= x; ++i) fa[i] = i;
}

int find(int x) {return fa[x] == x ? x : (fa[x] = find(fa[x]));}
}

namespace {
int n, m, k;
ll ans;
int c[K], a[K][N];
int nE, cur[K];

struct Edge {
	int u, v, w;
}e[M], ek[K][N];

void kru() {
	sort(e + 1, e + m + 1, [&](Edge X, Edge Y){return X.w < Y.w;});
	BCJ::init(n);
	for(int i = 1; i <= m; ++i) {
		int u = BCJ::find(e[i].u), v = BCJ::find(e[i].v), w = e[i].w;
		if(u == v) continue;
		ans += w;
		BCJ::fa[u] = v;
		e[++nE] = e[i];
	}
}

void sol(int x) {
	ll sum = 0;
	for(int i = 1; i <= k; ++i) if((x >> (i - 1)) & 1) sum += c[i], cur[i] = 1;
	BCJ::init(n + k);
	for(int i = 1; i <= nE; ++i) {
		for(int j = 1; j <= k; ++j) if((x >> (j - 1)) & 1) {
			while(cur[j] <= n && ek[j][cur[j]].w < e[i].w) {
				int u = BCJ::find(ek[j][cur[j]].u), v = BCJ::find(ek[j][cur[j]].v), w = ek[j][cur[j]].w;
				if(u == v) {
					++cur[j];
					continue;
				}
				sum += w;
				BCJ::fa[u] = v;
				++cur[j];
			}
		}
		int u = BCJ::find(e[i].u), v = BCJ::find(e[i].v), w = e[i].w;
		if(u == v) continue;
		sum += w;
		BCJ::fa[u] = v;
	}
	ans = min(ans, sum);
}

void MAIN() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n); read(m); read(k);
	for(int i = 1; i <= m; ++i) {
		read(e[i].u); read(e[i].v); read(e[i].w);
	}
	for(int i = 1; i <= k; ++i) {
		read(c[i]);
		for(int j = 1; j <= n; ++j) {
			read(a[i][j]);
			ek[i][j] = {i + n, j, a[i][j]};
		}
		sort(ek[i] + 1, ek[i] + n + 1, [&](Edge X, Edge Y){return X.w < Y.w;});
	}
	kru();
	for(int i = 0; i < (1 << k); ++i) sol(i);
	print(ans);
}
}

int main() {
	MAIN();
	return 0;
}
