#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
const ll M=19;
ll T,a_[N],c[N],n,m,x[5],f[M][N],a[N];
void MAIN()
{
	cin>>x[1]>>x[2]>>x[3]>>x[4];
	for(ll i=1;i<=n;i++)a[i]=(a_[i]^(x[i%4]));
	ll ans=0;
	for(ll i=1;i<=n;i++)ans^=a[i];
	cout<<ans<<endl;
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a_[i];
	for(ll i=1;i<=m;i++)cin>>c[i];
	ll K=log(n)/log(2);
	if(pow(2,K)<n)K++;
	for(ll i=1;i<=K;i++)for(ll j=1;j<=pow(2,K-i);j++)cin>>f[i][j];
	cin>>T;
	while(T--)MAIN();
	return 0;
}
