#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int w,u,v,nw,id;
	bool operator<(const Edge& rhs) const{
		return rhs.w<w;
	}
};
int n,m,k,cn[15],deg[15],ed[15],a[15][10015],c[15],fa[10050],co;
long long ans;
priority_queue<Edge>Q;
int fn(int x){
	return x==fa[x]?x:(fa[x]=fn(fa[x]));
}void un(int x,int y){
	x=fn(x),y=fn(y);
	fa[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);co=n-1;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		Edge e;
		scanf("%d%d%d",&(e.u),&(e.v),&(e.w));
		e.nw=e.id=0;Q.push(e);
	}for(int i=1;i<=k;i++){
		scanf("%d",&(c[i]));
		for(int j=1;j<=n;j++){
			scanf("%d",&(a[i][j]));
			Edge e;e.w=a[i][j]+c[i],e.u=j,e.v=n+i,e.nw=1,e.id=i;
			Q.push(e);
		}
	}while(co){
		Edge e=Q.top();Q.pop();
		if(e.nw&&cn[e.id])continue;
		if(fn(e.u)==fn(e.v))continue;
		ans+=e.w;
		//cerr<<"connecting "<<e.u<<' '<<e.v<<endl;
		un(e.u,e.v);
		if(e.id)deg[e.id]++,ed[e.id]=e.w;
		if(!e.nw)co--;
		else{
			cn[e.id]=1;
			for(int j=1;j<=n;j++){
				Edge f;f.w=a[e.id][j],f.u=j,f.v=n+e.id,f.nw=0,f.id=e.id;
				Q.push(f);
			}
		}
	}for(int i=1;i<=k;i++)if(deg[i]==1)ans-=ed[i];else cerr<<deg[i]<<endl;
	printf("%lld",ans);
}
