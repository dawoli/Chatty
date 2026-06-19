#include<bits/stdc++.h>//最小生成树Prim 
#define int long long
using namespace std;
int n,m,k;
struct node{
	int to,val;
};
struct Node{
	int pos,edge;
};
int rural[20][11111];
int rerural[20];
int posrural[20];
int c[20],top;
vector<node>g[11111];
int vis[11111];
vector<node>G[11111];
struct cmp{
	bool operator()(Node a,Node b){
		return a.edge>b.edge;
	}
};
priority_queue<Node,vector<Node>,cmp>q;
bool Is=false;
int fun(){
	int cnt=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			G[i].push_back({g[i][j].to,g[i][j].val});
		}
	}
	if(Is==false){
		for(int i=1;i<=k;i++){
			if(c[i]==1){
				sum+=rerural[i];
				for(int j=1;j<=n;j++){
					G[posrural[i]].push_back({j,rural[i][j]});
					G[j].push_back({posrural[i],rural[i][j]});
				}
			}
		}
	}
	
	q.push({1,0});
	while(!q.empty()){
		while(vis[q.top().pos]==1){
			q.pop();
			if(q.empty())break;
		}
		if(q.empty())break;
		int Pos=q.top().pos,Edge=q.top().edge;
		q.pop();
		sum+=Edge;
		if(Pos<=n)cnt++;
		if(cnt==n)break;
		vis[Pos]=1;
		for(int i=0;i<G[Pos].size();i++){
			if(vis[G[Pos][i].to]==0){
				q.push({G[Pos][i].to,G[Pos][i].val});
			}
		}
	}
	return sum;
}
int Min=9999999999999999;
void dfs(int x){
	if(x==k){
		memset(G,0,sizeof(G));
		
		Min=min(Min,fun());
		memset(vis,0,sizeof(vis));
		return ;
	}
	dfs(x+1);
	top++;
	c[top]=1;
	dfs(x+1);
	c[top]=0;
	top--;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,l;
		scanf("%lld%lld%lld",&u,&v,&l);
		g[u].push_back({v,l});
	}
	
	for(int i=1;i<=k;i++){
		posrural[i]=n+i;
		scanf("%lld",&rerural[i]);
		if(rerural[i]==0)Is=true;
		for(int j=1;j<=n;j++){
			scanf("%lld",&rural[i][j]);
		}
	}
	if(Is==true){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				for(int l=1;l<=n;l++){
					if(l!=i){
						g[i].push_back({l,rural[j][i]+rural[j][l]});
					}
				}
			}
		}
//		for(int i=1;i<=k;i++){
//			top++;
//			c[top]=1;
//		}
		Min=min(Min,fun());
	}
	else dfs(0);
	printf("%lld",Min);
	return 0;
}
