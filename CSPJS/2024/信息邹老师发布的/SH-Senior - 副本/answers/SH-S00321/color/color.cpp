#include<bits/stdc++.h>
using namespace std;
int n,ct[1000006],sh[1000006],a[1000006];
int ans;
int t;
void dfs(int ct,int i,int red,int blue)
{
	if(i==n)
	{
		ans=ct;
		return;
	}
	if(red==a[i] && sh[i]!=1)
	{
		dfs(ct+a[i],i+1,a[i],blue);
	}
	if(blue==a[i] && sh[i]!=1)
	{
		blue=a[i];
		dfs(ct+a[i],i+1,red,a[i]);
	}
	dfs(ct,i+1,red,a[i]);
	dfs(ct,i+1,a[i],blue);
}
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			ct[a[i]]++;
			sh[i]=ct[a[i]];
		}
		dfs(0,1,a[1],a[2]);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
