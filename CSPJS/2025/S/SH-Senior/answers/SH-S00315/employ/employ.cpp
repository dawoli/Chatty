#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 505, mod = 998244353;



int n, m; string s;
int c[N];


signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> s;
	
	int ans = 1, tmp = n, cnt = 0;
	for (int i = 1; i <= n ;++ i)
	{
		cin >> c[i];
	}
	
	sort(c + 1, c + n + 1);
	
	for (int i = n; i >= 1; -- i)
	{
		if(c[i] >= cnt) cnt ++, tmp --;
	}
		
	for (;tmp > 0; -- tmp)
	{
		ans = (ans * tmp) % mod;
	}
	
	cout << ans << endl;
	
	return 0;
 } 
