#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000009
#define N 10029
int n,m,k,id[N],nE,nE1;
ll ans,c[20],a[20][N];
struct E{
	int u,v;
	ll w;
}e[M],e1[N*20],e2[N*20];
int root(int u){
	return u==id[u]?u:id[u]=root(id[u]);
}
void unite(int x,int y){
	int rx=root(x),ry=root(y);
	if(rx!=ry)id[rx]=ry;
}
bool cmp(E ex,E ey){
	return ex.w<ey.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)id[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;ll w;
		cin>>u>>v>>w;
		e[++nE]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	sort(e+1,e+1+m,cmp);
//	for(int j=1;j<=nE;j++)cout<<e[j].u<<" "<<e[j].v<<" "<<e[j].w<<"\n"; 
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(root(u)!=root(v))e1[++nE1]={u,v,e[i].w},ans+=e[i].w,unite(u,v);
	}
//	for(int j=1;j<=nE1;j++)cout<<e1[j].u<<" "<<e1[j].v<<" "<<e1[j].w<<"\n"; 
	for(int i=1;i<(1<<k);i++){
		int nE2=0,cnt=0,cnt1=0;ll ans2=0;
		for(int j=1;j<=n+10;j++)id[j]=j;
		for(int j=1;j<=nE1;j++)e2[++nE2]=e1[j];
		for(int j=1;j<=k;j++){
			if(i&(1<<j-1)){
				for(int p=1;p<=n;p++)
					e2[++nE2]={n+j,p,a[j][p]};
				ans2+=c[j];
				cnt1++;
			}
		}
		sort(e2+1,e2+1+nE2,cmp);
//		for(int j=1;j<=nE2;j++)cout<<e2[j].u<<" "<<e2[j].v<<" "<<e2[j].w<<"\n"; 
		for(int j=1;j<=nE2;j++){
			int u=e2[j].u,v=e2[j].v;
			if(root(u)!=root(v))ans2+=e2[j].w,unite(u,v),cnt++;
//			cout<<cnt<<" "<<ans2<<"\n";
			if(cnt==n-1+cnt1){
				ans=min(ans,ans2);
//				cout<<cnt<<"11111111111111111\n";
				break;
			}
			if(ans2>=ans)break;
		}
	}
	cout<<ans;
	return 0;
} 
