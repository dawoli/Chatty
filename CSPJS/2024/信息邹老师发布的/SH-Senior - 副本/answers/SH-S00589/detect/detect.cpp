#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,L,V;
ll T;
struct node {
	ll x;
	ll v;
	ll a;
} arr[100009];
long double p[100009];
struct edge {
	ll lef=999999,rig=999999;
} mm[100009];
bool cmp(const edge &a,const edge &b){
	return a.lef<b.lef;
}

ll erf(ll x){
	ll l=1;
	ll r=m;
	while(l<r){
		int mid=(l+r)/2;
		if(p[mid]>=x){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	return l;
}
ll ans=0;
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n>>m>>L>>V;
		for(int i=1; i<=n; i++)cin>>arr[i].x>>arr[i].v>>arr[i].a;
		for(int i=1; i<=m; i++)cin>>p[i];
		for(int i=1; i<=n; i++) {
			//匀速
			if(arr[i].a==0&&arr[i].v>V)ans++;
			if(arr[i].a<0&&arr[i].v<=V)continue;
			if(arr[i].a>0&&arr[i].x>p[m])continue;
			//减速
			if(arr[i].a<0){
				ll s=2*arr[i].a*arr[i].x+V*V-arr[i].v*arr[i].v;
				ll l=1;
				ll r=m;
				while(l<r){
					int mid=(l+r)/2;
					if(p[mid]*2*arr[i].a<s+arr[i].x){
						r=mid;
					}
					else{
						l=mid+1;
					}
				}
				ans++;
			}
			//加速
			if(arr[i].a>0) {
				ll s=2*arr[i].a*arr[i].x+V*V-arr[i].v*arr[i].v;
				if(s<0){
					mm[i].rig=m;
				}
				else{
					mm[i].rig=erf(s+arr[i].x);
				}
					mm[i].lef=erf(arr[i].x);
				ans++;
			}
		}
	}
	sort(mm+1,mm+n+1,cmp);
	int o=1;
	ll ans1=0; 
	for(int j=1;j<=m;j++){
		if(mm[o].lef==999999){break;}
		while(p[j]<=mm[o].rig){
			j++;
			ans1++;
		}
	}
	cout<<ans-1<<" "<<ans1+1;
	return 0;
}
