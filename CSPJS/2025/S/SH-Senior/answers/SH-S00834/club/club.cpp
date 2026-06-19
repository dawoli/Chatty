#include <iostream>
#include <algorithm>
using namespace std;

int t, n, ans, cnt[5], num[5], c[20];
bool allzero, partzero;

struct Club
{
	int a, b, c;/*, da, db, dc*/
}d[100010];

bool cmp1(Club x, Club y)
{
	return x.a > y.a;
}

bool cmp2(Club x, Club y)
{
	return x.a - x.b > y.a - y.b;
}

bool cmp3(Club x, Club y)
{
	//int dxa = x.a * 2 - x.b - x.c, dya = y.a * 2 - y.b - y.c;
	//if (dxa >= dxb && dxa >= dxc)
	//{
	//	return dx > dy;
	//}
	//if (dx )
	return x.a - x.b - x.c > y.a - y.b - y.c;
}
/*
bool cmp4(Club x, Club y)
{
	return x.b - x.a - x.c > y.b - y.a - y.c;
}
*/
void dfs(int step)
{
	/*if (cnt[1] > n / 2 || cnt[2] > n / 2 || cnt[3] > n / 2)
	{
		return;
	}*/
	if (step > n)
	{
		num[1] = num[2] = num[3] = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (c[i] == 1) 
			{
				cnt[1] += d[i].a;
				num[1]++;
			}
			else if (c[i] == 2)
			{
				cnt[2] += d[i].b;
				num[2]++;
			}
			else
			{
				cnt[3] += d[i].c;
				num[3]++;
			}
			//cnt[c[i]] += a[i][c[i]];
		}
		if (num[1] > n / 2 || num[2] > n / 2 || num[3] > n / 2)
		{
			return;
		}
		ans = max(ans, cnt[1] + cnt[2] + cnt[3]);
		return;
	}
	c[step] = 1;
	//cnt[1]++;
	dfs(step + 1);
	//cnt[1]--;
	c[step] = 2;
	//cnt[2]++;
	dfs(step + 1);
	//cnt[2]--;
	c[step] = 3;
	//cnt[3]++;
	dfs(step + 1);
	//cnt[3]--;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		ans = 0;
		allzero = partzero = true;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> d[i].a >> d[i].b >> d[i].c;
			if (d[i].c != 0)
			{
				allzero = partzero = false;
			}
			if (d[i].b != 0)
			{
				allzero = false;
			}
			//d[i].da = d[i].a * 2 - d[i].b - d[i].c;
			//d[i].db = d[i].b * 2 - d[i].a - d[i].c;
			//d[i].dc = d[i].c * 2 - d[i].a - d[i].b;
		}
		if (allzero)
		{
			sort(d + 1, d + n + 1, cmp1);
			for (int i = 1; i <= n / 2; i++)
			{
				ans += d[i].a;
			}
			cout << ans << endl;
			continue;
		}
		if (partzero)
		{
			sort(d + 1, d + n + 1, cmp2);
			for (int i = 1; i <= n / 2; i++)
			{
				ans += d[i].a;
			}
			for (int i = n / 2 + 1; i <= n; i++)
			{
				ans += d[i].b;
			}
			cout << ans << endl;
			continue;
		}
		/*sort(d + 1, d + n + 1, cmp3);
		for (int i = 1; i <= n / 2; i++)
		{
			if ((d[i].a > d[i].b) && (d[i].a > d[i]c))
			{
				ans += d[i].a;
			}
			else
			{
				start = i;
				break;
			}
		}
		sort(d + start, d + n + 1, cmp4);
		for (int i = start; i <= min(n, start + n / 2); i++)
		{
			if (d[i].b >= d[i].a && d[i].b >= d[i]c)
			{
				ans += d[i].b;
			}
			else
			{
				start = i;
				break;
			}
		}
		for (int i = start; i <= n; i++)
		{
			ans += d[i].c;
		}
		cout << ans << endl;*/
		/*for (int i = 1; i <= n; i++)
		{
			cout << d[i].a << " " << d[i].b << " " << d[i].c << endl;
		}*/
		if (n <= 15)
		{
			ans = 0;
			dfs(1);
			cout << ans << endl;
			continue; 
		}
		/*sort(d + 1, d + n + 1, cmp1);
		for (int i = 1; ; i++)
		{
			if (d[i].da < d[i].db || d[i].da < d[i].db || i > n / 2)
			{
				break;
			}
			ans += d[i].a;
		}
		sort(d + 1, d + n + 1, cmp2);
		for (int i = 1; ; i++)
		{
			if (d[i].da < d[i].db || d[i].da < d[i].db || i > n / 2)
			{
				break;这个蒟蒻第一题都不会做了。 
			}
			ans += d[i].a;
		}
		sort(d + 1, d + n + 1, cmp3);
		for (int i = 1; ; i++)
		{
			if (d[i].da < d[i].db || d[i].da < d[i].db || i > n / 2)
			{
				break;
			}
			ans += d[i].a;
		}*/
		sort(d + 1, d + n + 1, cmp3);
		for (int i = 1; i <= n; i++)
		{
			if (i > n / 2)
			{
				ans += max(d[i].b, d[i].c);
			}
			else
			{
				ans += max(d[i].a, max(d[i].b, d[i].c));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
