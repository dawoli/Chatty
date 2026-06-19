#include <bits/stdc++.h>
using namespace std;

int n,r[100010];

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> r[i];
	}
	sort(r + 1,r + n + 1);
	int j = 1;
	for(int i = 1;i <= n;i++)
	{
		while(j <= n)
		{
			if(r[++j] > r[i])
			{
				break;
			}
		}
		if(j > n)
		{
			cout << n - i + 1;
			return 0;
		}
	}
	return 0;
}

