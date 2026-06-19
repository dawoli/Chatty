#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[100005],b[100005];
int query()
{
	int r=0,bl=0,c=0;
	for(int i=1; i<=n; i++)
	{
		if(b[i]==0)
		{
			if(a[i]==a[r]) c+=a[i];
			r=i;
		}
		else
		{
			if(a[i]==a[bl]) c+=a[i];
			bl=i;
		}
		//cout<<r<<" "<<bl<<" "<<b[i]<<" "<<c<<endl;
	}
	//cout<<endl;
	return c;
}
int ans=0;
void dfs(int x)
{
	if(x>n)
	{
		ans=max(ans,query());
		return;
	}
	b[x]=0;
	dfs(x+1);
	if(x!=1)
	{
		b[x]=1;
		dfs(x+1);
	}
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
		for(int i=1; i<=n; i++) cin>>a[i];
		ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
