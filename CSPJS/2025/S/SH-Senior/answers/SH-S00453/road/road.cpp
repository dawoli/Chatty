#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k; 
int u[1000010],v[1000010],w[1000010];
int c[10010][10010];
int fa[1000010];
int d[1000010];
bool ch[20];
struct edge{
	int u,v,w,s;//u,v,w正常 s表示这是哪个村的路,0就是需要修复的路 
}e[1000010];
bool cmp(edge tmp1,edge tmp2){
	return tmp1.w<tmp2.w;
}
edge mkpair(int x,int y,int z,int t){
	edge tmp;
	tmp.u=x,tmp.v=y,tmp.w=z,tmp.s=t;
	return tmp;
}
void init2(){
	for(int i=0;i<=15;i++){
		ch[i]=true;
	}
}
void init(int nn){
	for(int i=0;i<=nn;i++){
		fa[i]=i;
		d[i]=1;
	}
	for(int i=0;i<=nn+k+1;i++){
		fa[i]=i;
	}
}
int find(int u){
	if(fa[u]==u){
		return u;
	}
	fa[u]=find(fa[u]);
	return fa[u];
}
void merge(int u,int v){
	if(fa[find(u)]!=fa[find(v)]){
		d[fa[find(v)]]+=d[fa[u]];
		fa[find(u)]=fa[find(v)];
	} 
}
int kr(int ban){
	init(n); 
	int cnt=0,res=0;
	while(1){
		if(find(e[cnt+1].u)!=find(e[cnt+1].v)){
			merge(e[cnt+1].u,e[cnt+1].v);
			res+=e[cnt+1].w;
			//cout<<"Choose "<<e[cnt+1].u<<" "<<e[cnt+1].v<<" "<<e[cnt+1].w<<" "<<e[cnt+1].s<<endl;
			if(d[find(e[cnt+1].v)]==n){
				//cout<<"!"<<find(e[cnt+1].v)<<" "<<d[find(e[cnt+1].v)]<<endl;
				return res;
			}
			if(d[find(e[cnt+1].v)]==n){
				//cout<<"!"<<find(0)<<" "<<find(e[cnt+1].v)<<endl; 
				return res;
			} 
		}
		cnt++;
	}
}
int kr2(int tmpp){
	init(n); 
	int cnt=0,res=0;
	while(1){
		if(find(e[cnt+1].u)!=find(e[cnt+1].v)){
			merge(e[cnt+1].u,e[cnt+1].v);
			//cout<<"Choose "<<e[cnt+1].u<<" "<<e[cnt+1].v<<" "<<e[cnt+1].w<<" "<<e[cnt+1].s<<endl;
			res+=e[cnt+1].w;
			if(d[find(e[cnt+1].v)]==n+1){
				return res;
			}
			if(d[find(e[cnt+1].v)]==n){
				//cout<<"!"<<find(0)<<" "<<find(e[cnt+1].v)<<endl; 
				return res;
			} 
		}
		cnt++;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init2();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		e[i]=mkpair(u[i],v[i],w[i],0); 
	}
	int cnt=n;
	int allchcnt=0;
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		//allchcnt+=c[i][0]; 
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		//	e[cnt+1]=mkpair(n+i,j,c[i][j],i);
			cnt++;
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		//cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<" "<<e[i].s<<endl;
	}
	cout<<kr(100010);
	return 0;
} 
