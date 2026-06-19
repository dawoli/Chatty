#include<bits/stdc++.h>
using namespace std;

int n,a[5005],cnt,maxw;
bool vis[5005];
void dfs(int x)
{
	if(x>n)
	{
		int sum=0,maxv=0;
		for(int i=1;i<=n;i++)
			if(vis[i])
			{
				sum+=a[i];
				maxv=max(maxv,a[i]);
			}
		if(sum>maxv*2) cnt++;
		return;
	}
	vis[x]=true;
	dfs(x+1);
	vis[x]=false;
	dfs(x+1);
}


int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxw=max(maxw,a[i]);
	}
	maxw*=2;
	dfs(1);
	cout<<cnt;
	return 0;
 } 
