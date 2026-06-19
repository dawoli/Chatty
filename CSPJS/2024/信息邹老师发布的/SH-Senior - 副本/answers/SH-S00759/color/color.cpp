#include<bits/stdc++.h>
using namespace std;
int n,a[100001],maxn=0,col[100001]={};
void f(int i)
{
	if (i==n+1)
	{
		int ans=0;
		for (int j=1;j<=n;j++)
		{
			for (int k=j-1;k>=1;k--)
			{
				if (col[j]==col[k]&&a[j]==a[k]) ans+=a[j];
			}
		}
		maxn=max(ans,maxn);
	}
	col[i]=0;
	f(i+1);
	col[i]=1;
	f(i+1);
}
int main()
{
	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		maxn=0;
		scanf("%d",&n);
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
		}
		f(1);
		printf("%d",maxn);
	}
}
