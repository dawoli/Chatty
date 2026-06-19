#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
char s[N],t[N];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	int n = strlen(s),m = 0;
	for (int i = 0; i < n; ++i) if ('0' <= s[i] && s[i] <= '9') t[m++] = s[i];
	sort(t, t + m, greater<char>());
	puts(t);
	return 0;
}