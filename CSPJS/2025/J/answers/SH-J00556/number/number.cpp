#include <bits/stdc++.h>

using namespace std;

char s[1000010];
int n, a[16];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i ++ )
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			int x = s[i] - '0';
			a[x] ++ ;
		}
	}
	for (int i = 9; i >= 0; i -- )
	{
		while (a[i])
		{
			printf("%d", i);
			a[i] -- ;
		}
	}
	return 0;
}
