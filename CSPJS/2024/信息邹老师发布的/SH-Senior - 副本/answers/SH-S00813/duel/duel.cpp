#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,ans,cnt;
int r[100001],c[100001];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&r[i]);
	}
	sort(r,r+n);
	c[0]=1;
	for(int i=1;i<n;i++)
	{
		if(r[i]==r[i-1]) c[cnt]++;
		else c[++cnt]++;
	}
	ans=c[0];
	for(int i=1;i<=cnt;i++)
	{
		ans=max(ans,c[i]);
	}
	printf("%d",ans);
	return 0;
}
