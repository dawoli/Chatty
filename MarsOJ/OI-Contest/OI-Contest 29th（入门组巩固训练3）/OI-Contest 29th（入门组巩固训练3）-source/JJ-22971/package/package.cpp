#include <bits/stdc++.h>
using namespace std;
int n, m, k, v[1000111], t[10011], w[10011];
long long s;
int minn(int r, int l)
{
	int minm = 2147483647;
	for(int i = r; i < l; i++)
	{
		minm = min(minm, v[i]);
	}
	return minm;
}
int id(int a)
{
	for(int i = 0; i < m; i++)
	{
		if(v[i] == a)
		{
			return i;
		}
	}
}
int main()
{
	freopen("package.in", "r", stdin);
	freopen("package.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
		cin >> v[i];
	for(int i = 0; i < n; i++)
	{
		cin >> t[i];
		cin >> w[i];
		s += w[i];
	}
	long long sum = 0;
	int minm = minn(0, m);
	int ida = id(minn);
	sum += s / v[ida] * minm;
	ida = id(s % minm);
	sum += v[ida];
	cout << sum;
	return 0;
}
