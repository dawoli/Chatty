#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
	int x;
	cin>>x;
	return x; 
//	char ch=getchar();int ret=0,coef=1;
//	while(!(ch>='0'&&ch<='9')) ch=getchar();
//	while((ch>='0'&&ch<='9')){
//		ret=ret*10+ch-'0';
//		ch=getchar();
//	}
//	return ret*coef;
}
const int N = 1e4+20;
const int M = 1e6+1e5+10;
struct edge{
	int u,v,w,id;
}e[M];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int n,m,k,c[20],num,fa[N];
void init(){for(int i=1;i<=n+k;++i) fa[i]=i;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){fa[x]=y;}
void kruskal_left(){
	num=0;
	for(int i=1;i<=m;++i){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			e[++num]=e[i];
			merge(fx,fy);
		}
	}
}
bool f[20];
long long ans=1e18;
void kruskal(){
	long long ret=0;
	int nd=n;
	for(int i=1;i<=k;++i)
		if(f[i]) ret+=(ll)c[i],nd++;
	int nu=0;
	for(int i=1;i<=m;++i){
		if(e[i].id!=0&&!f[e[i].id]) continue; 
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			nu++;
			merge(fx,fy);
			ret+=(long long)e[i].w;
			if(ret>=ans) return ;
			if(nu==nd-1) break;
		}
	}
	ans=min(ans,ret);
}
void dfs(int i,bool v){
	f[i]=v;
	if(i==k){
		init();
		kruskal();
		return ;
	}
	dfs(i+1,0);
	dfs(i+1,1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		e[i].u=read(),e[i].v=read();
		e[i].w=read(),e[i].id=0;
	}
	int tot=m;
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j){
			tot++;
			e[tot].u=n+i;
			e[tot].v=j;
			e[tot].w=read();
			e[tot].id=i;
		}
	}
	sort(e+1,e+m+1,cmp);
	init();
	kruskal_left();
	for(int i=num+1,j=m+1;j<=tot;i++,j++){
		e[i]=e[j];
		m=i;
	}
	sort(e+1,e+m+1,cmp);
//	cout<<m<<endl;
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
