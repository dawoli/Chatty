#include <bits/stdc++.h>
using namespace std;

char s[1000005];

int a[1000005];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	int n = 0;
	int strl = strlen(s + 1);
	for (int i = 1; i <= strl; i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[++n] = s[i] - '0';
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--)
		printf("%d", a[i]);
	puts("");
	return 0;
}
