#include <bits/stdc++.h>
using namespace std;

int n, k, a[500005], b[500005], ans = 0;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int ansa = a[i], ansai = 0, cnt = 0;
		while (ansa != 0)
		{
			ansai += ansa % 2 * pow(10, cnt);
			ansa /= 2;
			cnt += 1;
		}
		b[i] = ansai;
		if (b[i] == 0) ans++;
	}
	/*
	int ans = b[1];
	for (int i = 2; i <= n; i++)
	{
		ans ^= b[i];
	}
	int wei = 0;
	while ()
	{
		
	}
	*/
	cout << ans << endl;
	return 0;
} 
