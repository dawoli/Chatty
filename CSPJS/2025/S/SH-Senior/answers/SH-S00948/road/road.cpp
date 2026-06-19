#include<bits/stdc++.h>
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define el <<"\n"
#define fi first
#define sc second
using namespace std;
typedef long long ll;
pair<ll,pair<ll,ll>> V[1000005];
ll C[15],B[15];
pair<ll,ll> A[15][10005];
bool U[15];
ll f[10005];
ll find(ll x){
	if(f[x]==x){
		return x;
	}else {
		return f[x]=find(f[x]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	rep(i,1,m){
		ll u,v,w;
		cin>>u>>v>>w;
		V[i]={w,{u,v}};
	}
	sort(V+1,V+m+1);
	rep(i,1,k){
		cin>>C[i];
		rep(j,1,n){
			cin>>A[i][j].fi;
			A[i][j].sc=j;
		}
		sort(A[i]+1,A[i]+n+1);
	}
	ll ans=1e18;
	rep(i,0,(1<<k)-1){
		rep(i,1,n+k){
			f[i]=i;
		}
		rep(i,0,k){
			B[i]=1;
		}
		int cnt=n-1;
		ll S=0;
		rep(j,1,k){
			if(i&(1<<j)){
				cnt++;
				S+=C[j];
			}
		}
		while(cnt){
			int j=0,mi=V[B[0]].fi;
			rep(l,1,k){
				if(i&(1<<l)){
					if(A[l][B[l]].fi<mi){
						j=l;
						mi=A[l][B[l]].fi;
					}
				}
			}
			int u,v;
			if(j==0){
				u=V[B[0]].sc.fi;
				v=V[B[0]].sc.sc;
			}else{
				u=n+j;
				v=A[j][B[j]].sc;
			}
			B[j]++;
			if(find(u)==find(v)){
				continue;
			}else{
//				cout<<u<<" "<<v el;
				f[find(u)]=find(v);
				S+=mi;
				cnt--;
			}
		}
		ans=min(ans,S);
	}
	cout<<ans;
}
