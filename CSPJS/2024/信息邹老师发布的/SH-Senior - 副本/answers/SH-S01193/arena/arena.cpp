#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

int n, m;
int a[maxn], c[maxn];

signed main() {
//	freopen("arena.in", "r", stdin);
//	freopen("arena.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	n = read(), m = read();
	for(int i = 1; i <= n; ++i) a[i] = read();
	for(int i = 1; i <= m; ++i) c[i] = read();
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
