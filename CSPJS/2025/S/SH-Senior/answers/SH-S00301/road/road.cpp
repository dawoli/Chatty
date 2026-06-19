#include<bits/stdc++.h>
using namespace std;
#define N 10004
#define M 1000006
#define INF 1000000009
typedef long long LL;
int n,m,k;
LL ans=0;
struct E{
	int u,v;
	LL w;
}e[M];
bool cmp1(E x,E y){
	return x.w<y.w;
}
int fa[N];
int find(int x){
	if(fa[x]==x){
		return x;
	}else{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
		fa[e[i].u]=e[i].u;
		fa[e[i].v]=e[i].v;
	}
	sort(e+1,e+1+m,cmp1);
	int c,a;
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&a);
		}
	}
	for(int i=1;i<=m;i++){
		int uu=e[i].u,vv=e[i].v;
		if(find(uu)!=find(vv)){
			fa[find(uu)]=vv;
			ans+=e[i].w;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);

	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

7 7 0
1 2 1
2 3 7
3 4 6
6 4 2
2 5 3
1 7 5
2 7 4
*/
