#include <bits/stdc++.h>
using namespace std;
int const m = 998244353;
int n, arr[5005];

bool cmp(int a, int b)
{
	return a > b;
}

void dfs(int a, int &max)
{
	int t = arr[a] + arr[a-1];
	for (int i = a; i >= 0; --i)
	{
		t += arr[a-1];
		if(t > 2*arr[a]) 
		{
			max++;
			if (max > m) max % m;
		}	
	}
	if (a < n - 2) dfs(a - 1, max);
}

int main()
{
	int max = 0;
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n, cmp);
	dfs(0, max);
	cout << max;
	return 0;
}
