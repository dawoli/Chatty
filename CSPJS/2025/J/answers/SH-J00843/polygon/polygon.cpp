#include <bits/stdc++.h>
using namespace std;

int n, a[5010];

bool check(int x, int y)
{
	int sum = 0, maxn = 0;
	for(int i = x; i <= y; i++)
	{
		sum += a[i];
		if(a[i] > maxn)
		{
			maxn = a[i];
		}	
	}
	if(sum > 2 * maxn)
	{
		return true;
	}
	return false;
}

int main()
{
	freopen("polygon", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int sum = 0, maxn = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	long long cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 3; j <= n; j++)
		{
			if(check(i, j))
			{
				if(cnt == 998244353)
				{
					cnt = 0;
				}
				cnt++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	cout << cnt << endl;
	return 0;
 } 
