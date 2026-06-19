#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, hd, tl;
ll a[200100];
ll que[200100];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	hd = 1;
	for (ll i = 1; i <= n; i++) {
		if (hd <= tl && que[hd] < a[i]) {
			hd++;
		}
		que[++tl] = a[i];
	}
	printf("%lld\n", tl - hd + 1);
	return 0;
} 
