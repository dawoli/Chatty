#include<bits/stdc++.h>
using namespace std;
int n,a[1001],f[1001],ans;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	f[1]=ans=1;
	for (int i=2;i<=n;i++)
	{
		int mx=0;
		for (int j=1;j<i;j++)
		{
			if (a[j]<a[i])
			{
				mx=max(f[j],mx);
			}
		}
		f[i]=mx+1;
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}