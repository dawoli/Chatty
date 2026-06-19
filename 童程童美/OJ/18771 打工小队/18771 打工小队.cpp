#include<bits/stdc++.h>
using namespace std;
int n,w[21][21],ans=-1,sm[21],m[21];
bool vis[21];
void dfs(int pos,int sum)
{
	if(pos>n)
	{
		if(sum>ans)ans=sum;
		return;
	}
	if(sum+sm[pos]<ans)return;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(pos+1,sum+w[pos][i]);
			vis[i]=0;
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>w[i][j];
			m[i]=max(m[i],w[i][j]);
		}
	}
	for(int i=n;i>=1;i--)
	{
		sm[i]=sm[i+1]+m[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
