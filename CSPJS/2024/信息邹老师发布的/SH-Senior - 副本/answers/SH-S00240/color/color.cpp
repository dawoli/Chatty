#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int a[200005];
int b[200005];
int r[200005];
void dfs(int deep,int sum)
{
	if(deep>n)
	{
		ans=max(ans,sum);
		return;
	}
	b[deep]=deep;
	r[deep]=r[deep-1];
	dfs(deep+1,sum+(a[deep]==a[b[deep-1]]?a[deep]:0));
	b[deep]=b[deep-1];
	r[deep]=deep;
	dfs(deep+1,sum+(a[deep]==a[r[deep-1]]?a[deep]:0));
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ans=0;
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
