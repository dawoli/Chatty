#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int n;
const int N = 2e6+10;
int T;

struct Stu { int a, b, c, fst, diff; }s[N];

int cnt_a, cnt_b, cnt_c;
int ans = 0;

inline void init()
{
	cnt_a = 0, cnt_b = 0, cnt_c = 0;
	ans = 0;
}

inline bool cmp(const Stu &x, const Stu &y) { return x.diff < y.diff; }

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> T;
	
	while (T--)
	{
		init();
		
		cin >> n;
		
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i].a >> s[i].b >> s[i].c;
			if (s[i].a >= s[i].b && s[i].b >= s[i].c)
			{
				s[i].fst = 1;
				s[i].diff = s[i].a - s[i].b;
				ans += s[i].a;
				cnt_a++;
			}
			else if (s[i].a >= s[i].c && s[i].c >= s[i].b)
			{
				s[i].fst = 1;
				s[i].diff = s[i].a - s[i].c;
				ans += s[i].a;
				cnt_a++;
			}
			else if (s[i].b >= s[i].c && s[i].c >= s[i].a)
			{
				s[i].fst = 2;
				s[i].diff = s[i].b - s[i].c;
				ans += s[i].b;
				cnt_b++;
			}
			else if (s[i].b >= s[i].a && s[i].a >= s[i].c)
			{
				s[i].fst = 2;
				s[i].diff = s[i].b - s[i].a;
				ans += s[i].b;
				cnt_b++;
			}
			else if (s[i].c >= s[i].a && s[i].a >= s[i].b)
			{
				s[i].fst = 3;
				s[i].diff = s[i].c - s[i].a;
				ans += s[i].c;
				cnt_c++;
			}
			else if (s[i].c >= s[i].b && s[i].b >= s[i].a)
			{
				s[i].fst = 3;
				s[i].diff = s[i].c - s[i].b;
				ans += s[i].c;
				cnt_c++;
			}
		}
		// 如果超出了约束 
		if (cnt_a > n / 2)
		{
			sort(s+1, s+n+1, cmp);
			int pos = 0;
			while (cnt_a > n / 2)
			{
				if (s[++pos].fst == 1)
				{
					cnt_a--;
					ans -= s[pos].diff;
				}
			}
		}
		if (cnt_b > n / 2)
		{
			sort(s+1, s+n+1, cmp);
			int pos = 0;
			while (cnt_b > n / 2)
			{
				if (s[++pos].fst == 2)
				{
					cnt_b--;
					ans -= s[pos].diff;
				}
			}
		}
		if (cnt_c > n / 2)
		{
			sort(s+1, s+n+1, cmp);
			int pos = 0;
			while (cnt_c > n / 2)
			{
				if (s[++pos].fst == 3)
				{
					cnt_c--;
					ans -= s[pos].diff;
				}
			}
		}
		cout << ans << '\n';
	}
}
