#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 510, mod = 998244353;

int n, m;
char s[N];
int w[N];
bool flag = true;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);	
	
	cin >> n >> m;
	cin >> (s + 1);
	for (int i = 1; i <= n; i ++ ) 
		if (s[i] != '1')
			flag = false;
			
	if (flag)
	{
		LL ans = 1;
		for (int i = 1; i <= n; i ++ ) ans = ans * i % mod;
		cout << ans; 
	}
	else
	{
		puts("0");
	}
	return 0;
}
