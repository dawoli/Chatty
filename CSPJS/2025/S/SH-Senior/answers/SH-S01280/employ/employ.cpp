#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ll n, m, k;
	cin >> n >> m >> k;
	cout << (((n * (m + 2) - 9436 * 4956 * k) * k - m - n * k + m * 95) % 998244353 + 998244353) % 998244353;
	return 0;
}

