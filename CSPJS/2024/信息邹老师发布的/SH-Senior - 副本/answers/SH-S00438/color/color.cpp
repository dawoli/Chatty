#include<bits/stdc++.h>
using namespace std;
#define N 200005
int n,a[N],sum,ans;
bool col[N];
void dfs(int lev,int lr,int lb)
{
	if(lev>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(a[lr]==a[lev]) sum+=a[lev];
	dfs(lev+1,lev,lb);
	if(a[lr]==a[lev]) sum-=a[lev];
	if(a[lb]==a[lev]) sum+=a[lev];
	dfs(lev+1,lr,lev);
	if(a[lb]==a[lev]) sum-=a[lev];
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		dfs(1,0,0);
		cout<<ans<<'\n';
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
