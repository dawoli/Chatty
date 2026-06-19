#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}m[100005];
int ans,n;
void dfs(int x,int sum,int a,int b,int c)
{
	if(x==n)
	{
		ans = max(sum,ans);
		return;
	}
	if(a<n/2)
		dfs(x+1,sum+m[x].a,a+1,b,c);
	if(b<n/2)
		dfs(x+1,sum+m[x].b,a,b+1,c);
	if(c<n/2)
		dfs(x+1,sum+m[x].c,a,b,c+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 0;i<n;i++)
		{
			cin>>m[i].a>>m[i].b>>m[i].c;
		}
		ans = 0;
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
