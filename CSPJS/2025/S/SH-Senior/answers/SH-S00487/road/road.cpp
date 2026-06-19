#include<bits/stdc++.h>
using namespace std;
#define N 100100
#define inf 10000000000000000

int n,m,k;

struct edge{
	int v;
	long long w;
};

vector<edge>e[N];

bool chos[11]; //是否城市化 
long long c[N],a[11][N];

//这显然是一个生成树问题，可以考虑O(2^k)枚举谁改造，然后prim
//但是prim忘记怎么写了GG，显然稠密图kruscal不行，稠密图prim带优先队列有用吗 

long long d[N]; //连接这个点的最小边权 
bool in[N]; //是否被连通 

struct node{
	int pos;
	bool operator < (node o) const { return d[pos] > d[o.pos]; }
};

priority_queue<node>q;

long long prim(){ //完蛋 prim写挂了,GG 
	int fx = 0;
	long long res = 0;
	int cnt = 0;
	for(int i = 1;i <= k;++i){
		if(chos[i]){
			fx++;
			res += c[i];
		}
	}
	for(int i = 1;i <= n + k;++i)in[i] = 0,d[i] = inf;
	while(!q.empty())q.pop();
	q.push({1});
	d[1] = 0;
	while(!q.empty()){
		int cur = q.top().pos;
		q.pop();
		if(in[cur])continue;
		in[cur] = 1;
		res += d[cur];
//		printf("+%lld = %lld\n",d[cur],res);
		if(cur <= n)cnt++;
		if(cnt >= n)return res;
		for(int i = 0;i < e[cur].size();++i){
			int v = e[cur][i].v;long long w = e[cur][i].w;
			if(!in[v] && d[v] >= w && (chos[v - n] || v <= n)){
				d[v] = w;
				q.push({v});
			}
		}
	}
	if(cnt >= n)return res;
	return inf;
}

long long bf(int pos){
	if(pos == k + 1){
		long long res = prim();
		return res;
	}
	chos[pos] = 1;
	long long res = bf(pos + 1);
	chos[pos] = 0;
	return min(res,bf(pos + 1));
}
 
int main(){
	freopen("road.in","r",stdin);
  	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m;++i){
		int u,v;long long w;
		scanf("%d%d%lld",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	bool flagA = true;
	for(int i = 1;i <= k;++i){
		scanf("%lld",&c[i]);
		if(c[i])flagA = false;
		for(int j = 1;j <= n;++j){
			scanf("%lld",&a[i][j]);
			e[i + n].push_back({j,a[i][j]});
			e[j].push_back({i + n,a[i][j]});
			if(a[i][j])flagA = false;
		}
	}
	if(k == 0)printf("%lld",prim()); //20pts
	else if(flagA)printf("0"); //32pts
	else{
		long long ans = inf;
		printf("%lld",bf(1));
	}
	return 0;
}
