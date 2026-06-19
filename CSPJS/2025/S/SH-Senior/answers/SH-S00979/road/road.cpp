#include<bits/stdc++.h>
using namespace std;
const int N=1e4+9;
const int M=1e6+9;
const int K=19;
int n,m,k,a[K][N],c[K],id[N];
vector<int> to[N];
vector<int> cost[N];
int root(int x){
	if(id[x]==x)return x;
	return id[x]=root(id[x]);
}
void merge(int u,int v){
	id[root(u)]=root(v);
}
struct edge{
	int u,v,w;
	edge(int u,int v,int w){
		this->u=u;
		this->v=v;
		this->w=w;
	}
	bool operator<(const edge & ano)const{
		return w<ano.w;
	}
};
vector<edge> e;
bool ppt1(){
	for(int i=1;i<=k;i++){
		if(!c[i])return false;
	}
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		to[u].push_back(v);
		cost[u].push_back(w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int bgv=0,ans=1e9;
	if(!ppt1())bgv=(1<<k)-1;
	for(int t=bgv;t<(1<<k);t++){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<to[i].size();j++){
				int v=to[i][j],w=cost[i][j];
				e.push_back(edge(i,v,w));
			}
		}
		for(int i=0;i<k;i++){
			if((t>>i)&1){
				cnt+=c[i+1];
				for(int j=1;j<=n;j++){
					int u=i+1,v=j,w=a[u][v];
					e.push_back(edge(u+n,v,w));
				}
			}
		}
		sort(e.begin(),e.end());
		for(int i=1;i<=n*2;i++)id[i]=i;
		for(int i=0;i<e.size();i++){
			edge cur=e[i];
			int u=cur.u;
			int v=cur.v;
			int w=cur.w;
			if(root(u)==root(v))continue;
//			cout<<u<<" "<<v<<" "<<w<<endl;
			merge(u,v);
			cnt+=w;
		}
//		cout<<t<<" "<<cnt<<endl; 
		ans=min(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
