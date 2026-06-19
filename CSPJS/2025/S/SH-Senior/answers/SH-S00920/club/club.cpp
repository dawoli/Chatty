#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int T;
int n;
int w[N][4];
int s[4][N], cnt[4];
int ans;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &T);
	while (T -- )
	{
		cnt[1] = cnt[2] = cnt[3] = ans = 0;		
		
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= 3; j ++ )
				scanf("%d", &w[i][j]);
		
		for (int i = 1; i <= n; i ++ )
		{
			int mx = max(max(w[i][1], w[i][2]), w[i][3]);
			if (mx == w[i][1]) s[1][ ++ cnt[1]] = i;
			else if (mx == w[i][2]) s[2][ ++ cnt[2]] = i;
			else s[3][ ++ cnt[3]] = i;
			ans += mx;
		}
		
		if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {printf("%d\n", ans); continue; }
		int pr;
		if (cnt[1] > n / 2) pr = 1;
		else if (cnt[2] > n / 2) pr = 2;
		else pr = 3;
		
		for (int i = 1; i <= cnt[pr]; i ++ )
		{
			int j = s[pr][i], mn = w[j][pr];
			if (pr == 1) mn -= max(w[j][2], w[j][3]);
			else if (pr == 2) mn -= max(w[j][1], w[j][3]);
			else mn -= max(w[j][1], w[j][2]);
			s[pr][i] = mn;
		}
		sort(s[pr] + 1, s[pr] + 1 + cnt[pr]);
		for (int i = 1; i <= cnt[pr] - n / 2; i ++ ) ans -= s[pr][i];
		
		printf("%d\n", ans);
	}
	return 0;
} 
