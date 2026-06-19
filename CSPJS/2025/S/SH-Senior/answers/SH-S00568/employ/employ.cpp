#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509;
const ll MOD=998244353;
ll n,m,c[N],p[N]; 
char s[N];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) p[i]=i;
	ll ans=0;
	do{
		ll cnt=0;
		for(int i=1;i<=n;i++){
			if(i-1-cnt>=c[p[i]]) continue;
			if(s[i]=='1') cnt++; 
		}
		if(cnt>=m) ans=(ans+1)%MOD;	
	}while(next_permutation(p+1,p+1+n));
	cout<<ans<<endl;
	return 0;
}

