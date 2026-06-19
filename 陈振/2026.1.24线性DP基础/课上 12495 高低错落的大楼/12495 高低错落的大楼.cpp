#include<bits/stdc++.h>
using namespace std;
int n,a[1001],f[1001],ans=1;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=1;
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=i-1;j>=1;j--)
		{
			if (a[j]<a[i])f[i]=max(f[i],f[j]+1);
			else break;
		}
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}