#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
vector<int> cnt;
vector<bool> vis;
/*void dfs(int i)
{
	if()
	{
		return;
	}
	if(!vis[i])
	{
		vis[i]=true;
		cnt.push_back(path);
		dfs();
		vis[i]=false;
		cnt.pop_back(path);
	}
}*/
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int sum,maxn=0;
	int u[1010],v[1010],w[100010],c[10010],a[10010];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	if(k!=0)
	{
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			for(int e=1;e<=n;e++)
			{
				cin>>a[e];
			}
		}
	}
	if(k==0)
	{
	    for(int j=1;j<=m;j++)
        {
            sum+=w[j];
            maxn=max(maxn,w[j]);
        }
        cout<<sum-maxn<<endl;
	}
    return 0;
}
