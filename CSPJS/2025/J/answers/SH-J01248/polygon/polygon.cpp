#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5010] = {};
int b[5010] = {};
int ans = 0;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i] = a[i];
	}
	for (int nu=3;nu<=n;nu++)//选择小木棒个数
	{
		int l = nu;
		int len = 0;
		int maxn = -1e3;
		int id = 0;
		int t = 1;
		while (t<=n-nu+1)
		{
			for (int i=t;i<=n;i++)
			{
				if (b[i]!=-1)
				{
					len+=b[i];
					b[i] = -1;
					if (b[i]>maxn)
					{
						maxn = b[i];
						id = i;
					}
				}
			}
			if (len > maxn*2)ans++;
			t++;
		}
	 } 
	 cout<<ans;
	 return 0;
}
