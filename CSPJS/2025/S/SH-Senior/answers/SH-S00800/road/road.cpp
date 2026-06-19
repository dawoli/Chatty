#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct bbq{
	ll u,v,w;
};
bbq x[100009];
ll n,m,k,ans,cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i].u>>x[i].v>>x[i].w;
		cnt+=x[i].w;
	}
	ans=cnt;
	for(int i=1;i<=k;i++){
		cnt=0;
		for(int j=0;j<=n;j++){
			ll abc;
			cin>>abc;
			cnt+=abc;
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
	return 0;
}
