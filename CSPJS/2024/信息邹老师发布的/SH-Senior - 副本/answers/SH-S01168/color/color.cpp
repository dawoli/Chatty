#include<bits/stdc++.h>
using namespace std;
int t,a[200005],n,maxn;
bool f[200005];
void dfs(int pos)
{
	if(pos==n)
	{
		int rt=0,bt=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==1)
			{
				if(rt==a[i]) sum+=a[i];
				rt=a[i];
			}
			if(f[i]==0)
			{
				if(bt==a[i]) sum+=a[i];
				bt=a[i];
			}
		}
		maxn=max(maxn,sum);
		return;
	}
	f[pos]=1;
	dfs(pos+1);
	f[pos]=0;
	dfs(pos+1);
	return;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++)
	{
		memset(a,0,sizeof(a));
		cin>>n;
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		dfs(1);
		cout<<maxn<<endl;
	}
	return 0;
} 
