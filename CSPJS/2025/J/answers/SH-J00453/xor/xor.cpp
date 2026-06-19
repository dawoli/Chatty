#include<bits/stdc++.h>
using namespace std;

const int N = 500005, M = 1000005;
int a[N], s[N], c[M], de[M];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, ans = 0, cnt = 0;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	s[0] = 0;
	c[0] = 1;
	de[++cnt] = 0;
	for(int i = 1; i <= n; ++i) s[i] = s[i - 1] ^ a[i];
	for(int i = 1; i <= n; ++i)
	{
		int cr = s[i];
		if(c[k ^ cr] == 1)
		{
			++ans;
			for(int j = 1; j <= cnt; ++j)
			{
				int x = de[j];
				c[x] = 0;
			}
			cnt = 0;
		}
		c[cr] = 1;
		de[++cnt] = cr;
	}
	printf("%d", ans);
}
