#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int T, n, k, q;
int l[N + 5] = {};
int s[N + 1][2001] = {};
int r, c;
long long subs = 0;
bool ans[N + 5] = {};

struct wordle
{
	int h;
	int st_idx;
	int en_idx;
};
wordle a[N + 5];

void calc (int tas, int t, int hos, int en_adr)
{
	if (t >= r)
	{
		if (en_adr == c)
			ans[tas] = true;
	}
	else
	{
		if (hos == 0)
		{
			for (int j = 1; j <= subs; j++)
			{
				if (a[j].st_idx == 1)
					calc (tas, t + 1, a[j].h, a[j].en_idx);
			}
		}
		else
		{
			for (int j = 1; j <= subs; j++)
			{
				if (a[j].h != hos && a[j].st_idx == en_adr)
					calc (tas, t + 1, a[j].h, a[j].en_idx);
			}
		}
	}
}

int main ()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		subs = 0;
		memset(s, 0, sizeof(s));
		memset(l, 0, sizeof(l));
		memset(ans, false, sizeof(ans));
		cin >> n >> k >> q;
		for (int j = 1; j <= n; j++)
		{
			cin >> l[j];
			for (int m = 1; m <= l[j]; m++)
			{
				cin >> s[j][m];
			}
		}
		for (int j = 1; j <= n; j++)
		{
			for (int m = 2; m <= min (k, l[j]); m++)
			{
				for (int p = 1; p <= l[j] + 1 - m; p++)
				{
					subs++;
					a[subs].h = j;
					a[subs].st_idx = s[j][p];
					a[subs].en_idx = s[j][p + m - 1];
				}
			}
		}
		/*
		for (int j = 1; j <= subs; j++)
		{
			cout << "j: " << j << endl;
			cout << "host: " << a[j].h << endl;
			cout << "start: " << a[j].st_idx << endl;
			cout << "end: " << a[j].en_idx << endl;
			cout << endl;
		}
		*/
		for (int j = 1; j <= q; j++)
		{
			cin >> r >> c;
			calc(j, 0, 0, 1);
			cout << ans[j] << endl;
		}
	}
	return 0;
}
