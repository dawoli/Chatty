#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
	int u,v,w;
};
vector<road> to[10009];
int c[19];
int gett[19][10009];
road p[1200009];
int bcz[10009];
int root(int a){
	if(bcz[a]==a) return a;
	return bcz[a]=root(bcz[a]);
}
bool cmp(road a,road b){
	return a.w<b.w;
}
int cost;
int havebridge;
int countc;
road x;
void solve1(){
	for(int i=1;i<=n;i++){
		bcz[i]=i;
	}
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=m&&havebridge!=(n-1);i++){
		if(root(p[i].u)==root(p[i].v)){
			continue;
		}
		cost+=p[i].w;
		bcz[root(p[i].u)]=root(p[i].v);
		havebridge++;
	}
	cout<<cost;
}
void solve2(){
	int nowp=m;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			x.u=(i+n);
			x.v=j;
			x.w=gett[i][j];
			p[++nowp]=x;
		}
	}
	for(int i=1;i<=(n+k);i++){
		bcz[i]=i;
	}
	sort(p+1,p+1+nowp,cmp);
	for(int i=1;i<=nowp;i++){
		if(root(p[i].u)==root(p[i].v)){
			continue;
		}
		cost+=p[i].w;
		bcz[root(p[i].u)]=bcz[root(p[i].v)];
	}
	cout<<cost;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>p[i].u>>p[i].v>>p[i].w;
	}
	if(k==0){
		solve1();
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			gett[i][j]=w;
		}
	}
	for(int i=1;i<=k;i++){
		if(c[i]==0){
			countc++;
		}
	}
	if(countc==k){
		solve2();
		return 0;
	}
	solve1();
	return 0;
}
