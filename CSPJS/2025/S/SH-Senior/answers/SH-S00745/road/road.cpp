#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> pii;
struct Edge{
	int u,v;
	long long w;
}e[2000005],g[2000005];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int n,m,k;
int cnt;

int c[15],a[15][10005];
int fa[10005];
void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y) fa[x]=y;
}
/*
void solve23(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			e[++cnt]={j,n+i,a[i][j]};
		}
	}
	sort(e+1,e+cnt+1,cmp);
	int jon=0;
	long long ans=0;
	int ness=n-1;
	for(int i=1;i<=cnt;i++){
		int u,v,w;
		u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)){
			if(u>n||v>n)ness++;
			merge(u,v);
			ans+=w;
			jon++;
		}
		if(jon==ness) break;
	}
	cout << ans << endl;
}*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	init();
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		e[++cnt]={u,v,w};
	}
	bool flg1=1,flg2=1,flg3=0;
	for(int i=1;i<=k;i++){
		cin >> c[k];
		if(c[k])flg2=0;
		for(int j=1;j<=n;j++){
			cin >> a[k][j];
			if(!a[k][j])flg3=1;
			if(c[k]||a[k][j])flg1=0;
		}
	}
	if(flg1&&k){
		cout << 0 << endl;
	}/*else if(){
		
	}else if(flg2&&flg3&&k){
		solve23();
	}*/else{
		sort(e+1,e+cnt+1,cmp);
		int jon=0;
		long long ans=0;
		for(int i=1;i<=cnt;i++){
			int u,v,w;
			u=e[i].u,v=e[i].v,w=e[i].w;
			if(find(u)!=find(v)){
				merge(u,v);
				ans+=w;
				jon++;
			}
			if(jon==n-1) break;
		}
		if(!k){
			cout << ans << endl;
		}else{
			/*
			int nct=cnt;
			for(int i=1;i<=cnt;i++){
				g[i]=e[i];
			}
			for(int i=1;i<=k;i++){
				nct=cnt;
				for(int j=1;j<=n;j++){
					g[nct++]={n+i,j,a[j][k]};
				}
				sort(g+1,g+nct+1,cmp);
				
			}
			*/
			cout << ans << endl;
		}	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
