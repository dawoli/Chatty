#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
string s;
int c[505];
bool vis[505];
const int mod=998244353;
void dfs(int step,int p,int pp)
{
	if(step>n)
	{
		if(!(p<m))	
		{
			cnt++;
			cnt%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		if(s[step-1]=='0'||!(pp<c[i])) 
		{
			dfs(step+1,p,pp+1);
		}
		else if(s[step-1]=='1') dfs(step+1,p+1,pp);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<cnt%mod;
	return 0;
}  
