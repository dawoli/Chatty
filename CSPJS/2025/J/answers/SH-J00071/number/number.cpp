#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res;
}

int cnt[10];
string s;

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); ++i)
		if (s[i] >= '0' && s[i] <= '9')
			++cnt[s[i] ^ 48];
	for (int i = 9; i >= 0; --i)
		while (cnt[i]--) putchar(i ^ 48);
	puts("");
	return 0;
}