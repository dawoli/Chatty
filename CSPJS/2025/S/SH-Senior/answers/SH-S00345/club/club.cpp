#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5, mod = 1e9 + 7;
ll T, n, a[N][5], maxn[N], id[N], cnt[5], tmp[N], ans, now;
void solve(ll x, ll y)
{
	now = 0;
	for(int i = 1; i <= n; i++)
	{
		tmp[i] = 1e9;
	}
	for(int i = 1; i <= n; i++)
	{
		if(id[i] == x)
		{
			now++;
			for(int j = 1; j <= 3; j++)
			{
				if(j != x)
				{
					tmp[now] = min(tmp[now], a[i][x] - a[i][j]);
				}
			}
		}
	}
	sort(tmp + 1, tmp + now + 1);
	for(int i = 1; i <= y; i++)
	{
		ans -= tmp[i];
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	while(T--)
	{
		cnt[1] = cnt[2] = cnt[3] = ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			maxn[i] = id[i] = 0;
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				cin >> a[i][j];
				if(a[i][j] > maxn[i])
				{
					maxn[i] = a[i][j];
					id[i] = j;
				}
			}
			cnt[id[i]]++;
			ans += maxn[i];
		}
		for(int i = 1; i <= 3; i++)
		{
			if(cnt[i] > n / 2)
			{
				solve(i, cnt[i] - n / 2);
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
