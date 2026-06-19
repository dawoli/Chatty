#include<bits/stdc++.h>
using namespace std;
int n,a[10001],f[10001],s[10001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=a[i];
		for(int j=1;j<i;j++)
		{
			if(a[i]>=a[j]&&f[i]<f[j]+1)
			{
				f[i]=f[j]+1;
				s[i]=s[j]+a[i];
			}
		}
		cout<<s[i]<<" ";
	}
	return 0;
}
