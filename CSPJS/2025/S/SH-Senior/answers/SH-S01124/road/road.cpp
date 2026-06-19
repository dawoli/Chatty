#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iterator>
#include<queue>
using namespace std;
const int max_n=10005,inf=0x3f3f3f3f,max_m=1000004;
int grp[max_n],g[max_n][max_n],temp[max_n];
void init()
{
	memset(g,0x3f,sizeof(g));
	for(int i=0;i<max_n;i++)
		g[i][i]=0;
	for (int i = 0; i < max_n; ++i)
		grp[i]=i;
}
struct Edge
{
	int u,v,val;
	Edge(int a,int b,int c)
	{
		u=a,v=b,val=c;
	}
	bool operator<(const Edge a)const 
	{
		return val>a.val;
	}
};
int find_grp(int a)
{
	return grp[a]=((grp[a]==a) ? grp[a] : find_grp(grp[a]));
}
inline void merge_grp(int a,int b)
{
	a=find_grp(a),b=find_grp(b);
	grp[a]=b;
	return ;
}
bool connect(int a,int n)
{
	for(int i=1;i<=n;i++)
		if(find_grp(i)!=a)
			return false;
	return true;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	priority_queue<Edge> q;
	init();
	int n,m,k;
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b]=g[b][a]=min(g[a][b],c);
	}  
	for(int i=1;i<=k;i++)
	{
		int cost;
		cin>>cost;
		for(int j=1;j<=n;j++)
			cin>>temp[j];
		for(int u=1;u<=n;u++)
			for(int v=u;v<=n;v++)
				g[u][v]=g[v][u]=min(g[u][v],temp[u]+temp[v]+cost);
	}
	for(int u=1;u<=n;u++)
		for(int v=u+1;v<=n;v++)
			q.push({u,v,g[u][v]});
	long long ans=0;
	while(!connect(find_grp(1),n))
	{
		Edge cur=q.top();
		q.pop();
		if(find_grp(cur.u)!=find_grp(cur.v))
		{
			ans+=cur.val;
			merge_grp(cur.u,cur.v);
		}
	}
	cout<<ans;
	return 0;
}
