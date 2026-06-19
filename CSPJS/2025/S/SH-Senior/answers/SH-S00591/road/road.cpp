#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e3+5;
long long n,m,k,b[N],g[N][N],f[N],cur=0,ans=0;
struct node{int u,v;long long w;}a[N*N/2];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void solve(){
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx!=fy){
			f[fx]=fy;
			ans+=a[i].w;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		solve();
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=2e9;
		}
	}
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		g[u][v]=min(g[u][v],w);
		g[v][u]=min(g[v][u],w);
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++) cin>>b[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				g[i][j]=min(g[i][j],b[i]+b[j]+c);
				g[j][i]=min(g[j][i],b[j]+b[i]+c);
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			a[++cur]={i,j,g[i][j]};
		}
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(a+1,a+cur+1,cmp);
	for(int i=1;i<=cur;i++){
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx!=fy){
			f[fx]=fy;
			ans+=a[i].w;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
