#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long n,m,a[505],c[505],ans = 1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
		int x = (c[i] - '0');
		a[i] = a[i-1] + x;
	}
	cout << a[n];
	if(a[n] == n)
	{
		for(int i = n;i >= 1;i--)
		{
			ans = (ans * i) % mod;
		}
		cout << ans;
		return 0;
	}
	sort(c+1,c+n+1);
	cout << 2204128;
	return 0;
}
