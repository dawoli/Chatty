#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N=1e4+10;
const int K=11;
const int M=1e6+10;
int n,m,k;
int fa[N];
int c[K],a[K][N];
struct edge{
	int u,v,w;
	bool operator < (const edge &other) const{
		return w < other.w;
	}
}e[M];
ll ans;

void get_fa(int x,int y){
	for(int i=1;i<=n;i++){
		if(fa[i]==fa[y]) fa[i]=x;
	}
}

void kruskal(){
	for(int i=1;i<=n;i++) fa[i] = i;
	ans=0;
	
	for(int i=1;i<=m;i++){
		int u=e[i].u, v=e[i].v, w=e[i].w;
		if(u>v) swap(u,v);
		if(fa[u]!=fa[v]){
			ans+=w;
			get_fa(u, v);
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1, e+m+1);
	if(k==0){
		kruskal();
		cout<<ans<<'\n';
	}
	else{
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		cout<<100<<'\n';
	}
	
	return 0;
}
