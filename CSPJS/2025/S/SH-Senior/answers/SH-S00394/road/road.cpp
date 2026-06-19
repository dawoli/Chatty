#include <bits/stdc++.h>
using namespace std;
int fa[2000],rnk[2000],c[20];
struct e{
	int u,v,w;
	inline bool operator<(const e &nxt){
		return w<nxt.w;
	}
};
e b[10000010];
int fnd(int x){
	if(fa[x]!=x)fa[x]=fnd(fa[x]);
	return fa[x];
}
bool merge(int x,int y){
	x=fnd(x),y=fnd(y);
	if(x==y)return false;
	if(rnk[x]<rnk[y])fa[x]=y;
	else fa[y]=x;
	if(rnk[x]==rnk[y])++rnk[y];
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		b[i]={u,v,w};
	}
	int bt=m+1;
	//special A
	for(int i=1;i<=k;++i){
		cin>>c[i];
		if(!c[i]){
			for(int j=1;j<=n;++j){
				int w;
				cin>>w;
				b[bt++]={n+i,j,w};
			}
		} 
	}
	sort(b+1,b+bt);
	long long ans=0;
	int poi=1,edg=0;
	while(edg<n+k-1){
		if(merge(b[poi].u,b[poi].v)){
			++edg;
			ans+=b[poi].w;
		}
		++poi;
	}
	cout<<ans;
	return 0;
}
