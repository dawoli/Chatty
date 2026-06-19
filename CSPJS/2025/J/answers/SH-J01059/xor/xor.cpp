#include <bits/stdc++.h>
using namespace std;
int const m = 500001;
long long vis[m][m] = {0};
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, arr[m], max = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == k)
		{
			vis[i][i] = 1;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			int t = arr[i];
			for (int q = i + 1; q <= j; ++q)
			{
				t ^= arr[q];
			}
			if (t == k) vis[i][j] = 1;
		}
	}
	int test[m] = {1};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			bool a = true;
			for (int q = i; q <= j; ++q)
			{
				if(!test[q]) a = false;
			}
			if(vis[i][j] && a) max++;
			for (int q = i; q <= j; ++q)
			{
				test[q] = 0;
			}
		}
	}
	cout << max;
	return 0;
}
