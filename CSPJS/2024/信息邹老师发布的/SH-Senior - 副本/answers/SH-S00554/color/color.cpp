#include<bits/stdc++.h>
using namespace std;
int a[200004],arr[20],rebl[20][2],ans;
void dfs(int layer,int n)
{
	if(layer>n)
	{
		int sum=0,i;
		for(i=1;i<=n;++i)
			sum+=a[i]==a[rebl[i][arr[i]]]?a[i]:0;
		ans=max(ans,sum);
		return ;
	}
	arr[layer]=0;
	rebl[layer+1][1]=rebl[layer][1];
	rebl[layer+1][0]=layer;
	dfs(layer+1,n);
	arr[layer]=1;
	rebl[layer+1][0]=rebl[layer][0];
	rebl[layer+1][1]=layer;
	dfs(layer+1,n);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		if(n<=15)
		{
			memset(rebl,0x00,sizeof(rebl));
			ans=0;
			dfs(1,n);
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
