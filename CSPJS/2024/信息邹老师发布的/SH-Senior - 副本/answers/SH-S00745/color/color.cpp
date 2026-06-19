#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 6;

// 记得开long long 
// 记得检查文件读入读出

ll a[N], c[N];
map<ll, ll> mp;

void solve()
{
	ll n; cin >> n;
	for(ll i=1; i<=n; i++) cin >> a[i];
	
	memset(c, 0, sizeof(c));
	mp.clear();
	
	for(ll i=2; i<=n; i++)
	{
		mp[a[i-1]] = 1;
		if(mp[a[i]])
		{
			c[i] = a[i];
		}
	}
	
	ll sum = 0;
	for(ll i=2; i<=n; i++) sum += c[i];
	cout << sum << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;	
} 
