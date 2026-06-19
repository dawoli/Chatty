#include <bits/stdc++.h>
using namespace std;
int T;
int n;
long long A[200010];
bool color[200010];
bool check_small20()
{
	return (n <= 20);
}
void slove_small20()
{
	long long ans = 0;
	for(int colors = 0; colors < (1 << n); colors++)
	{
		long long tmp_cnt = 0;
		memset(color, false, sizeof(color));
		for(int i = 1; i <= n; i++)
		{
			if(colors & (1 << (i - 1)))
			{
				color[i] = true;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i - 1; j >= 1; j--)
			{
				if(color[i] == color[j])
				{
					if(A[i] == A[j]) tmp_cnt += A[i];
					break;
				}
			}
		}
		ans = max(ans, tmp_cnt);
	}
	printf("%lld\n", ans);
}
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &A[i]);
		}
		if(check_small20())
		{
			slove_small20();
		}
	}
	return 0;
}
