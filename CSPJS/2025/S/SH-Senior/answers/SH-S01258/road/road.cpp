#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m,k,c[15],a[15][10005];
ll ans;
bool ues[15]; 
struct s{
	int to;
	ll va;
};
vector<s> side[10100];
ll ma[10005][10005];
ll dij[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	//memset(ma,sizeof(ma),0x7f7f7f7f);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		side[u].push_back({v,w});
		side[v].push_back({u,w});
	}
		//cin>>rd[i].u>>rd[i].v>>rd[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}		
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int l=1;l<=k;l++){	
				side[i].push_back({j,a[l][i]+a[l][j]+c[l]});
				side[j].push_back({i,a[l][i]+a[l][j]+c[l]});	
			}
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=0;j<side[i].size();j++){
			if(ma[i][side[i][j].to]>side[i][j].va || ma[i][side[i][j].to]==0){
				ma[i][side[i][j].to]=side[i][j].va;
				ma[side[i][j].to][i]=side[i][j].va;
			}
		}
	}
	for(int i=2;i<=n;i++){
		dij[i]=ma[1][i];
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			dij[i]=min(dij[i],ma[j][i]);
		}
	}
	for(int i=2;i<=n;i++){
		ans+=dij[i];
	}
	/*for(int i=2;i<=n;i++){
		ans+=ma[i-1][i];
	}*/
	cout<<ans<<endl;
} 	
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
