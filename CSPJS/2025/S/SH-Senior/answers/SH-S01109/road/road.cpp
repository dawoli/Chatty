#include<bits/stdc++.h>
using namespace std;

struct edge{
	int u,v;
	long long w;
};

int r[10001];
vector<edge> e;

int getRt(int x)
{
	return (r[x]==x?x:r[x]=getRt(r[x]));
}

bool cmp(const edge &a,const edge &b)
{
	return a.w < b.w;
}

long long Kruskal(int dts,int egs)
{
	long long ans = 0;
	for(int i=1;i<=dts;i++) r[i] = i;
	int t = dts - 1;
	sort(e.begin(),e.end(),cmp);
	int i=0;
	while (t>0 && i<egs)
	{
		if(getRt(e[i].u) != getRt(e[i].v))
		{
			r[e[i].u] = getRt(e[i].v);
			--t;
			ans += e[i].w;
		}
		i++;
	}
	
	return ans;
}

int n,m,k;
edge temp;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>temp.u>>temp.v>>temp.w;
		e.push_back(temp);
	}
	cout<<Kruskal(n,m);
	
	
	return 0;
}
