#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll *c1 = nullptr, *c2 = nullptr, *c3 = nullptr;
int n;
ll dfst(int ca, int cb, int cc, int nc)
{
	if (nc == n)
	{
		return 0;
	}
	ll ans = 0;
	if (ca < n / 2)
	{
		ans = max(dfst(ca + 1, cb, cc, nc + 1) + c1[nc], ans);
	}
	if (cb < n / 2)
	{
		ans = max(dfst(ca, cb + 1, cc, nc + 1) + c2[nc], ans);
	}
	if (cc < n / 2)
	{
		ans = max(dfst(ca, cb, cc + 1, nc + 1) + c3[nc], ans);
	}
	return ans;
}
struct pkg33
{
	int t;
	bool operator<(pkg33 b)
	{
		return c3[t] < c3[b.t];
	}
};
ll p2()
{
	pkg33 *pc1 = new pkg33[n], *pc2 = new pkg33[n];
	for (int i = 0; i < n; i++)
	{
		c3[i] = c1[i] - c2[i];
	}
	ll ca = 0, cb = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (c1[i] > c2[i])
		{
			ans += c1[i];
			pc1[ca].t = i;
			ca++;
		}
		else
		{
			ans += c2[i];
			pc2[cb].t = i;
			cb++;
		}
	}
	sort(pc1, pc1 + ca);
	sort(pc2, pc2 + cb);
	if (ca > n / 2)
	{
		ll oca = ca;
		while (ca > n / 2)
		{
			ans -= c3[pc1[oca - ca].t];
			ca--;
			cb++;
		}
	}
	else
	{
		while (cb > n / 2)
		{
			cb--;
			ans += c3[pc2[cb].t];
			ca++;
		}
	}
	delete[] pc1;
	delete[] pc2;
	return ans;
}
struct pkg3
{
	int t, type;
	bool operator<(pkg3 b)
	{
		return c3[t] < c3[b.t];
	}
};
struct pkg1
{
	int t, type;
	bool operator<(pkg1 b)
	{
		return c1[t] < c1[b.t];
	}
};
struct pkg2
{
	int t, type;
	bool operator<(pkg2 b)
	{
		return c2[t] < c2[b.t];
	}
};
ll p3()
{
	int ca = 0, cb = 0, cc = 0;
	ll ans = 0;
	pkg1 *pc1 = new pkg1[n];
	pkg2 *pc2 = new pkg2[n];
	pkg3 *pc3 = new pkg3[n];
	for (int i = 0; i < n; i++)
	{
		if (c1[i] > c2[i])
		{
			if (c1[i] > c3[i])
			{
				ans += c1[i];
				if (c1[i] - c2[i] > c1[i] - c3[i])
				{
					c1[i] = c1[i] - c2[i];
					pc1[ca++].t = i;
					pc1[ca++].type = 2;
				}
				else
				{
					c1[i] = c1[i] - c3[i];
					pc1[ca++].t = i;
					pc1[ca++].type = 3;
				}
				ca++;
			}
			else
			{
				ans += c3[i];
				if (c3[i] - c2[i] > c3[i] - c1[i])
				{
					c3[i] = c3[i] - c2[i];
					pc3[cc].t = i;
					pc3[cc].type = 2;
				}
				else
				{
					c3[i] = c3[i] - c1[i];
					pc3[cc].t = i;
					pc3[cc].type = 1;
				}
				cc++;
			}
		}
		else
		{
			if (c2[i] > c3[i])
			{
				ans += c2[i];
				if (c2[i] - c1[i] > c2[i] - c3[i])
				{
					c2[i] = c2[i] - c1[i];
					pc2[cb].t = i;
					pc2[cb].type = 1;
				}
				else
				{
					c2[i] = c2[i] - c3[i];
					pc2[cb].t = i;
					pc2[cb].type = 3;
				}
				cb++;
			}
			else
			{
				ans += c3[i];
				if (c3[i] - c2[i] > c3[i] - c1[i])
				{
					c3[i] = c3[i] - c2[i];
					pc3[cc].t = i;
					pc3[cc].type = 2;
				}
				else
				{
					c3[i] = c3[i] - c1[i];
					pc3[cc].t = i;
					pc3[cc].type = 1;
				}
				cc++;
			}
		}
	}
	if (ca > n / 2)
	{
		sort(pc1, pc1 + ca);
		ll oca = ca;
		while (ca > n / 2)
		{
			if (pc1[oca - ca].type == 2)
			{
				ans -= c1[pc1[oca - ca].t];
				c1[pc1[oca - ca].t] += c2[pc1[oca - ca].t];
				int i = pc1[oca - ca].t;
				pc2[cb].type = 3;
				c2[i] -= c3[i];
				pc2[cb++].t = i;
			}
			else
			{
				ans -= c1[pc1[oca - ca].t];
				c1[pc1[oca - ca].t] += c3[pc1[oca - ca].t];
				int i = pc1[oca - ca].t;
				pc3[cc].type = 2;
				c3[i] -= c2[i];
				pc3[cc++].t = i;
			}
			ca--;
		}
		if (cb > n / 2)
		{
			sort(pc2, pc2 + cb);
			ll ocb = cb;
			while (cb > n / 2)
			{
				if (pc2[ocb - cb].type == 1)
				{
					ocb++;
				}
				else
				{
					ans -= c2[pc2[ocb - cb].t];
					cb--;
				}
			}
		}
		else if (cc > n / 2)
		{
			sort(pc3, pc3 + cc);
			ll occ = cc;
			while (cc > n / 2)
			{
				if (pc3[occ - cc].type == 1)
				{
					occ++;
				}
				else
				{
					ans -= c3[pc3[occ - cc].t];
					cc--;
				}
			}
		}
	}
	else if (cb > n / 2)
	{
		sort(pc2, pc2 + cb);
		ll ocb = cb;
		while (cb > n / 2)
		{
			if (pc2[ocb - cb].type == 3)
			{
				ans -= c2[pc2[ocb - cb].t];
				c2[pc2[ocb - cb].t] += c3[pc2[ocb - cb].t];
				int i = pc2[ocb - cb].t;
				pc3[cc].type = 1;
				c3[i] -= c1[i];
				pc3[cc++].t = i;
			}
			else
			{
				ans -= c2[pc2[ocb - cb].t];
				c2[pc2[ocb - cb].t] += c1[pc2[ocb - cb].t];
				int i = pc2[ocb - cb].t;
				pc1[ca].type = 3;
				c1[i] -= c3[i];
				pc1[ca++].t = i;
			}
			cb--;
		}
		if (cc > n / 2)
		{
			sort(pc3, pc3 + cc);
			ll occ = cc;
			while (cc > n / 2)
			{
				if (pc3[occ - cc].type == 2)
				{
					occ++;
				}
				else
				{
					ans -= c3[pc3[occ - cc].t];
					cc--;
				}
			}
		}
		else if (ca > n / 2)
		{
			sort(pc1, pc1 + ca);
			ll oca = ca;
			while (ca > n / 2)
			{
				if (pc1[oca - ca].type == 2)
				{
					oca++;
				}
				else
				{
					ans -= c1[pc1[oca - ca].t];
					ca--;
				}
			}
		}
	}
	else if (cc > n / 2)
	{
		sort(pc3, pc3 + cc);
		ll occ = cc;
		while (cc > n / 2)
		{
			if (pc3[occ - cc].type == 1)
			{
				ans -= c3[pc3[occ - cc].t];
				c3[pc3[occ - cc].t] += c1[pc3[occ - cc].t];
				int i = pc3[occ - cc].t;
				pc1[ca].type = 2;
				c1[i] -= c2[i];
				pc1[ca++].t = i;
			}
			else
			{
				ans -= c3[pc3[occ - cc].t];
				c3[pc3[occ - cc].t] += c2[pc3[occ - cc].t];
				int i = pc3[occ - cc].t;
				pc2[cb].type = 3;
				c2[i] -= c1[i];
				pc2[cb++].t = i;
			}
			cc--;
		}
		if (ca > n / 2)
		{
			sort(pc1, pc1 + ca);
			ll oca = ca;
			while (ca > n / 2)
			{
				if (pc1[oca - ca].type == 3)
				{
					oca++;
				}
				else
				{
					ans -= c1[pc1[oca - ca].t];
					ca--;
				}
			}
		}
		else if (cb > n / 2)
		{
			sort(pc2, pc2 + cb);
			ll ocb = cb;
			while (cb > n / 2)
			{
				if (pc2[ocb - cb].type == 3)
				{
					ocb++;
				}
				else
				{
					ans -= c2[pc2[ocb - cb].t];
					cb--;
				}
			}
		}
	}
	return ans;
}
void solve()
{
	cin >> n;
	c1 = new ll[n];
	c2 = new ll[n];
	c3 = new ll[n];
	bool flag1 = true, flag2 = true;
	for (int i = 0; i < n; i++)
	{
		cin >> c1[i] >> c2[i] >> c3[i];
		if (flag2 && c3[i] != 0)
			flag2 = false;
		if (flag1 && c1[i] != 0 || c2[i] != 0)
			flag1 = false;
	}
	if (flag1)
	{
		sort(c3, c3 + n);
		ll ans = 0;
		for (int i = n - 1; i >= n - n / 2; i--)
		{
			ans += c3[i];
		}
		cout << ans << '\n';
	}
	else if (flag2)
	{
		cout << p2() << '\n';
	}
	else
	{
		cout << dfst(0, 0, 0, 0) << '\n';
	}
	delete[] c1;
	delete[] c2;
	delete[] c3;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
