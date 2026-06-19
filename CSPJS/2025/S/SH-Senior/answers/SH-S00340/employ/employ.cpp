#include<bits/stdc++.h>
using namespace std;

int n,m;
string s;
int c[550];
int ans;
bool vis[550];

void dfs(int d,int cs)
{
//	cout<<d<<' '<<cs<<endl;
	if(d>n)
	{
		if(cs>=m) ans++;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		if(d-cs-1>=c[i])
			dfs(d+1,cs);
		else if(s[d-1]=='0')
			dfs(d+1,cs);
		else
			dfs(d+1,cs+1); 
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
		cin>>c[i];
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
