#include <bits/stdc++.h>
using namespace std;
int n,m;
long long mod=998244353;
bool flag[505];
int temp[505];
int c[505];
int s[505];
long long ans=0;
void dfs(int step)
{
	if (step>n)
	{
		long long cnt=0;
		long long jj=0;
		for (int i=1;i<=n;i++)
		{
			if (jj>=c[temp[i]])
			{
				jj++;
			}
			else if (s[i]==1)
			{
				cnt++;
			}
			else
			{
				jj++;
			}
		}
		if (cnt>=m)
		{
			ans++;
			ans%=mod;
		}
		return ;
	}
	for (int i=1;i<=n;i++)
	{
		if (!flag[i])
		{
			temp[step]=i;
			flag[i]=true;
			dfs(step+1);
			flag[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string p;
	cin>>p;
	bool flaga=true;
	for (unsigned int i=0;i<p.size();i++)
	{
		s[i+1]=p[i]-'0';
		if (s[i+1]==0)
		{
			flaga=false;
		}
	}
	int aaaaa=0;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
		if (c[i]==0)	aaaaa++;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

