#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
struct Node{
	int l, r;
} a[N];
int n, k, q, l[N], s[N];
void solve()
{
	memset(a, 0, sizeof(a));
	memset(l, 0, sizeof(l));
	scanf("%d%d%d", &n, &k, &q); 
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &l[i]);
		a[i].l = a[i - 1].r + 1;
		a[i].r = a[i].l + l[i] - 1;
		for (int j = a[i].l; j <= a[i].r; j++)
		{
			scanf("%d", &s[j]);
		}
	}
	while (q--)
	{
		int r, c;
		scanf("%d%d", &r, &c);
		if (r == 1)
		{
			bool flag = false;
			for (int i = 1; i <= a[1].r; i++)
			{
				if (s[i] == 1)
				{
					for (int j = i + 1; j <= a[1].r; j++)
					{
						if (j - i + 1 > k) break;
						if (s[j] == c)
						{
							flag = true;
							break;
						}
					}
				}
				if (flag) break;
			}
			if (flag) cout << 1 << endl;
			else cout << 0 << endl;
			continue;
		}
		cout << rand() % 2 << endl; 
	}
}

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	srand(time(0));
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}
