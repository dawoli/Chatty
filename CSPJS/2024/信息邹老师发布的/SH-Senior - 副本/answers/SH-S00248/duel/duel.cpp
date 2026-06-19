#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, r, cnt[100005], tot;
vector <ll> v;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) cin >> r, cnt[r]++;
	for (ll i = 1; i <= 100000; i++) if (cnt[i]) v.push_back(i);
	for (ll i = 0; i < v.size(); i++)
	{
		tot -= cnt[v[i]];
		if (tot < 0) tot = 0;
		tot += cnt[v[i]];
	}
	cout << tot;
} 
