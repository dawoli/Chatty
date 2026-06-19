#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,k,u,v,w,fa[2000][10020],t,b[20];
long long c[2000];
struct node{
	int u,v,w;
}e[2000010];
bool cmp(node x,node y){
	return x.w<y.w;
}
inline int mx(int x,int y){
	return x>y?x:y;
}
inline long long mn(long long x,long long y){
	return x<y?x:y;
}
int find(int idx,int x){
	if(x!=fa[idx][x]){
		fa[idx][x]=find(idx,fa[idx][x]);
	}
	return fa[idx][x];
}
inline void merge(int idx,int x,int y){
	fa[idx][fa[idx][x]]=fa[idx][y];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	while(m--){
		scanf("%d%d%d",&u,&v,&w);
		e[t++]={u,v,w};
	}
	for(int i=0;i<k;i++){
		scanf("%lld",&b[i]);
		m+=b[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			e[t++]={n+i+1,j,w};
		}
	}
	sort(e,e+t,cmp);
	if(m==0){
		for(int i=1;i<=i+k;i++)fa[0][i]=i;
		for(int i=0;i<t;i++){
			u=e[i].u,v=e[i].v,w=e[i].w,m=mx(0,mx(e[i].u,e[i].v)-n);
			if(find(0,u)!=find(0,v)){
				c[0]+=w;
				merge(0,u,v);
			}
		}
	}
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<k;j++){
			if((i>>j)&1)c[i]+=b[j];
		}
	}
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++){
			fa[i][j]=j;
		}
	}
	for(int i=0;i<t;i++){
		u=e[i].u,v=e[i].v,w=e[i].w,m=mx(0,mx(e[i].u,e[i].v)-n);
		if(m==0){
			for(int j=0;j<(1<<k);j++){
				if(find(j,u)!=find(j,v)){
					c[j]+=w;
					merge(j,u,v);
				}
			}
		}else{
			for(int j=0;j<(1<<k-1);j++){
				int p=((((1<<k-m)-1)<<m)&j|((1<<m)-1)&j)|(1<<m-1);
				if(find(p,u)!=find(p,v)){
					c[p]+=w;
					merge(p,u,v);
				}
			}
		}
	}
	for(int i=1;i<(1<<k);i++)c[0]=mn(c[0],c[i]);
	printf("%lld",c[0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
