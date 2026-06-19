#include <bits/stdc++.h>
using namespace std;

int num = 0xAC;
char ch = 0xAC;
int read() {
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
	for (num = 0; ch >= '0' && ch <= '9'; ch = getchar()) {
		num = (num << 3) + (num << 1) + (ch & 0xf);
	}
	return num;
}

const int N = 20;
int n, a[N];

inline int lowbit(int x) {
	return x & -x;
}
int floorlb(int x) {
	for (int i = 0x1f; i >= 0; i--) {
		if ((x >> i) & 1)
			return i;
	}
	return -1;
}

inline bool maxeq(int &x, int k) {
	return (x < k) ? ((x = k), true) : false;
}

int score_singlecolor(int c) {
	int prv = -1;
	int cur;
	int ans = 0;
	while (c) {
		cur = floorlb(lowbit(c));
//		printf("%d %d\n", prv, cur);
		c &= c-1;
		if (~prv) {
			if (a[prv] == a[cur])
				ans += a[cur];
		}
		prv = cur;
	}
	return ans;
}
inline int score(int c) {
	return score_singlecolor(c) + score_singlecolor(((1 << n) - 1) &~ c);
}

int solve() {
	int ans = 0;
	n = read();
	for (int i = 0; i < n; i++) {
		a[i] = read();
	}
	for (unsigned c = 0; c < (1 << (n-1)); c++) {
		if (maxeq(ans, score(c)));
//			printf("%x\n", c);
	}
	return ans;
}

int main() {
	int T;
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);

	T = read();
	while (T--) {
		printf("%d\n", solve());
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

