#include<bits/stdc++.h>
using namespace std;
long long n,m,tt,visit[1005],ans,fa[1005],b[1005],a[1005][1005];
struct node{
	long long u,v,w;
	bool operator < (const node x)const{
		return w>x.w;
	}
};
priority_queue<node> g;
long long find(long long x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(long long x,long long y){
	fa[find(x)]=find(y);
}
void tree(){
	long long anst=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	while(!g.empty()){
		long long u=g.top().u,v=g.top().v,w=g.top().w;
		g.pop();
		if(find(u)==find(v)) continue;
		merge(u,v);
		anst+=w;
	}
	ans=anst;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>tt;
	memset(a,0x7f,sizeof(a));
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		g.push({u,v,w});
		g.push({v,u,w});
	}
	for(int i=1;i<=tt;i++){
		long long c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>b[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				a[j][k]=min(a[j][k],b[j]+b[k]+c);
			}
		}
	}
	for(int j=1;j<=n;j++){
		if(tt==0) break;
		for(int k=j+1;k<=n;k++){
			g.push({j,k,a[j][k]});
			g.push({k,j,a[j][k]});
		}
	}
	tree();
	cout<<ans<<endl;
	return 0;
}
