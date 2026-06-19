#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int u,v,w;
}e[20000005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int c[12][100005],f[100005];
int find(int x){
	if(f[x]==x) return f[x];
	return f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
        for(int j=1;j<=n;j++){
        	cin>>c[i][j];
		}
	}
	int cnt=m;
	for(int i=1;i<=k;i++){
		for(int j=1;j<n;j++){
			for(int t=i+1;t<=n;t++){
				e[++cnt].u=j;e[cnt].v=t;
				e[cnt].w=c[i][0]+c[i][j]+c[i][t];
			}
		}
	}
	sort(e+1,e+1+cnt,cmp);
	int ct=0,ans=0;
	for(int i=1;i<=cnt;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		ans+=e[i].w;
		ct++;
		f[x]=y;
		if(ct==n-1) break;
	}
	cout<<ans<<endl;
	return 0;
}
