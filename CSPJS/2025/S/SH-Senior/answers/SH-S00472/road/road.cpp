#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#define mkp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn= 1e4+9 ;
const int INF= 2e9+9 ;

int n,m,k;
vector<pii> e[maxn];
int c[12][maxn];

int dis[maxn];
ll ans=0;

void init()
{
	for(int i=1;i<=n;++i)
		dis[i]=INF;
	ans=0;
}
/*
struct cmp1{
	bool operator ()(const pair<ll,int> &tmp1,const pair<ll,int> &tmp2)
	{
		return tmp1.first<tmp2.first ;
	}
}; */

void solvek0() //prim 因为边过多 
{
	__gnu_pbds::priority_queue<pair<int,int> >pq;
	__gnu_pbds::priority_queue<pair<int,int> >::point_iterator pt[maxn];
	
	for(int i=2;i<=n;++i)
	{
		pt[i]=pq.push(mkp(-INF,i));
	}
	dis[1]=0;
	pt[1]=pq.push(mkp(0,1));
	
	for(int tn=1;tn<=n;++tn) //当前tn个点 
	{
		int nowp=pq.top().second;
		dis[nowp]=0;
		ans+=-pq.top().first;
		pq.pop();
		
		for(auto j:e[nowp])
		{
			int &v=j.first; int &w=j.second;
			if(w<dis[v]) //未到达 
			{
				dis[v]=w;
				pq.modify(pt[v],mkp(-w,v));
			}
		}
	}
	
	printf("%lld",ans);
}

int from[12];
bool isA()
{
	for(int i=1;i<=k;++i)
	{
		if(c[i][0]!=0) return false;
		from[i]=0;
		for(int j=1;j<=n;++j)
			if(c[i][j]==0) from[i]=j;
		if(from[i]==0) return false;
	}
	return true;
}

void solveA()
{
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=n;++j)
		{
			e[from[i]].push_back(mkp(j,c[i][j]));
			e[j].push_back(mkp(from[i],c[i][j]));
		}
	}
	__gnu_pbds::priority_queue<pair<int,int> >pq;
	__gnu_pbds::priority_queue<pair<int,int> >::point_iterator pt[maxn];
	
	for(int i=2;i<=n;++i)
	{
		pt[i]=pq.push(mkp(-INF,i));
	}
	dis[1]=0;
	pt[1]=pq.push(mkp(0,1));
	
	for(int tn=1;tn<=n;++tn) //当前tn个点 
	{
		int nowp=pq.top().second;
		dis[nowp]=0;
		ans+=-pq.top().first;
		pq.pop();
		
		for(auto j:e[nowp])
		{
			int &v=j.first; int &w=j.second;
			if(w<dis[v]) //未到达 
			{
				dis[v]=w;
				pq.modify(pt[v],mkp(-w,v));
			}
		}
	}
	
	printf("%lld",ans);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	init();
	int u,v,w;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back(mkp(v,w));
		e[v].push_back(mkp(u,w));
	}
	for(int i=1;i<=k;++i)
	for(int j=0;j<=n;++j)
	{
		scanf("%d",&c[i][j]);
	}
	
	if(k==0)
		solvek0();
	else if(isA())
		solveA();
	else
		solvek0();
	
	return 0;
}

