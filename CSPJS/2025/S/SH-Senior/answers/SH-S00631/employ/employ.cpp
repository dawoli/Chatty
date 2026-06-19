#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m;
ll s[505],c[505],ans=1;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&s[i]);
	}	
	for(int i=1;i<=n;i++) {
		scanf("%lld",&c[i]);
	}
	if(n<m) {
		printf("0\n"); return 0; 
	}
	for(int i=n;i>=1;i--) {
		ans*=i%mod;
		ans%=mod;
	}
	printf("%lld\n",ans%mod);
	return 0;
} 
/*

*/
