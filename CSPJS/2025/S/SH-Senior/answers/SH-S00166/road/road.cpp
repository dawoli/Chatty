#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k; 
ll c[19],a[19][10009];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++)cin>>a[j][i];
	}
	if(k==0){//16
		
	}
	return 0;
}
