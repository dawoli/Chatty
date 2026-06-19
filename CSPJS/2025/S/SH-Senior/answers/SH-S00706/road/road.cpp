#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=3e7+10;
ll h[maxn],nxt[maxn],val[maxn],to[maxn],cnt;
ll dis[maxn];
bool vis[maxn];
ll n,m,s,tot,ans,k;
ll temp[maxn];
//int li[10003][10003];
void add(ll a,ll b,ll c)
{
	to[++cnt]=b;
	val[cnt]=c;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
struct node
{
	ll w,v;
	friend bool operator <(node a,node b)
	{
		return a.w>b.w;
	}
}tmp;
priority_queue<node>q;
void prim()
{
	for(int i=1;i<=n;i++)dis[i]=INT_MAX;
	dis[1]=0;
	tmp.w=0;
	tmp.v=1;
	q.push(tmp);
	while(!q.empty())
	{
		ll u=q.top().v;
		q.pop();
		if(vis[u])continue;
		ans+=dis[u];
		vis[u]=1;
		for(int i=h[u];i;i=nxt[i])
		{
			if(dis[to[i]]>val[i])
			{
				dis[to[i]]=val[i];
				tmp.w=val[i];
				tmp.v=to[i];
				q.push(tmp);
			}
		}
		
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//注意以上两行的修改以及去除注释 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
		//li[a][b]=li[b][a]=c;
	}
	for(int i=1;i<=k;i++)
	{
		ll c1;
		cin>>c1;
		for(int i=1;i<=n;i++)
		{
			cin>>temp[i];
		} 
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ll x=temp[i]+temp[j]+c1;
				add(i,j,x);
				add(j,i,x);
			}
		}
	}
	prim();
	cout<<ans;
	return 0;
}
