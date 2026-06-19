#include <bits/stdc++.h>
using namespace std;
#define N 35
int n, a[N], ans;
bool vis[N];
bool isPrime(int x)
{
	if(x < 2)
		return false;
	for(int i = 2; i*i <= x; ++i)
		if(x%i == 0)
			return false;
	return true;
}
void dfs(int k)
{
	if(k > n)
	{
		if(isPrime(a[k-1]+a[1]))
			ans++;
		return;
	}
	for(int i = 1; i <= n; ++i) 
	{
		if(!vis[i] && isPrime(a[k-1]+i))
		{
			vis[i] = true;
			a[k] = i;
			dfs(k+1);
			vis[i] = false;
		}
	}
}
int main()
{
	cin >> n;
	dfs(1);
	cout << ans;
	return 0;
}
