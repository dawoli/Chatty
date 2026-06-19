#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100009 
ll n,m,a[N],c[N],T,x[N][4],K;
char d[20][N*2];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=m;i++)cin>>c[i];
	K=(ll)ceil(log2(n));
	for(ll i=1;i<=K;i++)
	    for(ll j=1;j<=(1<<(K-i));j++)
	        cin>>d[i][j];
	cin>>T;
	for(ll i=1;i<=T;i++)
	    for(ll j=0;j<4;j++)cin>>x[i][j];
	ll ans=0;
	for(ll i=1;i<=m;i++)
	    ans^=(i*c[i]*(c[i]+1)/2);
	for(ll i=1;i<=T;i++)
	    cout<<ans<<"\n"; 
	return 0;
}
