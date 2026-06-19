#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int a[15][10005];
struct edge{
	int u,v,w; 
}e[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
map<int,int>ma;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		int x;cin>>x;
		for(int j=1;j<=n;j++){
			cin>>x;
		}
	}
	sort(e+1,e+1+n,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(ma[u]==0||ma[v]==0){
			ans+=e[i].w;
			ma[u]=1;ma[v]=1;
		}
	} 
	cout<<ans<<endl;
} 
