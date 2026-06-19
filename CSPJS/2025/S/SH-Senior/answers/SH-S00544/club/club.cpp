#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

struct sat{
	int a, b, c, vis;
}s[100007];
long long dp[207][103][103][103];
long long dp2[207][103][103];

bool cmp(sat x, sat y)
{
	return x.a > y.a;
}
bool cmp2(sat x, sat y)
{
	return x.b > y.b;
}

bool check(int n)
{
	for (int i = 1; i <= n; i++)
		if (s[i].c != 0)
			return 0;
	return 1;
}

bool check2(int n)
{
	for (int i = 1; i <= n; i++)
		if (s[i].c != 0 || s[i].b != 0)
			return 0;
	return 1;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		memset(s, sizeof(s), 0);
		memset(dp, sizeof(dp), 0);
		memset(dp2, sizeof(dp2), 0);
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> s[i].a >> s[i].b >> s[i].c;
		if (n < 200)//normal
		{
			for (int i = 1; i <= n; i++)
			{
				for (int a = 0;a <= n/2;a++)
				{
					for (int b = 0;b <= n/2;b++)
					{
						for (int c = 0;c <= n/2;c++)
						{
							if (a == 0 && b == 0 && c == 0)
								dp[i][a][b][c] = 0;
							else
							{
								long long ch1=0, ch2 =0, ch3 =0;
								if(a - 1 >= 0)
									ch1 = dp[i-1][a-1][b][c] + s[i].a;
								if(b - 1 >= 0)
									ch2 = dp[i-1][a][b-1][c] + s[i].b;
								if(c - 1 >= 0)
									ch3 = dp[i-1][a][b][c-1] + s[i].c;
								dp[i][a][b][c] = max(max(ch1, ch2),ch3);
							}
						}
					}
				}
			}
			cout<<dp[n][n/2][n/2][n/2];
		}
		else if (check2(n) == 1) //A
		{
			sort(s+1, s+n+1, cmp);
			long long ans = 0;
			for (int i = 1; i <= n/2; i++)
				ans += s[i].a;
			cout << ans;
		}
		else if (check(n) == 1)//B
		{
			int sum = 0;
			for (int i = 1; i <= n; i++)
			{
				if (s[i].a > s[i].b)
					sum++;
			}

			if (sum > n/2)
			{
				sort(s+1,s+n+1,cmp);
				long long ans = 0;
				for (int i = 1; i <= n/2; i++)
				{
					ans += s[i].a;
					s[i].vis = 2;
				}
				sort(s+1,s+n+1,cmp2);
				for (int i = 1; i <= n; i++)
				{
					if (s[i].vis != 2)
						ans += s[i].b;
				}
				cout << ans;
			}
			else
			{
				sort(s+1,s+n+1,cmp2);
				long long ans = 0;
				for (int i = 1; i <= n/2; i++)
				{
					ans += s[i].b;
					s[i].vis = 2;
				}
				sort(s+1,s+n+1,cmp);
				for (int i = 1; i <= n; i++)
				{
					if (s[i].vis != 2)
						ans += s[i].a;
				}
				cout << ans;
			}
		}
		cout << endl;
	}
	return 0;
} 
