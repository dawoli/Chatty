#include <bits/stdc++.h>
using namespace std;
int n,k,a,f[500005],sum[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a;
		sum[i]=(sum[i-1]^a);
		for (int j=i-1;j>=0;j--)
			if ((sum[i]^sum[j])==k)
			{
				f[i]=f[j]+1;
				break;
			}
		f[i]=max(f[i-1],f[i]);
	}
	cout<<f[n];
}
