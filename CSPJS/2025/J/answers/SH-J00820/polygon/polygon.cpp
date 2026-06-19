#include<bits/stdc++.h>
using namespace std;
int n,a[101],ans=0;
bool b[101];
void dfs(int d)
{
	if (d==n+1)
	{
		int maxn=-1,sum=0,cnt=0;
		for (int i=1;i<=n;i++)
		{
			if (b[i]==true)
			{
				cnt++;
				sum+=a[i];
				maxn=max(maxn,a[i]);
			}
		}
		if (sum>2*maxn&&cnt>=3) ans++;
		return;
	}
	dfs(d+1);
	b[d]=true;
	dfs(d+1);
	b[d]=false;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dfs(1);
	printf("%d",ans);
}
