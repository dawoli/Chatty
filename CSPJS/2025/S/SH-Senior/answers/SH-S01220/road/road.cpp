#include<bits/stdc++.h>
#define N 10090
#define K 19
using namespace std;
typedef long long ll;
ll n,m,k,c[K];
vector<ll> to[N],w[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++){
		ll a,b,C;
		cin>>a>>b>>C;
		to[a].push_back(b);
		to[b].push_back(a);
		w[a].push_back(C);
		w[b].push_back(C);
	}
	for(ll j=1;j<=m;j++){
		cin>>c[j];
		for(ll i=1;i<=n;i++){
			ll A;
			cin>>A;
			to[j].push_back(i);
			to[i].push_back(j);
			w[j].push_back(A);
			w[i].push_back(A);
		}
	}
	if(k==0){
		
	}
	return 0;
}
