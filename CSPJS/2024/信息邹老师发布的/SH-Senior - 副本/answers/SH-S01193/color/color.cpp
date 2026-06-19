#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;

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

struct Color {
	int value, color, left, right;
} a[maxn];

int T, n, ans = 0, cnt = 0;
int red = 1, blue = 0;
int c[maxn];

signed main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	T = read();
	while(T--) {
		n = read();
		for(int i = 1; i <= n; ++i) {
			a[i].value = read();
			a[i].color = red;
			a[i - 1].right = a[i].value;
			a[i].left = a[i - 1].value;
		}
		for(int i = 1; i <= n; ++i) {
			if(a[i].color != a[i - 1].color) c[i] = 0;
			for(int j = 1; j <= n; ++j) {
				if(a[j].color == a[i].color && a[i].left == a[j].value) {
					c[i] = a[i].value;
				}
				else c[i] = 0;
			}
			cnt += c[i];
			ans = max(ans, cnt);
		}
		printf("%d\n", ans);
//		printf("%d\n", 0);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
