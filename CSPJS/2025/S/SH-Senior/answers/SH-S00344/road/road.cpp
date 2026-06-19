#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,M=1e4+10;
ll u[N],v[N],w[N],c[20],a[M][M],f[M][M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(f,10000,sizeof f);
	ll n,m,k,cnt=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		f[u[i]][v[i]]=f[u[i]][v[i]]=w[i];
		cnt+=w[i];
	}
	int f1=0;
	for(int j=1;j<=k;j++){
		cin>>c[j];
		if(c[j]!=0){
			f1=1;
		}
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][j-1]+f[j-1][j]);
			}
		}
		cout<<f[1][n];
		return 0;
	}
	if(!f1){
		for(int i=1;i<=n+k;i++){
			for(int j=i+1;j<=n+k;j++){
				f[i][j]=max(f[i][j-1]+a[j-1][j],a[i][j]);
				//cout<<f[i][j]<<" "<<a[i][j]<<"\n";
			}
		}
		cout<<f[k][n];
		return 0;
	}
	cout<<cnt;
	return 0;
}

