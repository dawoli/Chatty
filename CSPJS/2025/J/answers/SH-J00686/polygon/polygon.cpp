#include <iostream>
using namespace std;

long long int a[50005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];		
	}
	long long int ans = 0;
	for (int i = 1;i <= (1 << (n+1));i+=2)
	{
		long long int cnt = 0;
		long long int maxn = 0;
		long long int sum = 0;
		for (int j = 1;j <= n;j++)
		{
			if (((i >> j) & 1))
			{
				sum += a[j];
				maxn = max(maxn,a[j]);
				cnt ++;
			}
		}
		if (sum > maxn * 2 && cnt >= 3)
			ans ++;
		ans %= 998224353;
	}
	cout << ans << endl;
	return 0;
}
