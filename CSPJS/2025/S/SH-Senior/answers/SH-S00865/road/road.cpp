#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Edges{
	int u,v,w;
}to[5000005];
bool cmp(Edges a,Edges b){
	return a.w<b.w;
}
int dfn[1000005];
int find(int u){
	if(dfn[u]==u){
		return u;
	}
	else{
		return find(dfn[u]);
	}
}
int idx=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>to[i].u>>to[i].v>>to[i].w;
	}
	for(int i=1;i<=k;i++){
		int t;
		cin>>t;
		int r[10005];
		for(int j=1;j<=n;j++){
			cin>>r[j];
		}
		for(int j=1;j<=n;j++){
			for(int q=1;q<j;q++){
				idx++;
				to[idx+m].u=q;
				to[idx+m].v=j;
				to[idx+m].w=r[q]+r[j]+t;
			}
		}
	}
	sort(to+1,to+m+idx+1,cmp);
	for(int i=1;i<=n;i++){
		dfn[i]=i;
	}
	int cnt=0,ans=0;
	for(int i=1;i<=m+idx+1;i++){
		int u=to[i].u;
		int v=to[i].v;
		int w=to[i].w;
		int ttt=find(u);
		if(ttt!=find(v)){
			dfn[v]=ttt;
			cnt++;
			ans+=w;
		}
		if(cnt>=n-1){
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
