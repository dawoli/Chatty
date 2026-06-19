#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
const int mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=0;i<(1<<n);i++)
	{
		int maxn=0,sum=0;
		for (int j=0;j<n;j++)
		{
			if (i&(1<<j))
			{
				maxn=max(maxn,a[j+1]);
				sum+=a[j+1];
			}
		}
		if (sum>maxn*2)
			ans++;
		ans%=mod;
	}
	cout<<ans;
}
