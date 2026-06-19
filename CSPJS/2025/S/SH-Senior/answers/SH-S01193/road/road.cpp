#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll city,u,v,w,road,town,c[1005][1005],t[15][100005],vis[100005],vist[15][100005],value=0x3f3f3f3f3f3f3f;
/*bool done()
{
	for(int i = 1;i<=city;i++)
	{
		if(vis[i]==0)return 0;
	}
	return 1;
}*/
ll sum()
{
	ll ans=0;
	for(ll i = 1;i<=town;i++)
	{
		ans+=vist[i][0]*t[i][0];
		for(ll j = 1;j<=city;j++)
		{
			ans+=vist[i][j]*t[i][j];
		}
	}
	return ans;
}
void dfs(ll vv,ll visit)
{
	if(visit==city-1)
	{
		value=min(value,vv+sum());
	}
	for(ll i = 1;i<=city;i++)
	{
		for(ll j = 1;j<=city;j++)
		{
			if(i==j)continue; 
			if(vis[i]&&vis[j])continue;
			if(vis[i]||vis[j])visit++;
			else visit+=2;
			vis[i]=1;
			vis[j]=1;
			if(c[i][j])
			{
				dfs(vv+c[i][j],visit);
			}
			else
			{
				for(ll k= 1;k<=town;k++)
				{
					vist[k][0]=1;
					vist[k][i]=1;
					vist[k][j]=1;
					bool temp1=vist[k][0],temp2=vist[k][i],temp3=vist[k][j];
					dfs(vv+t[k][i]+t[k][j],visit);
					vist[k][0]=temp1;
					vist[k][i]=temp2;
					vist[k][j]=temp3;
				}
			}
		}
	}
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>city>>road>>town;
	for(ll i = 1;i<=city;i++)
	{
		cin>>u>>v>>w;
		c[u][v]=w;
		c[v][u]=w;
	}
	for(ll i = 1;i<=town;i++)
	{
		cin>>t[i][0];
		for(ll j = 1;j<=city;j++)
		{
			cin>>t[i][j];
		}
	}
	dfs(0,0);
	cout<<value/2+1;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
