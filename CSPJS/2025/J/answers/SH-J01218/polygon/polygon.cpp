#include <bits/stdc++.h>
#define N 5005
#define mod 998244353
using namespace std;
typedef long long ll;

int n,a[N];
int ans;
bool choose[N];
void check()
{
	int sum = 0,maxn = 0,tot = 0;
	for (int i = 1;i <= n;i++)
	{
		if (choose[i])
		{
			tot++;
			sum += a[i];
			maxn = max(maxn,a[i]);
		}
	}
	maxn *= 2;
	if (sum > maxn && tot >= 3) ans = (ans + 1) % mod;
	return;
}

void dfs(int pos)
{
	if (pos > n)
	{
		check();
		return;
	}
	choose[pos] = 1;
	dfs(pos + 1);
	choose[pos] = 0;
	dfs(pos + 1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	dfs(1);
	cout << ans << endl;
	return 0;
}
