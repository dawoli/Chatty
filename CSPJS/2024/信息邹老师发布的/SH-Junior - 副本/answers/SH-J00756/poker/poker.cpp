#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
bool flag[4][15];
char a[4] = {'D', 'C', 'H', 'S'};
char b[15] = {' ', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', ' '};

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	char c;
	scanf("%d%c", &n, &c);
	for (int i = 1; i <= n; i++)
	{
		char x, y;
		scanf("%c%c%c", &x, &y, &c);
		for (int j = 0; j < 4; j++)
		{
			if (x == a[j])
			{
				for (int k = 1; k <= 13; k++)
				{
					if (y == b[k])
					{
						flag[j][k] = true;
						break;
					}
				}
				break;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			if (!flag[i][j])
			{
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
