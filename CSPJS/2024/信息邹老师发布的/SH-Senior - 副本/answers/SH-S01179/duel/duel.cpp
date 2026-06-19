#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[1919810], cnt[1919810], ans, pre[1919810];
signed main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		cnt[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	m = unique(a + 1, a + n + 1) - a - 1;
	for(int i = 1; i <= m; i++){
		pre[i] = pre[i - 1] + cnt[a[i]];
	}
	for(int i = 2; i <= m; i++){
		if(cnt[a[i]] > pre[i - 1]){
			ans += pre[i - 1];
			pre[i] = cnt[a[i]];
		} else{
			ans += cnt[a[i]];
			pre[i] -= cnt[a[i]];
		}
	}
	printf("%lld", n - ans);
	return 0;
}
