#include<bits/stdc++.h>
using namespace std;
const int len=2e5+10;
int a[len],r[len],b[len],cntr=0,cntb=0,n,rans=0;
int cal()
{
	int ans=0;
	for(int i=1;i<=cntb;i++)
	{
		if(b[i]==b[i-1])
		{
			ans+=b[i];
		}
	}
	for(int i=1;i<=cntr;i++)
	{
		if(r[i]==r[i-1])
		{
			ans+=r[i];
		}
	}
	return ans;
}
void dfs(int x)
{
	if(x==n+1)
	{
		rans=max(rans,cal());
		return;
	}
	r[++cntr]=a[x];
	dfs(x+1);
	cntr--;
	b[++cntb]=a[x];
	dfs(x+1);
	cntb--;
	return;
}
void func()
{
	rans=0;
	cin>>n;
	for(int j=1;j<=n;j++)
	{
		cin>>a[j];
	}
	if(n<=15)
	{
		dfs(1);
		cout<<rans<<'\n';
		return;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		func();
	}
	return 0;
}
