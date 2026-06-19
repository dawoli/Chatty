#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e5 + 7;

ll n, a[N], b[N];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
	
	sort(a + 1, a + n + 1);
	int tot = 1, cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == a[i + 1]) {
			++tot;
			continue;
		}
		b[++cnt] = tot;
		tot = 1;
	}
	
	ll rem = b[1];
	for (int i = 2; i <= cnt; ++i) {
		if (rem <= b[i]) rem = 0;
		else rem -= b[i];
		rem += b[i];
	}
	printf("%lld\n", rem);
	
	return 0;
}

