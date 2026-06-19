#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int c[505];
int a[505];
int n,m;
bool vis[505];
bool f=0;
string s;
const int mod = 998244353;
int ans=0;
void dfs(int step)
{
	if(step>n)
	{
		int cnt=0;
		for(int i = 1;i <= n;i++)
		{
			if(cnt>=c[a[i]]||s[i-1]=='0')
			{
				cnt++;
				continue;
			}
		}
		if(n-cnt>=m)ans=(ans+1)%mod;
	}
	for(int i = 1;i <= n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		a[step]=i;
		dfs(step+1);
		vis[i]=0;
		a[step]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i <= n;i++)
	{
		cin>>c[i];
	}
	for(int i = 0;i < s.size();i++)
	{
		if(s[i]=='0')f=0;
	}
	if(f)
	{
		int ans=1;
		for(int i = 1;i <= n;i++)
		{
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
