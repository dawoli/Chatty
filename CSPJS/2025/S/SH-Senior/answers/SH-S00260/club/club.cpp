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

constexpr int MaxN = 1e5 + 5;
int n, lim, a[MaxN][3], id[MaxN];
char max[MaxN], sub[MaxN];

struct Member {
	int a[3], max, sub;
	inline void Update() {
		max = sub = 0;
		if (a[1] > a[max]) max = 1;
		if (a[1] <= a[sub]) sub = 1;
		if (a[2] > a[max]) max = 2;
		if (a[2] <= a[sub]) sub = 2;
		sub = 3 - max - sub;
	}
	inline const int Delta() const { 
		return a[max] - a[sub];
	}
} m[MaxN];
inline void Read(Member &x) {
	Read(x.a[0], x.a[1], x.a[2]);
}

void TestCase() {
	Read(n), lim = n >> 1;
	for (int i = 1; i <= n; i++)
		Read(m[i]), m[i].Update();
	std::sort(m + 1, m + n + 1, [](const Member &x, const Member &y) { return x.Delta() > y.Delta(); });
	int cnt[3] = {0, 0, 0}, ans = 0;
	for (int i = 1; i <= n; i++)
		if (cnt[m[i].max] < lim)
			cnt[m[i].max]++, ans += m[i].a[m[i].max];
		else
			cnt[m[i].sub]++, ans += m[i].a[m[i].sub];
	printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; Read(t);
	while (t--) TestCase();
	return 0;
}