#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e4+10;
const int M=1e6+10;
int n,m,k;
array<int,3> edges[M];
bool vis[M];
int a[20],b[20][N];
vector<int> Mess;
struct DSU{
	vector<int> fa;
	DSU(int n,int k):fa(n+k+10){ iota(fa.begin(),fa.end(),0);	}
	inline void init(){ iota(fa.begin(),fa.end(),0); }
	inline int find(int x){ return x==fa[x]?x:fa[x]=find(fa[x]); }
	inline bool merge(int u,int v){
		int x=find(u),y=find(v);
		if(x!=y){
			fa[x]=y;
			return 1;
		}
		return 0;
	}
};
int val[11*N];
vector<pii> vec[11*N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		edges[i]={w,u,v};
	}
	for(int i=0;i<k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++)
			cin>>b[i][j],Mess.push_back(b[i][j]);
	}
	DSU dsu(n,k);
	sort(edges+1,edges+1+m);
	ll ans=0;
	for(int i=1;i<=m;i++){
		int u=edges[i][1],v=edges[i][2],w=edges[i][0];
		if(dsu.merge(u,v))
			ans+=w,Mess.push_back(w),vis[i]=1;
	}
	sort(Mess.begin(),Mess.end());
	Mess.erase(unique(Mess.begin(),Mess.end()),Mess.end());
	for(int i=0;i<k;i++)
		for(int j=1;j<=n;j++){
			int x=lower_bound(Mess.begin(),Mess.end(),b[i][j])-Mess.begin()+1;
			val[x]=b[i][j];
			b[i][j]=x;
		}
	for(int i=1;i<=m;i++)
		if(vis[i]){
			int u=edges[i][1],v=edges[i][2],w=edges[i][0];
			int x=lower_bound(Mess.begin(),Mess.end(),w)-Mess.begin()+1;
			val[x]=w,vec[x].push_back({u,v});
		}
	for(int S=0;S<(1<<k);S++){
		ll tmp=0;
		for(int i=0;i<k;i++)
			if((S>>i)&1){
				tmp+=a[i];
				for(int j=1;j<=n;j++)
					vec[b[i][j]].push_back({n+1+i,j});
			}
		dsu.init();
		for(int i=1;i<=Mess.size();i++)
			for(auto p:vec[i])
				if(dsu.merge(p.first,p.second))
					tmp+=val[i];
		ans=min(ans,tmp);
		for(int i=0;i<k;i++)
			if((S>>i)&1)
				for(int j=1;j<=n;j++)
					vec[b[i][j]].pop_back();
	}
	cout<<ans<<endl;
	return 0;
}
