#include<bits/stdc++.h>
using namespace std;
int n=0,a[100001],f1[100001],ans1,f2[100001],ans2;//f1是最长不上升子序列长度，f2是最长上升子序列长度
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin>>a[++n]);
	n--;
	f1[1]=ans1=1;
	for (int i=2;i<=n;i++)
	{
		int mx=0;
		for (int j=1;j<i;j++)
		{
			if (a[j]>=a[i])mx=max(mx,f1[j]);
		}
		f1[i]=mx+1;
		ans1=max(ans1,f1[i]);
	}
	f2[1]=ans2=1;
	for (int i=2;i<=n;i++)
	{
		int mx=0;
		for (int j=1;j<i;j++)
		{
			if (a[j]<a[i])mx=max(mx,f2[j]);
		}
		f2[i]=mx+1;
		ans2=max(ans2,f2[i]);
	}
	cout<<ans1<<'\n'<<ans2<<'\n';
	return 0;
}