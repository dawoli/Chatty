#include <bits/stdc++.h>
using namespace std;

long long n, flag = 1, ans, maxn = 0;
long long a[5005];

void dfs(int x) {
	if(x > maxn * 2) {
		ans++;
		return;
	}
	for(int i = 1; i <= n; i++) {
		maxn = max(a[i], maxn);
		dfs(x * a[i]);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] != 1) flag = 0;
	}
	if(n < 3) {
		printf("0");
		return 0;
	}
	if(flag == 1) {
		for(long long i = 3; i <= n; i++) {
			long long tmp = 1;
			for(long long j = n; j > i; j--) {
				tmp = tmp * j;
				tmp = tmp % 998244353;
			}
			ans = ans % 998244353;
			ans += tmp;
			ans = ans % 998244353;
		}
	}
	else if(n <= 3) {
		int maxs = 0, sum = 0;
		for(int i = 1; i <= n; i++) if(maxs < n) maxs = a[i];
		for(int i = 1; i <= n; i++) {
			sum += a[i];
		}
		if(sum > maxs * 2) ans++;
	}
	else {
		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++) {
				for(int k = j; k <= n; k++) {
					dfs(1);
				}
			}
		}
	}
	cout << ans;
	return 0;
} 
