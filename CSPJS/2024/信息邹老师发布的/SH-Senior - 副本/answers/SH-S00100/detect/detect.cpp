#include <bits/stdc++.h>
using namespace std;
int n, m, L, V;
int d[100010], v[100010], a[100010];
int p[100010];
pair<int, int> nums[100010];
bool check_small20()
{
	return n <= 20;
}
void slove_small20()
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(p[j] >= d[i])
			{
				int now_v = v[i] * v[i] + 2 * a[i] * (p[j] - d[i]);
				int tmp_num = V * V;
				if(now_v > tmp_num)
				{
					cnt++;
					break;
				}
			}
		}
	}
	printf("%d ", cnt);
	int ans = 0;
	for(int choose = 0; choose < (1 << m); choose++)
	{
		int tmp_cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(choose & (1 << (j - 1)))
				{
					if(p[j] > d[i])
					{
						int now_v = v[i] * v[i] + 2 * a[i] * (p[j] - d[i]);
						int tmp_num = V * V;
						if(now_v > tmp_num)
						{
							tmp_cnt++;
							break;
						}
					}
				}
			}
		}
		// cout << tmp_cnt;
		if(cnt == tmp_cnt)
		{
			int u = choose;
			int c = 0;
			while(u)
			{
				c += u & 1;
				u >>= 1;
			}
			ans = max(ans, m - c);
		}
	}
	printf("%d\n", ans);
}
bool check_all0()
{
	for(int i = 1; i <= n; i++)
		if(a[i] != 0) return false;
	return true;
}
void slove_all0()
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int j = m;
		if(p[j] >= d[i])
		{
			int now_v = v[i];
			int tmp_num = V;
			if(now_v > tmp_num)
			{
				cnt++;
			}
		}
	}
	printf("%d %d\n", cnt, m - (cnt == 0 ? 0 : 1));
}
bool check_great0()
{
	for(int i = 1; i <= n; i++)
		if(a[i] <= 0) return false;
	return true;
}
void slove_great0()
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int j = m;
		if(p[j] >= d[i])
		{
			int now_v = v[i] * v[i] + 2 * a[i] * (p[j] - d[i]);
			int tmp_num = V * V;
			if(now_v > tmp_num)
			{
				cnt++;
			}
		}
	}
	printf("%d %d\n", cnt, m - (cnt == 0 ? 0 : 1));
}
bool check_less0()
{
	for(int i = 1; i <= n; i++)
		if(a[i] >= 0) return false;
	return true;
}
void slove_less0()
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int leave_pos = v[i] * v[i] / a[i] + d[i];
		nums[i] = {d[i], leave_pos};
	}
	sort(nums + 1, nums + n + 1);
//	for(int i = 1; i <= n; i++)
//	{
//		int le = 1, ri = m;
//		while(le < ri)
//		{
//			int mid = (le + ri) >> 1;
//			if(p[mid] > )
//		}
//	}
	puts("0 0");
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d %d", &n, &m, &L, &V);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d %d %d", &d[i], &v[i], &a[i]);
		}
		for(int i = 1; i <= m; i++)
		{
			scanf("%d", &p[i]);
		}
		if(check_small20())
		{
			slove_small20();
		}
		else if(check_all0())
		{
			slove_all0();
		}
		else if(check_great0())
		{
			slove_great0();
		}
		else if(check_less0())
		{
			slove_less0();
		}
	}
	return 0;
}
