#include <bits/stdc++.h>
using namespace std;

long long n, m, a[110];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	long long R = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int cnt = 1;
	for(long long i = 1; i <= m; i++)
	{
		if(i % 2 == 0)
		{
			for(long long j = n; j >= 1; j--)
			{
				if(a[cnt] == R)
				{
					cout << i << ' ' << j << endl;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				cnt++;
			}
		}
		else
		{
			for(int j = 1; j <= n; j++)
			{
				if(a[cnt] == R)
				{
					cout << i << ' ' << j << endl;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				cnt++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
