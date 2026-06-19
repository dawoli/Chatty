#include<bits/stdc++.h>
using namespace std;
struct Road{
	int u,v,w;
	bool operator<(const Road r)const{
		return w<r.w;
	}
};
long long ans;
int n,m,k,cnt,x,id[10009],xc[10009];
Road rr,rd[10000009];
int root(int u){
	if(id[u]==u) return u;
	return id[u]=root(id[u]);
}
void hb(int u,int v){
	id[root(u)]=root(v);
}
void Kruskal(){
	sort(rd+1,rd+1+cnt);
	for(int i=1;i<=cnt;i++){
		rr=rd[i];
		if(root(rr.u)==root(rr.v)) continue;
		ans+=rr.w;
		hb(rr.u,rr.v);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cnt=m;
	for(int i=1;i<=n;i++) id[i]=i;
	for(int i=1;i<=m;i++){
		cin>>rr.u>>rr.v>>rr.w;
		rd[i]=rr;
	}
	for(int i=1;i<=k;i++){
		cin>>x;
		for(int j=1;j<=n;j++) cin>>xc[j];
		for(int j=1;j<=n;j++)
			for(int l=j+1;l<=n;l++){
				rr.u=j,rr.v=l,rr.w=xc[j]+xc[l]+x;
				rd[++cnt]=rr;
			}
	}
	Kruskal();
	cout<<ans<<endl;
	return 0;
} 
