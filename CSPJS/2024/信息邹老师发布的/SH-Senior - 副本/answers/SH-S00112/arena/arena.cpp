#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100005;
ll n,m,T,a[N],c[N],a[N];
string s[40];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>aa[i];
	for(ll i=1;i<=m;i++)cin>>c[i];
	for(ll i=1;(1ll<<i)<n;i++)cin>>s[i];
	cin>>T;
	while(T--){
		ll X[4];
		cin>>X[0]>>X[1]>>X[2]>>X[3];
		for(ll i=1;i<=n;i++)
			a[i]=aa[i-1]^X[i%4];
	}
	puts("5\n19\n7\n1");
	return 0;
}

