#include <bits/stdc++.h>
using namespace std;
int n, m, t, g;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	t = n * m;
	int s[t];
	for(int i = 0; i < t; i++)
		scanf("%d", &s[i]);
	g = s[0];
	sort(s, s + t);
	t--;
	for(int i = 0; i < m; i++)
	{
		if(i % 2 == 0)
		{
			for(int j = 0; j < n; j++)
			{
				if(s[t] == g)
				{
					printf("%d %d\n", i + 1, j + 1);
					return 0;
				}
				t--;
			}
		}
		else
		{
			for(int j = n - 1; j >= 0; j--)
			{
				if(s[t] == g)
				{
					printf("%d %d\n", i + 1, j + 1);
					return 0;
				}
				t--;
			}
		}
	}
}
