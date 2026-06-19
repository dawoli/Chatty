#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
int T,n,ans=0,a[maxn];
int col[maxn];
void dfs(int ste,int co,int sco)
{
	col[ste]=co;
	for(int i=ste-1;i>=1;i--)
	{
		if(col[i]==co)
		{
			if(a[i]==a[ste])sco+=a[i];
			break;
		}
	}
	if(ste==n)
	{
		ans=max(ans,sco);
		return;
	}
	dfs(ste+1,0,sco);
	col[ste+1]=2;
	dfs(ste+1,1,sco);
	col[ste+1]=2;
	return;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		memset(a,0,sizeof(a));
		memset(col,2,sizeof(col));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		dfs(1,0,0);
		col[1]=2;
		dfs(1,1,0);
		col[1]=2;
		printf("%d\n",ans);
	}
	return 0;
 } 
