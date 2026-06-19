#include <bits/stdc++.h>
using namespace std;

int n,m;
const int N=507;
const int mod=998244353;
int per[N];
bool vis[N];
string s;
int c[N];
long long ans;

void dfs(int depth)
{
	if(depth==n+1)
	{
		int fail=0;
//		for(int i=1;i<=n;i++) cout<<per[i]<<" ";
//		cout<<endl;
		for(int i=1;i<=n;i++)
		{
//			cout<<per[i]<<" "<<fail<<endl;
			if(per[i]<=fail) return;
			fail+=(int)(s[i]-'0');
		}
		ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=true;
		per[depth]=c[i];
		dfs(depth+1);
		per[depth]=0;
		vis[i]=false;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	memset(vis,false,sizeof(vis));
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1);
	cout<<ans<<"\n"; 
	return 0;
}
/*
3 2
101
1 1 2
*/
