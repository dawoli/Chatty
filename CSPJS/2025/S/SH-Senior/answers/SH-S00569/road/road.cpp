#include<bits/stdc++.h>
using namespace std;
#define N 10017
#define M 1000007
#define ll long long
//重构前的图，重构后的图
struct node{
	int u,v,w;
	bool operator<(const node &b)const{
		return w<b.w;
	}
}d[M],e[N*10],f[N];
int n,m,k;
int c[N],a[11][N];
int fa[N];
void init(){
	for(int i=0;i<=n+k;++i){
		fa[i]=i;
	}
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>d[i].u>>d[i].v>>d[i].w;
	}
	init();
	sort(d+1,d+m+1);
	int tot=0;
	for(int i=1;i<=m;++i){
		int xx=find(d[i].u),yy=find(d[i].v);
		if(xx!=yy){
			fa[xx]=yy;
			f[++tot]=d[i];
		}
	}
	for(int i=0;i<k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	ll ans=200000000000000ll,r=2000000000000000ll;
	//int sum=0;
	for(int i=0;i<(1<<k);++i){
		//cout<<i<<'\n';
		for(int j=1;j<=n-1;++j){// 1e7
			e[j]=f[j];
		}
		tot=n-1;
		init();//1e5
		ll anss=0;
		int rr=0;
		for(int j=0;j<k;++j){
			if(i>>j&1){
				++rr;
				anss+=c[j];
				for(int l=1;l<=n;++l){// 1e8 
					++tot;
					e[tot].u=n+rr;
					e[tot].v=l;
					e[tot].w=a[j][l];
					//++sum;
				}
			}
		}
		if(anss>r) continue;
	//	for(int j=1;j<=tot;++j){
	//		cout<<e[j].u<<'|'<<e[j].v<<'|'<<e[j].w<<'\n';
	//	}
		sort(e+1,e+tot+1);
		for(int j=1;j<=tot;++j){
			int xx=find(e[j].u),yy=find(e[j].v);
			if(xx!=yy){
				fa[xx]=yy;
				anss+=e[j].w;
			}
		}
		if(i==0) r=anss;
	//	cout<<anss<<",\n";
		ans=min(ans,anss);
	}
	cout<<ans<<'\n';
	//cerr<<sum<<'\n';
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


CCF评测机，帮帮我!

不要被卡常!!!!!!!!!
:( 
*/
