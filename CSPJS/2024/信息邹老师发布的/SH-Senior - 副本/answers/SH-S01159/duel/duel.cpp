#include<bits/stdc++.h>
using namespace std;
int n,a[100005],cntat[100005],cntal[100005],next[100005],ans,x,cntt;//attack,alive
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cntat[x]++;
		cntal[x]++;
	}
	for(int i=1;i<=100000;i++)
		if(cntal[i]!=0)
			a[++cntt]=i;
	int k=100011;
	for(int i=100000;i>=1;i--)
	{
		if(cntal[i]!=0)
		{
			next[i]=k;
			k=i;
		}
	}
	int i=a[1],j=a[1];
	while(j<=a[cntt])
	{
		int u=cntal[i],v=cntat[j];
		if(i==j)
		{
			j=next[j];
			continue;
		}
		if(u==v)
		{
			ans-=u;
			i=next[i];
			j=next[j];
		}
		else if(u<v)
		{
			cntat[j]-=u;
			ans-=u;
			i=next[i];
		}
		else
		{
			ans-=v;
			cntal[i]-=v;
			cntat[j]=0;
			j=next[j];
		}
	}
	cout<<ans;
	return 0;
}
