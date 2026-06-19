#include<bits/stdc++.h>
using namespace std;
const int N=1e4+9;
const int M=1e6+9;
const int INF=1e9+9;
const int K=12;
//1~k∂‘”¶n+1µΩn+k 
int n,m,k,ans,now,ans_brute=INF;
int a[N+K],id[N+K];
int status[K];
bool A=true;
//vector<int> to[N+K],w[N+K];
struct node
{
	int from,to,v;
}e[M];
bool cmp(const node &a,const node &b)
{
	return a.v<b.v;
}
int root(int x)
{
	return id[x]==x?x:id[x]=root(id[x]);
}
void unite(int x,int y)
{
	int rx=root(x),ry=root(y);
	id[rx]=ry;
}
bool united(int x,int y){return root(x)==root(y);}
void Kruskal()
{
	for(int i=1;i<=now;i++)
	{
		if(!united(e[i].from,e[i].to))
		{
			if(A||k==0)
			{
				unite(e[i].from,e[i].to);
				ans+=e[i].v;
			}
			else
			{
				if((e[i].from>n&&!status[e[i].from-n])||(e[i].to>n&&!status[e[i].to-n])) continue;
				else
				{
					unite(e[i].from,e[i].to);
					ans+=e[i].v;
				}
			}
			//cout<<e[i].from<<" "<<e[i].to<<" "<<e[i].v<<endl;
		} 
		if(ans>=ans_brute) break;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) id[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,cost;
		cin>>u>>v>>cost;
		e[i].from=u,e[i].to=v,e[i].v=cost;
	}
	now=m;
	for(int i=1;i<=k;i++)
	{
		cin>>a[n+i];
		if(a[n+i]) A=false;
		for(int j=1;j<=n;j++)
		{
			int cost;
			cin>>cost;
			e[++now].from=n+i;
			e[now].to=j;
			e[now].v=cost;
		}
	}
	sort(e+1,e+now+1,cmp);
	if(A||k==0)
	{
		Kruskal();
		cout<<ans;
		return 0;
	}
	else
	{
		ans_brute=INF;
		for(int i=0;i<(1<<k);i++)
		{
			for(int i=1;i<=n+k;i++) id[i]=i;
			int now=i,tmp=0;
			ans=0;
			while(now)
			{
				status[++tmp]=now&1;
				now>>=1;
				if(status[tmp]) ans+=a[n+tmp];
			}
			if(ans>=ans_brute) continue;
			Kruskal();
			ans_brute=min(ans_brute,ans);
		}
		cout<<ans_brute;
	}
	return 0;
}
