#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
const int maxn=1e4+1;
vector<pair<int,ll>> vc[maxn];
ll c[11][maxn],ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
