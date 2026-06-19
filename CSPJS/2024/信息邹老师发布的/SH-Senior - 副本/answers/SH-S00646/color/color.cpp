#include <iostream>
#include <cstdio>
using namespace std;
int t, n, clr[200010];
long long a[200010], ans;
long long cal() {
	long long ret = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i - 1; j; j--) {
			if(clr[j] == clr[i]) {
				if(a[i] == a[j]) {
					ret += a[i];
				}
				break;
			}
		}
	}
	return ret;
}
void dfs(int x) {
	if(x > n) {
		ans = max(ans, cal());
		return;
	}
	clr[x] = 0;
	dfs(x + 1);
	clr[x] = 1;
	dfs(x + 1);
} 
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		ans = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		dfs(1);
		printf("%lld\n", ans);
	}
    return 0;
}
