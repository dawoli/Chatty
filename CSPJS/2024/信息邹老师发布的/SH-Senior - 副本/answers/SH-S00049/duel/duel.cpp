#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
signed main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	scanf("%lld", &n);
	multiset<int>s;
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		s.insert(a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = n; i >= 1; i--) {
		int now = a[i];
		auto it = s.lower_bound(now);
		if(it == s.begin()) {
			continue;
		}
		it--;
		s.erase(it);
	}
	int ans = s.size();
	printf("%lld", ans);
}
