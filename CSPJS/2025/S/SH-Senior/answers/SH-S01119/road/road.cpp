/*========road==========*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
/*========road==========*/

const int maxn=1e4+6;
const int maxm=1e6+6;
const int maxk=16;
const int maxe=2*(maxn*maxk+maxm);

struct Edge{
	int from,to,cost;
	Edge(int f0=0,int t0=0,int c0=0):from(f0),to(t0),cost(c0){
	}
	operator <(const Edge &another_edge){
		return cost<another_edge.cost;
	}
};




int head[maxn];
Edge edg[maxe];
int cnt=0;

void add_edge(int i,int j,int w){
	edg[++cnt]=Edge(i,j,w);
	edg[++cnt]=Edge(j,i,w);
}

//bing4 cha2 ji2
int fa[maxn];
int siz[maxn];

int find_fa(int x){
	return fa[x]==x?x:(fa[x]=find_fa(fa[x]));
}

void merge(int x,int y){
	if(siz[x]<siz[y]) swap(x,y);
	fa[y]=x;
	siz[x]+=siz[y];
	siz[y]=0;
}


int n,m,k;

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i,siz[i]=1;
	}
	for(int i=1;i<=m;i++){
		int a,b,x;
		cin>>a>>b>>x;
		add_edge(a,b,x);
	}
	for(int i=1;i<=k;i++){
		int ci;
		cin>>ci;
		vector<int> new_road_costs(1,0);
		int minc=2147483647,pos=1;
		for(int j=1;j<=n;j++){
			int new_road_cost;
			cin>>new_road_cost;
			new_road_costs.push_back(new_road_cost);
			if(new_road_cost<minc){
				minc=new_road_cost;
				pos=j;
			}
		}
		//cerr<<"Minc="<<minc<<" ci="<<ci<<endl;
		for(int j=1;j<=n;j++){
			add_edge(pos,j,new_road_costs[j]+ci+minc);
		}
	}
	sort(edg+1,edg+cnt+1);
//	for(int i=1;i<=cnt;i++){
//		cerr<<edg[i].from<<' '<<edg[i].to<<' '<<edg[i].cost<<endl;
//	}
//	cerr<<"-----------"<<endl;
	int p=1,coo=0;
	for(int i=1;i<n;i++){ // rebuild n-1 edges
		while(find_fa(edg[p].from)==find_fa(edg[p].to)) p++;
		//cerr<<"p="<<p<<' '<<edg[p].from<<' '<<edg[p].to<<' '<<edg[p].cost<<endl;
		merge(edg[p].from,edg[p].to);
		coo+=edg[p].cost;
	}
	cout<<coo<<endl;
	return 0;
}
