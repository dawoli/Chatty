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

struct Attack {
	int attack, life, id;
} r[maxn];

int n, cnt = 0, ans;

signed main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
//	scanf("%d", &n);
	n = read();
	for(int i = 1; i <= n; ++i) {
//		scanf("%d", &r[i].id);
		r[i].id = read();
		r[i].attack = 0;
		r[i].life = 1;
	}
	
	for(int i = 1; i <= n; ++i) {
		if(r[i].attack == 1 || r[i].life == 0) continue;
		for(int j = 1; j <= n; ++j) {
			if(r[j].id > r[i].id) {
				r[j].attack = 1;
				r[i].life = 0;		
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(r[i].life != 0) cnt++;
	}
	
	ans = n - cnt;
	printf("%d\n", ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
