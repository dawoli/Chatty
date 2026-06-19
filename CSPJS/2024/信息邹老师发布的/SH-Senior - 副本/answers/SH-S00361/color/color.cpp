#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n;
int ans=0,u=0;;
void dfs(int i,int x,int y)
{
	if(i==n)
	{
		ans=max(ans,u);
		return ;
	}
	
	int t=u;
	if(a[i]==x)
		u+=x;	
	dfs(i+1,a[i],y);
	u=t;
	t=u;
	if(a[i]==y)
		u+=x;
	dfs(i+1,x,a[i]);
	u=t;
	
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
		int maxx=0;
		for(int i=0;i<n;i++)
		{
			
			cin>>a[i];
		}
		dfs(0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
