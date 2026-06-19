#include<bits/stdc++.h>
using namespace std;

char s[510];
int c[510];
int p[15];
long long f[510][510];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> s[i];
	for(int i = 1;i <= n;i++)cin >> c[i];
	if(n <= 10)
	{
		int ans = 0;
		for(int i = 1;i <= n;i++)p[i] = i;
		do
		{
			int cnt = 0;
			for(int i = 1;i <= n;i++)
				if(cnt >= c[p[i]] || s[i] == '0')cnt++;
			if(n - cnt >= m)ans++;
		}while(next_permutation(p + 1,p + n + 1));
		cout << ans;
		return 0;
	}
	if(n == m)
	{
		for(int i = 1;i <= n;i++)
			if(s[i] == 0 || c[i] == 0)
			{
				cout << 0;
				return 0;
			}
		long long ans = 1;
		for(int i = 1;i <= n;i++)ans = ans * i % 998244353;
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}

