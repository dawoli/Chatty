#include<bits/stdc++.h>
using namespace std;

int a[200010];
long long f[2010][2010][2];
int last[1000010];
long long s[200010];

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++)cin >> a[i];
		memset(s,0,sizeof(s));
		memset(f,0,sizeof(f));
		for(int i = 1;i <= n;i++)if(a[i] == a[i - 1])s[i] = s[i - 1] + a[i];
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= i;j++)
			{
				if(last[a[i]] > 0)
				{
					f[i][j][0] = f[i - 1][last[a[i] + 1]][1] + a[i];
					f[i][j][1] = f[i - 1][last[a[i] + 1]][0] + a[i];
				}
				if(j == i)
				{
					f[i][j][0] = max(f[i - 1][1][0] + (a[i] == a[i - 1]) * a[i],f[i][j][0]);
					f[i][j][1] = max(f[i - 1][1][1] + (a[i] == a[i - 1]) * a[i],f[i][j][1]);
				}
				else
				{
					f[i][j][0] = max(f[i - 1][j][0] + (a[i] == a[i - 1]) * a[i],f[i][j][0]);
					f[i][j][1] = max(f[i - 1][j][1] + (a[i] == a[i - 1]) * a[i],f[i][j][1]);
				}
				last[a[i]] = i;
			}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= i;j++)
				cout << f[i][j][1] << " ";
			cout << endl;
		}
		long long ans = 0;
		for(int i = 1;i <= n;i++)
		{
			ans = max(ans,f[n][i][1]);
			ans = max(ans,f[n][i][0]);
		}
		cout << ans;
	}
    return 0;
}
