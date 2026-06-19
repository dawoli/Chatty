#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int maxn=1e4+15;
const int maxm=1e6+10;
int n,m,k;
ll ans=1e16;
ll res=0;
int adj[maxn][maxn];
int sel[12];
int vil[12][maxn];
bool vis[maxn];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<pair<int,int>> edg[maxn];
int c[12];
inline int read()
{
	int rr=0,ww=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		    ww=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		rr=rr*(1<<3)+rr*(1<<1)+ch-(1<<4)-(1<<5);
		ch=getchar();
	}
	return rr*ww;
}
signed main()
{
//	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	int u,v,w;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			adj[i][j]=INT_MAX;
		}
		adj[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		u=read(),v=read(),w=read();
		adj[u][v]=w,adj[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			vil[i][j]=read();
		}
	}
	for(int pb=0;pb<(1<<k);pb++)
	{
		res=0;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
		}
		for(int i=1;i<=k;i++)
		{
			sel[i]=0;
		}
		int fl=0,kl=pb,bitcnt=0;
		while(kl>0)
		{
			bitcnt++;
			if(kl&1)
			{
				sel[++fl]=k-bitcnt+1;
				res+=c[k-bitcnt+1];
			}
			kl=kl/2;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(adj[i][j]!=0 && adj[i][j]!=INT_MAX)
				{
					pair<int,int> st;
					st.first=adj[i][j],st.second=j;
					edg[i].push_back(st);
				}
			}
		}
		for(int f=1;f<=fl;f++)
		{
			for(int i=1;i<=n;i++)
			{
				adj[n+f][i]=vil[f][i],adj[i][n+f]=vil[f][i];
				pair<int,int> st;
				st.first=adj[n+f][i],st.second=i;
				edg[n+f].push_back(st);
			}
		}
		vis[1]=1;
		pair<int,int> pp;
		pp.first=0,pp.second=1;
		pq.push(pp);
		while(!pq.empty())
		{
			pair<int,int> cur=pq.top();
//			for(int u:edg[])
//			pq[cur.first]
		}
		ans=min(ans,res);
	}
	return 0;
}
