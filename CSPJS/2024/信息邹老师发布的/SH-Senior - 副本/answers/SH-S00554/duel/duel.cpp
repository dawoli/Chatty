#include<bits/stdc++.h>
using namespace std;
int box1[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,a,maxv=0,i,ans,cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a);
		++box1[a];
		maxv=max(maxv,a);
	}
	ans=n;
	for(i=1;i<=maxv;++i)
	{
		if(!box1[i])
			continue;
		if(cnt)
		{
			if(cnt<box1[i])
			{
				ans-=cnt;
				cnt=box1[i];
			}
			else
				ans-=box1[i];
		}
		else
			cnt+=box1[i];
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
