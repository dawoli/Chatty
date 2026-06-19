#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
int u,c,vst[10019],q[19][10009],n,m,k,d[10019],p[10009][10009],f,x,y,z,ans=INF,cnt;
void dijkstra(int s){
	for (int i=1;i<=n;i++) vst[i]=0;
	f=s;
	cnt=0;
	while(1){
		u=-1;
		c=INF-1;
		for (int i=1;i<=n;i++){
			if (vst[i]&&z>=p[f][i]) continue;
			u=i;
			z=p[f][i];
		}
		if (u==-1) break;
		ans+=c;
		vst[u]=1;
	}
}
void solve(){
	for (int i=1;i<=n;i++){
		dijkstra(i);
		ans=min(ans,cnt);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) p[i][j]=INF;
	}
	for (int i=1;i<=m;i++){
		cin>>x>>y>>z;
		p[x][y]=z;
		p[y][x]=z;
	}
	for (int i=1;i<=k;i++){
		for (int j=0;j<=n;j++){
			cin>>q[i][j];
			for (int o=1;o<=n;o++){
				for (int l=o+1;l<=n;l++){
					p[l][o]=p[o][l]=min(p[o][l],q[i][o]+q[i][l]); 
				}
			}
		}
	}
	solve();
	cout<<ans<<endl;
	return 0;
}
