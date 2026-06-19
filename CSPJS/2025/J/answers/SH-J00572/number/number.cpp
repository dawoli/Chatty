#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e6 + 5;
char c;
int a[N],cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while (cin >> c)
	{
		if ('0' <= c && c <= '9') a[++cnt] = c - '0';
	}
	sort(a + 1,a + cnt + 1,greater<int>());
	for (int i = 1; i <= cnt; i++) putchar(a[i] + '0');
	return 0;
}
