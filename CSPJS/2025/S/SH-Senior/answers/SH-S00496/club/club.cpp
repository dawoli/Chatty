// T1 club
// AC
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, a[MAXN][4];

/*
int mem[205][205][205];
int dfs(int now, int na, int nb)
{
	if (mem[now][na][nb] != -1)
		return mem[now][na][nb];
	if (now == n + 1)
		return 0;
	
	int nc = now - na - nb - 1;
	int ans = 0;
	if (na + 1 <= n / 2)
		ans = max(ans, dfs(now + 1, na + 1, nb) + a[now][1]);
	if (nb + 1 <= n / 2)
		ans = max(ans, dfs(now + 1, na, nb + 1) + a[now][2]);
	if (nc + 1 <= n / 2)
		ans = max(ans, dfs(now + 1, na, nb) + a[now][3]);
	return mem[now][na][nb] = ans;
}
*/

int find_max(int a, int b, int c)
{
	if (a >= b && a >= c)
		return 1;
	if (b >= a && b >= c)
		return 2;
	return 3;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int TT;
	cin >> TT;
	while (TT--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		
		/*
		// solve case 1-11
		if (n <= 200)
		{
			
			memset(mem, -1, sizeof(mem));
			cout << dfs(1, 0, 0) << "\n";
			continue;
		}
		
		// solve case 12-14
		bool c_all_zero = true;
		for (int i = 1; i <= n; i++)
		{
			if (a[i][3] != 0)
			{
				c_all_zero = false;
				break;
			}
		}
		if (c_all_zero)
		{
			
			int my_offset[MAXN]{0};
			long long ans = 0;
			for (int i = 1; i <= n; i++)
			{
				my_offset[i] = a[i][1] - a[i][2];
				ans += a[i][1];
			}
			sort(my_offset + 1, my_offset + 1 + n);
			for (int i = 1; i <= n / 2; i++)
				ans -= my_offset[i];
			cout << ans << "\n";
			continue;
		}
		*/
		
		// in fact, only one group may exceed the limit
		// first, get everyone maximum
		// movint all the spare people to another ONE group is always OK
		// find the minimum loss and do it
		long long ans = 0;
		int lst_a[MAXN]{0}, lst_b[MAXN]{0}, lst_c[MAXN]{0};
		int cnt_a = 0, cnt_b = 0, cnt_c = 0;
		
		for (int i = 1; i <= n; i++)
		{
			int res = find_max(a[i][1], a[i][2], a[i][3]);
			ans += a[i][res];
			if (res == 1)
				lst_a[++cnt_a] = i;
			else if (res == 2)
				lst_b[++cnt_b] = i;
			else
				lst_c[++cnt_c] = i;
		}
		
		if (cnt_a <= n / 2 && cnt_b <= n / 2 && cnt_c <= n / 2)
		{
			cout << ans << "\n";
			continue;
		}
		
		int my_offset[MAXN]{0};
		int people_to_move = 0;
		if (cnt_a > n / 2)
		{
			people_to_move = cnt_a - n / 2;
			for (int i = 1; i <= cnt_a; i++)
				my_offset[i] = min(a[lst_a[i]][1] - a[lst_a[i]][2], a[lst_a[i]][1] - a[lst_a[i]][3]);
			sort(my_offset + 1, my_offset + 1 + cnt_a);
			for (int i = 1; i <= people_to_move; i++)
				ans -= my_offset[i];
		}
		else if (cnt_b > n / 2)
		{
			people_to_move = cnt_b - n / 2;
			for (int i = 1; i <= cnt_b; i++)
				my_offset[i] = min(a[lst_b[i]][2] - a[lst_b[i]][1], a[lst_b[i]][2] - a[lst_b[i]][3]);
			sort(my_offset + 1, my_offset + 1 + cnt_b);
			for (int i = 1; i <= people_to_move; i++)
				ans -= my_offset[i];
		}
		else
		{
			people_to_move = cnt_c - n / 2;
			for (int i = 1; i <= cnt_c; i++)
				my_offset[i] = min(a[lst_c[i]][3] - a[lst_c[i]][1], a[lst_c[i]][3] - a[lst_c[i]][2]);
			sort(my_offset + 1, my_offset + 1 + cnt_c);
			for (int i = 1; i <= people_to_move; i++)
				ans -= my_offset[i];
		}
		cout << ans << "\n";
	}
}
