#include <bits/stdc++.h>
using namespace std;

int n, k, sum;
int a[500005], vis[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	bool flag1 = true, flag2 = true;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != 1) flag1 = false;
		if (a[i] != 0 && a[i] != 1) flag2 = false;
	}
	if (k == 0 && flag1 == true)
	{
		cout << n/2;
		return 0;
	}
	else if (flag2 == true)
	{
		if (k == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == 0) sum++;
				else if (a[i] == a[i+1] && vis[i] == 0)
				{
					sum++;
					vis[i] = vis[i+1] = 1;
				}
			}
		}
		else if (k == 1)
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == 1) sum++;
			}
		}
		cout << sum;
	}
	return 0;
} 
