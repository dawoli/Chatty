#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
const int N=1e4+5;
int n,m,k;
struct type{
	int u,v,w;
}e[2000005];
int fa[N];
int a[15][N];
int cnt[15];//used num of town
int c[15];// cost of town
bool check_A=1;
int find(int x){
	if(fa[x]==x)	return x;
	else return fa[x]=find(fa[x]);
}
bool cmp1(type p,type q){
	return p.w<q.w;
}
void init(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0)	check_A=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)	check_A=0;
		}
	}
}
void get_mst(){
	for(int i=1;i<=n;i++)	fa[i]=i;
	sort(e+1,e+m+1,cmp1);
	int ans=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u;
		int v=e[i].v;
		int fu=find(u);
		int fv=find(v);
		if(fu==fv)	continue;
		ans+=e[i].w;
		fa[fu]=fv;
	}
	printf("%d\n",ans);
}
void solve_hard(){
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	if(k==0)	get_mst();//16pts
	else if(check_A)	printf("0\n");//32pts
	else solve_hard();
	return 0;
}
