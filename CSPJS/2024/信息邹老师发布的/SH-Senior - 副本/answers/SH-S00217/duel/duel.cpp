#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,r[maxn],dig[maxn],ans,cnt;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	ans=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&r[i]);
	}
	sort(r+1,r+n+1);
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(r[i]>r[i-1])dig[++cnt]=1;
		else dig[cnt]++;
	}
	for(int i=1;i<cnt;i++)
	{
		if(dig[i]<=dig[i+1])ans-=dig[i];
		else ans-=dig[i+1],dig[i+1]=dig[i];
	}
	printf("%d\n",ans);
	return 0;
 } 
