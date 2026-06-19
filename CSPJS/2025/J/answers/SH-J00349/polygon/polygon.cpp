#include<bits/stdc++.h>
using namespace std;
const int N=1000007,Mod=998244353;
int n,a[N];
vector<int>edge[N];
bool vis[N];
int ans=0;
void dfs(int u,int mx,int sum,int dep)
{
	if(dep>=3 && dep<=n)
	{
		if(2*mx<sum)
		{
			ans++;
			ans=ans%Mod;
		}
	}
	if(dep==n)return;
	vis[u]=true;
	for(int e : edge[u])if(!vis[e])
	{
		vis[e]=true;
		dfs(e,max(a[e],mx),sum+a[e],dep+1);
		vis[e]=false;
	}
	vis[u]=false;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			edge[i].push_back(j);
		//	edge[j].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,a[i],a[i],1);
	}
	
	cout<<ans%Mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}//#Shang4Shan3Ruo6Shui4
