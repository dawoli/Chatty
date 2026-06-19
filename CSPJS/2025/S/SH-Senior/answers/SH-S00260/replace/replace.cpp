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

constexpr int MaxN = 2e5 + 5;
int n, q;
std::string s[MaxN][2], x, y;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	Read(n, q);
	for (int i = 1; i <= n; i++)
		std::cin >> s[i][0] >> s[i][1];
	for (int i = 1; i <= q; i++) {
		std::cin >> x >> y;
	}
	return 0;
}