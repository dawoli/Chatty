#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
};
edge es[1000009];
bool cmp(edge a,edge b){
	return a.w<=b.w;
} 
int p[100009];
int rt(int x){
	if(p[x]==x)return x;
	return p[x]=rt(p[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)p[i]=i;
	for(int i=1;i<=m;i++){
		edge e;
		cin>>e.u>>e.v>>e.w;
		es[i]=e;
	}
	int cur=m;
	if(k>0){
		for(int i=1+m;i<=k+m;i++){
			int w0;
			cin>>w0;
			for(int j=1;j<=n;j++){
				edge e;
				e.u=i-m+n,e.v=j;
				int w1;
				cin>>w1;
				e.w=w1+w0/2;
				es[++cur]=e;
			}
		}
	}
	sort(es+1,es+m+k*n+1,cmp);
	int C0=n+k,C1=0;
	for(int i=1;C0>1;i++){
		int r=es[i].u,s=es[i].v,t=es[i].w;
		if(rt(r)==rt(s))continue;
		p[rt(s)]=rt(r);
		C1+=t;
		C0--;
	}
	cout<<C1;
	return 0;
}
