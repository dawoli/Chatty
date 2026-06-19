#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int a[N],Max,n;
bool f[N];//red0 blue1
void dfs(int p)
{
	if(p>n)
	{
		int ans=0;
		int rlst=0,blst=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i])
			{
				if(a[blst]==a[i])
					ans+=a[i];
				blst=i;
			}
			else
			{
				if(a[rlst]==a[i])
					ans+=a[i];
				rlst=i;
			}
		}
		Max=max(Max,ans);
		return ;
	}
	dfs(p+1);
	f[p]=1;
	dfs(p+1);
	f[p]=0;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		Max=-1;
		dfs(1);
		cout<<Max<<endl;
	}
	return 0;
}
