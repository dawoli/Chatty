#include <bits/stdc++.h>

using namespace std;

int n, m, a[1010], v[16][16], id = 0, x, ming;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i ++ )
	{
		scanf("%d", &a[i]);
	}
	x = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i ++ )
	{
		if (a[i] == x)
		{
			ming = i;
			break;
		}
	}
	for (int j = 1; j <= m; j ++ )
	{
		if (j & 1)
		{
			for (int i = 1; i <= n; i ++ )
			{
				id ++ ;
				v[i][j] =  id;
				if (id == ming)
				{
					printf("%d %d\n", j, i);
					return 0;
				}
			}
		}
		else
		{
			for (int i = n; i >= 1; i -- )
			{
				id ++ ;
				v[i][j] = id;
				if (id == ming)
				{
					printf("%d %d\n", j, i);
					return 0;
				}
			}
		}
	}
	
	return 0;
}
