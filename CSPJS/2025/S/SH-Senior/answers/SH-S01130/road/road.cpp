#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 20,maxp = 20;
int n,m,k,p;
long long ans;
int c[maxp],val[maxp];
int dis[maxn],From[maxn];
bool vis[maxn];
vector<pair<int,int> >  graph[maxn];

void prim(){
	dis[1] = 0;
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(0,1));
	while(!pq.empty()){
		int top = pq.top().second,topy = -pq.top().first;
		pq.pop();
		if(vis[top])	continue;
		vis[top] = true;
		if(top <= n){
			ans += topy;
		}else	val[top - n] = topy;
		for(int i = 0;i < graph[top].size();i ++){
			int t = graph[top][i].first;
			if(vis[t])	continue;
			int v = 0;
			if(t > n)	v = c[t - n];
			if(v + graph[top][i].second <= dis[t]){
				From[t] = top;
				dis[t] = v + graph[top][i].second;
				pq.push(make_pair(-dis[t],t));
			}
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%d %d %d",&n,&m,&k);
	p = n;
	for(int i = 1;i <= m;i ++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		graph[u].push_back(make_pair(v,w));
		graph[v].push_back(make_pair(u,w));
	}
	for(int i = 1;i <= k;i ++){
		scanf("%d",&c[i]);
		for(int j = 1;j <= n;j ++){
			int x;
			scanf("%d",&x);
			graph[j].push_back(make_pair(n + i,x));
			graph[n + i].push_back(make_pair(j,x));
		}
	}
	prim();
	bool flag[maxp];
	memset(flag,false,sizeof(flag));
	for(int i = 1;i <= n;i ++){
		if(From[i] > n)	flag[From[i] - n] = true;
	}
	for(int i = 1;i <= k;i ++){
		if(flag[i])	ans += val[i];
	}
	printf("%lld",ans);
	return 0;
}

