#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N = 1e5 + 5;
ll n, c[N], cnt, b[N];
bool cmp(ll a, ll b)
{
	return a < b;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n; cnt = n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		b[c[i]]++;
	}
	sort(c + 1, c + n + 1, cmp);
	int las = c[1];
	for (int i = 1; i <= n; i++)
	{
		if (las < c[i])
		{
			cnt--;
			b[las]--;
			while (!b[las++]);
			las--;
		}
		else continue;
	}
	cout << cnt << endl;
	return 0;
}
