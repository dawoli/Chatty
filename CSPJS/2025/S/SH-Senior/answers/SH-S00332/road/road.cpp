#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define wt first
#define to second
using namespace std;

const int N=1e4+10;
int n,m,k,u,v,w;
vector <PII> e[N];
bool vst[N];
priority_queue<PII,vector<PII>,greater<PII> > pq;
int ans=0;

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		cin >> u >> v >> w;
		e[u].push_back({w,v});
		e[v].push_back({w,u});
	}
	for(auto st : e[1])	pq.push(st);
	vst[1]=true;
	
	while(!pq.empty())
	{
		PII tp=pq.top();
		pq.pop();
		if(vst[tp.to])	continue;
		ans+=tp.wt;
		vst[tp.to]=true;
		for(auto nxt : e[tp.to])	if(!vst[nxt.to])	pq.push(nxt);
	}
	
	cout << ans << endl;
	
	return 0;
}

