#include<bits/stdc++.h>
using namespace std;
int t,fa[30001],dis[30001],size[30001];
int find(int x)
{
	if(fa[x]==x)return x;
	int f=find(fa[x]);
	dis[x]+=dis[fa[x]];
	return fa[x]=f;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=1;i<=30000;i++)
		fa[i]=i;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		char c;
		int x,y;
		cin>>c>>x>>y;
		if(c=='M')
		{
			int fx=find(x),fy=find(y);
			if(fx!=fy)
			{
				fa[fx]=fy;
				dis[fx]+=size[fy]+1;
				size[fy]+=size[fx]+1;
			}
		}
		else
		{
			int fx=find(x),fy=find(y);
			if(fx!=fy)cout<<"-1\n";
			else cout<<abs(dis[x]-dis[y])-1<<'\n';
		}
	}
}