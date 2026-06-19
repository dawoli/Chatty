#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long kai(int q, int w)
{
	if(w == 1) return q;
	long long sum1 = 0;
	for(int l = 1; l <= q - w + 1; l++)
	{
		sum1 += kai(q - l, w - 1);
		sum1 %= MOD;
	}
	return sum1;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = n - 1; i >= 3; i--)
	{
		int k = i;
		long long qwer = kai(n, k);
		sum += qwer;
		sum %= MOD;
	}
	cout << sum + 1;
	return 0;
}
