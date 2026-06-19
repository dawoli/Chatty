#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200009],ans=0;
void dfs(int b,int c,int d,long long df)
{
	ans=max(ans,df);
	if(b==n+1)return;
	if(a[b]==c)dfs(b+1,a[b],d,df+a[b]);
	else dfs(b+1,a[b],d,df);
	if(a[b]==d)dfs(b+1,c,a[b],df+a[b]);
	else dfs(b+1,c,a[b],df);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		dfs(1,-1,-1,0);
		cout<<ans<<endl;
	}
}
