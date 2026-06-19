#include<iostream>
#include <cstdio>
using namespace std;
int T,n,k[] = {6,2,5,5,4,5,6,3,7,6};
int a[] = {-1,-1,1,7,4,2,6,8,10,18,23,20,60,80,88,108,202,188,208,288,387};
long long ans = 9e18;
void dfs(int x)
{
	if (n == 0)
	{
		ans = min(1ll*x,ans);
		return ;
	}
	if (n < 2) return;
	for (int i = 0; i <= 9; i++)
	{
		if (x == 0 && i == 0) continue;
		if (n < k[i]) continue;
		if (n-k[i] < 2)  continue;
		n -= k[i];
		dfs(x*10+i);
		n += k[i];
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> T;
	while (T--)
	{
		cin >> n;
		if (n < 2)
		{
			cout << -1 << endl;
			continue;
		}
		if (2 <= n && n <= 7)
		{
			for (int i = 1; i <= 9; i++)
				if (k[i] == n)
				{
					cout << i << endl;
					break;
				}
			continue;
		}
		if (n % 7 == 0)
		{
			for (int i = 1; i <= n/7; i++) cout << "8";
			cout << endl;
			continue;
		}
		if ((n-1) % 7 == 0)
		{
			int x = (n-1) / 7;
			cout << "10";
			for (int i = 1; i <= x-1; i++) cout << "8";
			cout << endl;
			continue;
		}
		if (n <= 20)
		{
			cout << a[n] << endl;
			continue;
		}
		dfs(0);
		if (ans == 9e18) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
} 
