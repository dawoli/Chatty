#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Edge{
	long long u,v,w;//road connect to v,cost w
	bool f;
	bool operator< (const Edge &b) const{
		return w>b.w;
	}
	/*
	bool operator> (const Edge &b) const{
		return w<b.w;
	}*/
};
vector<Edge> g;
int f[10131];
long long c[10131];
bool vis[10131];
void init(int x){
	for(int i=1;i<=x;i++){
		f[i]=i;
	}
}
int query(int x){
	return f[x]==x ? x : f[x]=query(f[x]);
}
void merge(int x,int y){
	f[query(x)]=y;
}
vector<Edge> t;
void kruskal(){
	priority_queue<Edge> q;
	for(Edge e : g){
		q.push(e);
	}
	int ct=0;
	while(!q.empty()){
		Edge e=q.top();
		q.pop();
		if(query(e.u)!=query(e.v)){
			merge(e.u,e.v);
			ct++;
			t.push_back(e);
		}
		if(ct==n-1) break;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init(n+k);
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g.push_back(Edge{u,v,w,0});
	}
	
	vector<long long> r(n+1);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int i=1;i<=n;i++){
			cin>>r[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				g.push_back(Edge{i,j,r[i]+r[j]+c[i]});
			}
		}
	}
	kruskal();
	long long ans=0;
	for(Edge e : t){
		//cout<<e.u<<' '<<e.v<<' '<<e.w<<'\n';
		ans+=e.w;
	}
	cout<<ans;
	return 0;
}

