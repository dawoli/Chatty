#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000009;
ll n,m,k,ans,cost[19],r[19][N];
bool vst[N];
struct road{
	ll u,v,l,extra;
}a[N];
bool cmp(const road&a,const road&b){
	if(a.l<b.l)return 1;
	if(a.l>b.l)return 0;
	return 1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].l;
		a[i].extra=0;
	}
	for(ll i=1;i<=k;i++){
		cin>>cost[i];
		for(ll j=1;j<=n;j++){
			cin>>r[i][j];
		}
	}
	sort(a+1,a+1+m,cmp);
	for(ll i=1;i<=m;i++){
		if(vst[a[i].u]&&vst[a[i].v])continue;
		ans+=a[i].l;
		vst[a[i].u]=1,vst[a[i].v]=1;
	}
	cout<<ans;
	return 0;
}
