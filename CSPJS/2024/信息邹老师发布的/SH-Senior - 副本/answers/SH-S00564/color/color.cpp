#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
int col[1000005];
int n,ans;
void check()
{
	int sum=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(col[j]==col[i])
			{
				if(arr[j]==arr[i])
					sum+=arr[i];
				break;
			}
		}
	}
	ans=max(ans,sum);
}
void dfs(int layer)
{
	if(layer>n)
	{
		check();
		return;
	}
	col[layer]=0;
	dfs(layer+1);
	col[layer]=1;
	dfs(layer+1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i]);
		dfs(1);
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
