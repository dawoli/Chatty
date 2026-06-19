#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100020],f[100020],ans;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=a[i];
	}
	sort(a+1,a+n+1);
	sort(f+1,f+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]>f[i]&&a[j]!=100001)
			{
				f[i]=0;
				a[i]=0;
				a[j]=100001;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
