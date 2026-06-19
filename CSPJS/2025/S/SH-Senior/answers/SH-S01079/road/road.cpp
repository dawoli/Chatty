#include <iostream>
#include <algorithm>
#include <stdio.h>
#define int long long
using namespace std;
const int N=1e4+1;
//struct E{
//	int v,w,nex;
//}e[1000001];
//
//
//int cnt,head[N];
//void add(int u,int v,int w){
//	e[++cnt]=(E){v,w,head[u]};
//	head[u]=cnt;
//}
struct E{
	int u,v,w;
}e[1000001]; int cnt;
void add(int u,int v,int w){
	e[++cnt]=(E){u,v,w};
	
}

bool cmp(E x,E y){
	return x.w<y.w;
}
int n,m,k;
int c[N],fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}


int solve(int ns,int ms){
	for(int i=1;i<=ns;i++) fa[i]=i;
	sort(e+1,e+ms+1,cmp);
	int ans=0;
	for(int i=1;i<=ms;i++){
		int u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if(fu>fv) swap(fu,fv);
		if(fu!=fv){
			fa[fu]=fv;
			ans+=e[i].w;
		}
	}
	return ans;
}


int v[11][N];
int Ans=0x7fffffff;

void work(int num){
	cnt=m;
	int ns=n,ms=m;
	int val=0;
	for(int i=0;i<10;i++){
		if((num>>i)&1){
			val+=v[i+1][0];
			ns++,ms+=n;
			for(int j=1;j<=n;j++){
				add(i+n+1,j,v[i+1][j]);
			}
		}
	}
	Ans=min(Ans,val+solve(ns,ms));
//	cout<<solve(ns,ms)<<' '<<val<<endl;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	bool flag=0;
	for(int i=1;i<=k;i++){
		cin>>v[i][0];
		if(v[i][0]) flag=1;
		for(int j=1;j<=n;j++){
			cin>>v[i][j];
		}
	}
//	if(!flag){
//		for(int i=1;i<=m;i++){
//			for(int j=1;j<=n;j++)
//			e[i].w=min(e[i].w,v[j][e[i].u]+v[j][e[i].v]);
//		}
//		cout<<solve(n,m);
//		fclose(stdin);fclose(stdout);
//		return 0;
//	}
	for(int i=0;i<=(1<<k)-1;i++){
		work(i);
	}
	cout<<Ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
