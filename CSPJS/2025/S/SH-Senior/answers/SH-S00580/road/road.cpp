#include<bits/stdc++.h>
using namespace std;
const int N=1e4+9,M=2e6+9;
typedef long long ll;
ll n,m,k,ans;
ll c[N],a[20][N];
struct road{
	ll u,v,w;
}r[M];
bool cmp(road a,road b){
	return a.w<b.w;
}
bool vst[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(k==0){
		sort(r+1,r+1+n,cmp);
		for(ll i=1;i<=n;i++){
			if(vst[r[i].u]&&vst[r[i].v]) continue;
			ans+=r[i].w;
			vst[r[i].u]=1;
			vst[r[i].v]=1;
		}
		cout<<ans<<endl;
	}else{
		ll num=m+1;
		for(ll i=1;i<=k;i++){
			for(ll j=1;j<=n;j++){
				if(i!=j&&c[i]==0){
					r[num].u=i;
					r[num].v=j;
					r[num].w=a[i][j];
					num++;
				}
			}
		}
		sort(r+1,r+num,cmp);
		for(ll i=1;i<=n;i++){
			if(vst[r[i].u]&&vst[r[i].v]) continue;
			ans+=r[i].w;
			vst[r[i].u]=1;
			vst[r[i].v]=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
