#include <bits/stdc++.h>
using namespace std;
int a[500005];
int n,k,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int e=0;
	for (int i=1;i<=n;i++)
	{
		int s=0;
		for (int j=i;j<=n;j++)
		{
			s=s^a[j];
			if (s==k)
			{
				if (i>e)
				{
					ans++;
					e=j;
				}
				else
				{
					if (j<=e)
					{
						e=j;
					}
				}
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
