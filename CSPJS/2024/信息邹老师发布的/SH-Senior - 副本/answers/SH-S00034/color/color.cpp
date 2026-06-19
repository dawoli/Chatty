#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[105];
void dfs(int k,int color,int colorvalue,int cnt)
{
//	cout<<k<<" "<<color<<" "<<colorvalue<<" "<<cnt<<endl;
	if(k==n)
	{
		if(a[k]==colorvalue)
			cnt+=a[k];
		ans=max(ans,cnt);
		return;
	}
	if(a[k]==colorvalue)
		dfs(k+1,0,colorvalue,cnt+a[k]),dfs(k+1,1-color,colorvalue,cnt+a[k]);
	dfs(k+1,color,a[k],cnt);
	dfs(k+1,1-color,colorvalue,cnt);
}
void runp()
{
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,0,0);
//	dfs(1,1,0,0);
	cout<<ans<<endl;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
		runp();
	return 0;
}
