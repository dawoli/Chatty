#include<cstdio>
#include<algorithm>
using namespace std;
const int K = 15;
const int N = 10005;
const int M = 1e6 + 1e3;
struct edge{
	int u;
	int v;
	int w;
};
edge e[M<<1];
int n,m,k,a[K][N],c[K],fa[N],ans;
bool cmp(edge& x,edge& y){
	return x.w<y.w;
}
int findf(int x){
	if(x!=fa[x]){
		fa[x]=findf(fa[x]);
	}
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=k;i++){
		int equ=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]==0){
				equ=j;break;
			}
		}
		if(equ==0){
			equ=0;
		}
		for(int j=1;j<=n;j++){
			if(j==equ)continue;
			e[++m].u=j;
			e[m].v=equ;
			e[m].w=a[i][j];
		}
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		int f1=findf(e[i].u);
		int f2=findf(e[i].v);
		if(f1!=f2){
			fa[f2]=f1;
			ans+=e[i].w;
			sum++;
			if(sum>=n-1){
				printf("%d\n",ans);
				return 0;
			} 
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
