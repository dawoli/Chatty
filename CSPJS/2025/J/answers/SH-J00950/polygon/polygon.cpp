#include <bits/stdc++.h>
using namespace std;
int a[5010],n,c,v[5010];
vector<int> b;
void dfs(int u)
{
	if (u==n+1)
	{
		return;
	}
	if (u>=3+1)
	{
		int s=0,mx=0;
		for (int i=0;i<u-1;i++)
		{
			s+=b[i];
			mx=max(mx,b[i]);
		}
		if (s>2*mx)
		{
			//cout<<s<<" "<<mx<<" "<<2*mx<<endl;
			c=c%998244353+1;
			return;
		}
	}
	if (v[u]==0)
	{
		v[u]=1;
		b.push_back(a[u]);
		dfs(u+1);
		b.pop_back();
		v[u]=0;
	}
	dfs(u+1);
}
void subtask1()
{
	if (n<3)
	{
		cout<<0;
	}
	else if (n==3)
	{
		int s=0,mx=0;
		for (int i=1;i<=n;i++)
		{
			s+=a[i];
			mx=max(mx,a[i]);
		}
		cout<<(s>2*mx);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (n<=3)
	{
		subtask1();
		return 0;
	}
	dfs(1);
	cout<<c;
	return 0;
}
