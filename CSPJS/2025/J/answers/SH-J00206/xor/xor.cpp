# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500010;
ll n, k, sum, ans, p;
ll a[N];
map <ll, ll> mp;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	sum = 0;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), mp[sum ^= a[i]] = -1;
	if (k) mp[0] = 0;
	p = sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum ^= a[i];
		if (mp[sum ^ k] >= p)
		{
//			cout<<i<<endl;
			ans++;
			p = i;
		}
		mp[sum] = i;
	}
	printf("%lld\n", ans);
	return 0;
}
