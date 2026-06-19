#include <bits/stdc++.h>
using namespace std;
int n, k, c = 0, t = -1, s;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	int a[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
	{
		if(i <= t)
			continue;
		s = a[i];
		if(s == k)
		{
			c++;
			continue;
		}
		for(int j = i + 1; j < n; j++)
		{
			s = (s ^ a[j]);
			if(s == k)
			{
				t = j;
				c++;
				break;
			}
		}
	}
	printf("%d\n", c);
	return 0;
}
