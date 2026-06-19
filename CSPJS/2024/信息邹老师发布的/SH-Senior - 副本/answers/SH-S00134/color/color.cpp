#include<bits/stdc++.h>
using namespace std;
long long t,ans[20],n;
int dfs(int* m,int* v,int b,int c)
{
	if(b>n)return 0;
	int a=dfs(m,v,b+1,0);
	v[b+1]=1;
	int d=dfs(m,v,b+1,1);
	v[b+1]=0;
	for(int i=b-1;i>=1;i--)
	{
		if(v[i]==v[b])
		{
			if(m[i]==m[b])
			{
				return max(a,d)+m[i];
				
			}
			return max(a,d);
		}
	}
	return max(a,d);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++)
	{
		int a[20005],vis[20005]={0};
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		ans[o]=dfs(a,vis,1,0);
	}
	for(int i=1;i<=t;i++)cout<<ans[i]<<endl;
	return 0;
}
