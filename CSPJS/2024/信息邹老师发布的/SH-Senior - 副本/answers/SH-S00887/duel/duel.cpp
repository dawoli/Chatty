#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n,x,mx,cnt,c;
int r[100010],sum[100010];


int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	cnt=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		r[x]++;
		mx=max(mx,x);
	}
	sum[1]=r[1];
	for(int i=2;i<=mx;i++)
	{
		sum[i]=sum[i-1]+r[i];
		c=min(r[i],sum[i-1]);
		cnt-=c;
		sum[i]-=c;
	}
	printf("%d",cnt);
	return 0;
}
