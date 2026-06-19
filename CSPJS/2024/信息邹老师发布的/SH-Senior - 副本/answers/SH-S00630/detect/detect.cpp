#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Cars{
	int a;
	int v;
	int d;
};
int n,m,L,V;//n--car m--speed L-length V--limit
void solve(){
	int limit[100009]={};
	Cars car[100009]={};
	int ans=0;
	bool isAorB=1;
	for(int i=1;i<=n;i++) cin>>car[i].d>>car[i].v>>car[i].a;
	for(int i=1;i<=m;i++) cin>>limit[i];
	for(int i=1;i<=n;i++){
		if(car[i].a<0) isAorB=0;
		if(car[i].a>=0){
			if(limit[m]>=car[i].d)
				if(car[i].v*car[i].v+2*car[i].a*(limit[m]-car[i].d)>V*V) ans++;
		}
		else{
			if(car[i].v<V) continue;
			double s=(V*V-car[i].v*car[i].v)/(2*car[i].a)+car[i].d;
			for(int j=1;j<=m;j++){
				if(limit[j]>=car[i].d){
					if(car[i].v*car[i].v+2*car[i].a*(limit[j]-car[i].d)>V*V){
						ans++;
						break;
					}
				}
			}
		}
	}
	cout<<ans<<" ";
	if(isAorB and ans!=0) cout<<m-1<<"\n";
	else{
		cout<<m<<"\n";
	}
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>L>>V;
		solve();
	}
}
