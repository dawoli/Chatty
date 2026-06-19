#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353,N=510;
int n,m,c[N];
ll ans;
string s;
bool vis[N];
void dfs(int d,int h)
{
	if(h+n-d<m)return;
	if(d==n)
	{
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=true;
		if(d-h>=c[i]||s[d]=='0')dfs(d+1,h);
		else dfs(d+1,h+1);
		vis[i]=false;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(m==n)
	{
		ans=1;
		for(int i=0;i<s.size();i++)
			if(s[i]=='0'||c[i]==0)
			{
				cout<<0;
				return 0;
			}
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		cout<<ans;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
