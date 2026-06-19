#include<iostream>
#include <cstring>
#include<algorithm> 
using namespace std;
long long a[200005];
long long pre[200005];
long long mx[1000005];
long long dp[200005];
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	long long tt;
	cin>>tt;
	while(tt-->0)
	{
		long long n;
		cin>>n;
		for (long long i = 1; i <= n; i++)
		{
			cin>>a[i];
		}
		for (long long i = 2; i <= n; i++)
		{
			if (a[i] == a[i - 1])
			{
				pre[i] = pre[i - 1] + a[i];
			}
			else
			{
				pre[i] = pre[i - 1];
			}
		}
		memset(mx, -0x3f, sizeof(mx));
		long long mxd = 0;
		long long result = 0;
		for (long long i = 1; i <= n; i++)
		{
			dp[i] = max(mx[a[i]] + pre[i - 1] + a[i], mxd + pre[i - 1]);
			mx[a[i - 1]] = max(mx[a[i - 1]], dp[i] - pre[i]);
			mxd = max(mxd, dp[i] - pre[i]);
			result = max(result, dp[i] + pre[n] - pre[i]);
		}
		cout << result << endl;
	}
}
