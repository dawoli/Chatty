#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,fa[10005],c[15],a[15][10005],ans,ct,vis[15];
struct node{
	int u,v,w;
}e[1100005];
bool cmp(node a,node b){
	return a.w<b.w;
}
void init(){
	for(int i=1;i<=n+k;i++)fa[i]=i;
}
int find(int x){
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	int tmp=n;
	init();
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e[++m]=node{i+n,j,a[i][j]};
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=e[i].u,y=e[i].v,val=e[i].w;
		int fx=find(x),fy=find(y);
		if(fx==fy)continue;
		if(x>tmp&&!vis[x-tmp]){
			vis[x-tmp]=1;
			n++;
		}
		if(y>tmp&&!vis[y-tmp]){
			vis[y-tmp]=1;
			n++;
		}
		fa[fx]=fy;
		ans+=val;
		ct++;
		if(ct==n-1){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
