#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1009;

ll T, n, m;
ll a[N], c[N], st[N];
string s[N];
ll x[4];
ll lg[N];

int main(){
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	
	cin>>n>>m;
	for(ll i=2; i<=n; i++) lg[i]=lg[i/2]+1;
	for(ll i=1; i<=n; i++) cin>>a[N];
	for(ll i=1; i<=m; i++) cin>>c[i];
	
	for(ll i=1; i<=lg[n]+1; i++) cin>>s[i];
	
	cin>>T;
	for(ll i=1; i<=T;i++){
		for(ll i=0; i<4; i++) cin>>x[i];
		for(ll i=1; i<=n; i++)
			st[i] = a[i]^(x[i%4]);
		ll nnn = n, ans=0;
		for(ll i=1; i<=m; i++){
			n=c[i];
		ll ok[N][2], nn=n;
		for(ll i=1; i<=n; i++) ok[i][0]=i;
		for(ll i=0; i<=lg[n]; i++, nn/=2){
			for(ll j=1, w=0; j<=nn; j+=2){
				if(s[i][(j+1)/2-1]=='1'){
					ll lz = ok[j+1][i&1];
					if(a[lz]>=i) 
						ok[++w][!(i&1)] = lz;
					else
						ok[++w][!(i&1)] = ok[j][i&1];
				}
				else{	
					ll lz = ok[j][i&1];
					if(a[lz]>=i) 
						ok[++w][!(i&1)] = lz;
					else
						ok[++w][!(i&1)] = ok[j+1][i&1];
				}
			}
		}
		ll ls = lg[n]+1;
		ll res=ok[1][ls&1];
		ans^=(res*i);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
