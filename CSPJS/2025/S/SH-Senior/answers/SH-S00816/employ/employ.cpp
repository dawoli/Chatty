#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,k;
	long long ans = 1;
	string s;
	cin >> n >> m;
	cin >> s;
	for (int i = 1;i<=n;i++) cin >> k;
	for (int i = n;i>=1;i--)
	{
		ans = ans * i;
		ans = ans % 998244353;
	}
	cout <<ans;
	return 0;
} 
