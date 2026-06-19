#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long gi_ans=0;
int n;
void dfs(int id,int ans,int mmax)
{
	if(id==n+1)
	{
		if(ans>mmax*2)
		{
			gi_ans=(gi_ans+1)%998244353;
		}
		return;
	}
	dfs(id+1,ans,mmax);
	dfs(id+1,ans+a[id],max(mmax,a[id]));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int li_i=1;li_i<=n;li_i++)
	{
		cin>>a[li_i];
	}
	dfs(1,0,0);
	cout<<gi_ans;
	return 0;
}
