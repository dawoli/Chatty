#include<bits/stdc++.h>
using namespace std;
string s;
int n, q;
char t[100005];
int cnt[100005][26], ans = 0;
bitset<100005> b, c;
void dfs(int u, bool check = false)
{
	if (u > n)return;
	if (check)
	{
		if (!b[u])return;
	}
	dfs(u * 2, check);
	dfs(u * 2 + 1, check);
	int odd = 0, even = 0, sum = 0, u2 = 0, u21 = 0;
	if (u * 2 <= n)u2 = 1;
	if (u * 2 + 1 <= n)u21 = 1;
	for (int i = 0; i < 26; i++)
	{
		cnt[u][i] = (u2 ? cnt[u * 2][i] : 0) + (u21 ? cnt[u * 2 + 1][i] : 0) + (t[u] -  'a' == i ? 1 : 0);
		sum += cnt[u][i];
		if (cnt[u][i] & 1)odd++;
		else even++;
	}
	if (sum & 1)
	{
		if (odd == 1)ans++, c[u] = true;
		else if (check && c[u])ans--;
		else c[u] = false;
	}
	else
	{
		if (odd == 0)ans++, c[u] = true;
		else if (check && c[u])ans--;
		else c[u] = false;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	cin >> t[i];
	dfs(1);
	cout << ans <<  "\n";
	for (int i = 1; i <= q; i++)
	{
		b.reset();
		int x;
		char ch;
		cin >> x >> ch;
		cnt[x][t[x] -  'a']--;
		t[x] = ch;
		do
		{
			b.set(x, true);
			x /= 2;
		}
		while (x != 0);
		dfs(1, true);
		cout << ans <<  "\n";
	}
	return 0;
}