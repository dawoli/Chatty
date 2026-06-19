#include<iostream>
#include <cstring>
using namespace std;
int l[100005];
int ss[200005];
int* s[100005];
int t[105][200005];
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int tt;
	cin >> tt;
	while (tt-->0)
	{
		int n;
		int kk;
		int q;
		scanf("%d%d%d",&n,&kk,&q);
		s[1] = ss;
		memset(t, 0, sizeof(t));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d",&l[i]);
			for (int j = 1; j <= l[i]; j++)
			{
				scanf("%d",&s[i][j]);
				if (s[i][j] == 1)
				{
					t[0][1] = 0x3f3f3f3f;
				}
			}
			if (i < n)
			{
				s[i + 1] = s[i] + l[i];
			}
		}
		for (int i = 1; i <= 100; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int cnt = 0;
				for (int k = 1; k <= l[j]; k++)
				{
					if (k > kk && t[i - 1][s[j][k - kk]] && t[i - 1][s[j][k - kk]] != j)
					{
						cnt--;
					}
					if (cnt)
					{
						if (t[i][s[j][k]] && t[i][s[j][k]] != j)
						{
							t[i][s[j][k]] = 0x3f3f3f3f;
						}
						else
						{
							t[i][s[j][k]] = j;
						}
					}
					if (t[i - 1][s[j][k]] && t[i - 1][s[j][k]] != j)
					{
						cnt++;
					}
				}
			}
		}
		for (int i = 1; i <= q; i++)
		{
			int r,c;
			cin >> r >> c;
			if (t[r][c])
			{
				puts("1");
			}
			else
			{
				puts("0");
			}
		}
	}
}
