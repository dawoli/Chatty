#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n, m;
char s[505];
int c[505];

void A()
{
	bool flag = false;
	for (int i = 1; i <= n; i++)
		if (s[i] == '1')
		{
			flag = true;
			break;
		}
	if (!flag)
	{
		puts("0");
		return;
	}
	int not0;
	for (int i = 1; i <= n; i++)
		if (c[i] != 0)
			not0++;
	long long ans = not0;
	for (int i = 2; i <= n; i++)
	{
		ans = ans * (n - i + 1) % MOD;
	}
	printf("%d\n", ans);
}
	

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
	}
	if (m == 1)
		A();
}
