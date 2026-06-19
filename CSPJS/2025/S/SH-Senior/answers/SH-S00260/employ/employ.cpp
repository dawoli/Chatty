#include <bits/extc++.h>

template <typename T>
inline void Read(T &x) {
	char ch;
	for (x = 0; !isdigit(ch); ch = getchar());
	for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
}

template <typename T, typename... Tr>
inline void Read(T &x, Tr &... rest) {
	Read(x), Read(rest...);
}
template <typename T>
inline void ChkMin(T &x, const T &y) {
	if (x > y) x = y;
}
template <typename T>
inline void ChkMax(T &x, const T &y) {
	if (x < y) x = y;
}

constexpr int MaxN = 505, MaxM = MaxN, mod = 998244353;
int n, m, c[MaxN], id[MaxN]; char s[MaxN];

inline int qpow(int x, int n) {
	int ans = 1;
	for (int it = x; n; n >>= 1, it = 1l * it * it % mod)
		if (n & 1) ans = 1l * ans * it % mod;
	return ans;
}
inline int inv(int x) { return qpow(x, mod - 2); }

void SolveBrute() {
	int ans = 0;
	do {
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (!s[i] || cnt >= c[id[i]]) cnt++;
		if (n - cnt >= m) ans++;
		if (ans >= mod) ans -= mod;
	} while (std::next_permutation(id + 1, id + n + 1));
	printf("%d\n", ans);
}
int zero = 0;
// void SolveFA() {
// 	std::sort(c + 1, c + n + 1);
// 	int cnt = 0;
// 	for (int i = 1, cnt = 0; i <= n; i++)
// 		if (cnt >= c[i]) cnt++;
// 		else break;
// 	for (int i = 1; i <= )
// }
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	Read(n, m);
	scanf("%s", s + 1);
	bool FA = true;
	for (int i = 1; i <= n; i++) {
		if ((s[id[i] = i] -= '0') == 0) FA = false;
		Read(c[i]), zero += c[i] == 0;
	}
	// if (n <= 10) 
		return SolveBrute(), 0;
	// if (FA) return SolveFA(), 0;
	return 0;
}

/* 
	I Love OI Forever, and I wish I could study OI longer.
	My final year in CSP.
*/