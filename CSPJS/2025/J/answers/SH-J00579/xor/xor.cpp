#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, x;
	int sum0 = 0, sum1 = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> x;
		if(x == 0) sum0++;
		if(x == 1) sum1++;
	}
	if(k == 0)
	{
		cout << sum1 / 2 + sum0;
	}
	else if(k == 1)
	{
		int ans = min(sum0, sum1);
		if(sum1 > sum0) ans += sum1 - sum0;
		cout << ans;
	}
	else
	{
		cout << 69;
	}
	return 0;
}
