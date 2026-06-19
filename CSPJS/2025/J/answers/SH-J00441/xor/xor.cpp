#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k;
struct cocktail
{
	int l, r;
	int siz;
};

bool cmp(cocktail x, cocktail y)
{
	if (x.r != y.r)
	{
		return x.r < y.r; 
	}
	return x.siz < y.siz;
}

int a[1001], pre[1001];
cocktail b[1000001];

void B()
{
	int cnt0 = 0, cnt1 = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] == 0)
		{
			cnt0 += 1;
		}
		else
		{
			cnt1 += 1;
		}
	}
	if (k == 1)
	{
		cout << cnt1;
	}
	else
	{
		int cnt11 = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] == 1 && a[i + 1] == 1)
			{
				cnt11 += 1;
				i += 1;
			}
		}
		cout << cnt0 + cnt11;
	}
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k; 
	int maxn = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		maxn = max(maxn, a[i]);
		pre[i] = pre[i - 1] ^ a[i];
	}
	if (maxn == 1)
	{
		B();
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j <= n; ++j)
		{
			int num = pre[j] ^ pre[i - 1];
			if (num == k)
			{
				cnt += 1;
				b[cnt].l = i;
				b[cnt].r = j;
				b[cnt].siz = j - i + 1;
			}
		}
	}
	sort(b + 1, b + cnt + 1, cmp);
	int last = 0, ans = 0;
	for (int i = 1; i <= cnt; ++i)
	{
		if (b[i].l > last)
		{
			last = b[i].r;
			ans += 1;
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
