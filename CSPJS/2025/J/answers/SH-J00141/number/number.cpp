#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e6 + 11;
int n, a[N], l;
char s[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[++l] = s[i] - '0';
	sort(a + 1, a + l + 1);
	for (int i = l; i; i--)
		printf("%d", a[i]);
	return 0;
}
