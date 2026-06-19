#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
struct edges{
	ll u,v,w;
}a[1000005];
bool cmp(edges x,edges y){
	return (x.w<y.w);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for (ll i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		//fa[a[i].u]=a[i].v;
	}
	sort(a+1,a+m+1,cmp);
	ll tmp;
	for (ll i=1;i<=k;i++){
		for (ll j=1;j<=n+1;j++){
			cin>>tmp;
		}
	}
	ll ans=0;
	for (ll i=1;i<=m-1;i++){
		ans+=a[i].w;
	}
	cout<<ans<<endl;
	
	return 0;
}
