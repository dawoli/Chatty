#include<bits/stdc++.h>

using namespace std;

int k,n,a[5000],vis[5000]={0},ans=0;

void dfs(int step,int max,int tot)
{
	if(step>=3)
	{
		if(a[max]*2<tot)ans++;
		if(ans>998244353)ans=1;
	}
	if (max==n-1 || step==n)return;
	for(int i=max;i<n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(step+1,i,tot+a[i]);
			vis[i]=0;
		}
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	dfs(0,0,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
