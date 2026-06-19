#include <bits/stdc++.h>
using namespace std;
bool dp[110][200010];
int l[200010];
int cnt[200010];
bool ok[200010];
vector<int> s[200010];
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		memset(dp, false, sizeof(dp));
		dp[0][1] = true;
		memset(cnt, 0, sizeof(cnt));
		int n, k, q;
		scanf("%d %d %d", &n, &k, &q);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &l[i]);
			for(int j = 1; j <= l[i]; j++)
			{
				int x;
				scanf("%d", &x);
				s[i].push_back(x);
				cnt[x]++;
			}
		}
		for(int i = 1; i <= 100; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				int st = -1, en = 0;
				for(int m = 0; m < l[j]; m++)
				{
					if(dp[i - 1][s[j][m]] && cnt[s[j][m]] >= 2)
					{
						if(en < m)
						{
							for(int o = st; o <= en; o++)
							{
								dp[i][s[j][o]] = true;
							}
							st = m + 1;
							en = m + k - 1;
						}
						else
						{
							en = m + k - 1;
						}
					}
				}
				for(int m = st; m < min(l[j], en); m++)
				{
					dp[i][s[j][m]] = true;
				}
			}
		}
		for(int i = 1; i <= q; i++)
		{
			int r, c;
			scanf("%d %d", &r, &c);
			if(r > 100 || c > 200000) puts("0");
			else printf("%d\n", dp[r][c]);
		}
	}
	return 0;
}
