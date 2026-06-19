#include<bits/stdc++.h>
#define int long long
using namespace std;
bool st;
const int N=1e4+9;
const int SN=1e3+9;
const int M=1e6+9;
const int K=19;
const int INF=0x3f3f3f3f3f3f3f3f;
int n,m,k,a[K][N],c[N];
//a[i][j]代表乡镇i与城市j的费用 
int id[N];
struct edge{
	int u,v,cost;
}e[M+10000000],ee[M];
bool cmp(const edge&a,const edge&b){
	if(a.cost<b.cost) return true;
	else return false;
}
int root(int u){
	if(id[u]==u) return u;
	else return id[u]=root(id[u]);
}
void unite(int u,int v){
	int ru=root(u); int rv=root(v);
	if(ru==rv) return;
	id[ru]=rv;
}
void solvek0(){
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) id[i]=i;
	int sum=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u; int v=e[i].v; int cost=e[i].cost;
		if(root(u)!=root(v)) unite(u,v),sum+=cost;
	}
	cout<<sum<<endl;
}
bool allfree(){
	for(int i=1;i<=k;i++){
		if(c[i]!=0) return false;
	}
	return true;
}
void solveallfree(){
	for(int i=1;i<=k;i++){
		for(int p=1;p<=n;p++){
			for(int q=p+1;q<=n;q++){
				e[++m]=(edge){p,q,a[i][p]+a[i][q]};
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) id[i]=i;
	int sum=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u; int v=e[i].v; int cost=e[i].cost;
		if(root(u)!=root(v)) unite(u,v),sum+=cost;
	}
	cout<<sum<<endl;
}
void solve(){
	int om=m;
	int ans=INF;
	for(int i=0;i<(1LL<<k);i++){
		int sum=0;
		m=om;
		for(int j=1;j<=m;j++) e[j]=ee[j];
		for(int j=1;j<=k;j++){
			if((i>>(k-1))&1){
				sum+=c[j];
				for(int p=1;p<=n;p++){
					for(int q=p+1;q<=n;q++){
						e[++m]=(edge){p,q,a[j][p]+a[j][q]};
					}
				}
			}
		}
		sort(e+1,e+m+1,cmp);
		for(int j=1;j<=n;j++) id[j]=j;
		for(int j=1;j<=m;j++){
			int u=e[j].u; int v=e[j].v; int cost=e[j].cost;
//			if(i==1) cout<<"?"<<u<<" "<<v<<" "<<cost<<endl;
			if(root(u)!=root(v)) unite(u,v),sum+=cost;
		}
		ans=min(ans,sum);
//		if(i==1) cout<<"sum:"<<sum<<endl;
	}
	cout<<ans;
}
bool ed;
signed main(){
//	cout<<(&st-&ed)/1024.0/1024.0<<endl;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].cost,ee[i]=e[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0) solvek0();
	else if(allfree()&&n<=1e3) solveallfree();
	else solve();
	return 0;
}
