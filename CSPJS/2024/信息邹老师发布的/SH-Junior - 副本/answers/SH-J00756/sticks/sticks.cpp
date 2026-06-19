#include <bits/stdc++.h>
using namespace std;

int T, n;
int sn[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int len, num[100005];

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%d", &T);
	for (;T--;)
	{
		len = 0;
		memset(num, 0, sizeof(num));
		scanf("%d", &n);
		if (n < 2)
		{
			printf("-1\n");
			continue;
		}
		if (n < 7)
		{
			for (int i = 1; i <= 9; i++)
			{
				if (sn[i] == n)
				{
					printf("%d\n", i);
					break;
				}
			}
			continue;
		}
		while (n >= 7)
		{
			n -= 7;
			num[++len] = 8;
		}
		if (n == 1)
		{
			num[len] = 0;
			num[++len] = 1;
		}
		else
		{
			for (int i = 1; i <= 9; i++)
			{
				if (sn[i] == n)
				{
					num[++len] = i;
					break;
				}
			}
		}
		int p = len;
		while (p > 1)
		{
			int flag = false;
			for (int i = 0; i < num[p]; i++)
			{
				if (sn[i] > sn[num[p]] && (i != 0 || p != len))
				{
					flag = true;
					int d = sn[i] - sn[num[p]];
					num[p] = i;
					for (int j = 0; j < 8; j++)
					{
						if (7 - sn[j] == d)
						{
							num[p - 1] = j;
							break;
						}
					}
					break;
				}
			}
			if (!flag)
			{
				break;
			}
			p--;
		}
		for (int i = len; i >= 1; i--)
		{
			printf("%d", num[i]);
		}
		printf("\n");
	}
	return 0;
}
