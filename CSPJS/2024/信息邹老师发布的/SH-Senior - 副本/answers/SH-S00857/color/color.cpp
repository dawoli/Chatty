#include<bits/stdc++.h>
using namespace std;
int a[1000010],t,n,x,maxn=-10000,p,q;
void dfs(int i,int ans)
{
	if(a[i]==p)
	{
		if(i==n)
		{
			maxn=max(maxn,ans+p);
			return;
		}
		dfs(i+1,ans+p);
		return;
	}
	if(a[i]==q)
	{	
		if(i==n)
		{
			maxn=max(maxn,ans+q);
			return;
		}
		dfs(i+1,ans+q);
		return;
	}
	if(i==n)
	{
		maxn=max(maxn,ans);
		return;
	}
	int tmp=p;
	p=a[i];
	dfs(i+1,ans);
	p=tmp;
	tmp=q;
	q=a[i];
	dfs(i+1,ans);
	q=tmp;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++)
	{
		cin>>n;
		maxn=-10000;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		dfs(1,0);
		cout<<maxn<<endl;
	}
	return 0;
}
