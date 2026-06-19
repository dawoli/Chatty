#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+10;
int n,m,k,u[N],v[N],w[N],c[N],a[15][N/10+5],sum;

void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		sum+=c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			sum+=a[i][j];
		}
	}
	if(sum==0){
		cout<<sum;
		return
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
} 
