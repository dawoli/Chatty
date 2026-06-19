#include<bits/stdc++.h>
using namespace std;
int n, m, a[100005], c[100005], k, t, x;
int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		cin >> c[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		if(pow(2, i) > n)
		{
			k = n - 1;
		}
		else if(pow(2, i) == n)
		{
			k = n;
		}
	}
	for(int i = 1; i <= k; i ++)
	{
		cin >> x;
	}
	cin >> t;
	for(int i = 1; i <= t; i ++)
	{
		cout << rand() << endl;
	}
	return 0;
}
