# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100010;
ll n, ans, wai;
ll a[N];
ll cnt[N];

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), cnt[a[i]]++;
	sort(a + 1, a + n + 1);
	ans = n, wai = cnt[a[1]];
	for (int i = 2; i <= n; i++) 
	{
		if (a[i] == a[i - 1]) continue;
		if (wai > cnt[a[i]])
		{
			wai -= cnt[a[i]];
			ans -= cnt[a[i]];
			wai += cnt[a[i]];
		}
		else ans -= wai, wai = cnt[a[i]];
	}
	printf("%lld\n", ans);
//	wai=8 ans=19
//	136 *8
//	2417 *2
//	114514 11
	return 0;
}
