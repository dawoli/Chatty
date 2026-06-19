#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll d,v,a;
}c[100005];
ll n,m,L,V,dis[1000006],wh[1000006],clrwh[100005],pmax,pmin,ans1,ans2;
ll redis[1000006];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	
//	db[0]=1;
//	for(ll i=1;i<=25;i++){
//		db[i]=db[i-1]*2;
//	}
	
	while(T--){
		for(ll i=0;i<=pmax;i++){
			dis[i]=0;
			redis[i]=0;
		}
		for(ll i=1;i<=clrwh[0];i++){
			wh[clrwh[i]]=0;
		}
		ans1=0;
		ans2=0;
		pmax=0;
		pmin=10000000;
		
		cin>>n>>m>>L>>V;
		for(ll i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		
		for(ll i=1,pi;i<=m;i++){
			cin>>pi;
			dis[pi]=-1;
			pmax=max(pmax,pi);
			pmin=min(pmin,pi);
		}
		
		for(ll i=pmax,cnt=0;i>=0;i--){
			if(dis[i]==-1){
				cnt=0;
				continue;
			}
			dis[i]=++cnt;
		}
		for(ll i=pmin,cnt=0;i<=pmax;i++){
			if(dis[i]==-1){
				cnt=i;
			}
			redis[i]=cnt;
		}
		
		for(ll i=1;i<=n;i++){
			node k=c[i];
			if(k.a==0){
				if(k.v>V&&k.d<=pmax){
					ans1++;
					if(wh[pmax]==0){
						wh[pmax]=1;
						clrwh[0]++;
						clrwh[clrwh[0]]=pmax;
						ans2++;
					}
				}
			}
			if(k.a>0){
				if(V*V-k.v*k.v+2*k.a*k.d<pmax*2*k.a&&k.d<=pmax){
					ans1++;
					if(wh[pmax]==0){
						wh[pmax]=1;
						clrwh[0]++;
						clrwh[clrwh[0]]=pmax;
						ans2++;
					}
				}
			}
			if(k.a<0){
				if(k.v>=V){
					ll X=ceil((V*V-k.v*k.v)*1.0/(2*k.a)*1.0);
					if(dis[k.d]==-1||X>dis[k.d]){
						ans1++;
						
						ll res=k.d+X,ct;
						if(res>=pmax){
							res=pmax;
						}
						else{
							res=redis[res];
						}
						if(wh[res]==0){
							wh[res]=1;
							clrwh[0]++;
							clrwh[clrwh[0]]=res;
							ans2++;
						}
					}
				}
			}
		}
		cout<<ans1<<' '<<m-ans2<<'\n';
	}
}
//rp++
