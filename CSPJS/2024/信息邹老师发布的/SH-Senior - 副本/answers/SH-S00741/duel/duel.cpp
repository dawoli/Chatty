#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,r[100009];
ll m,val[100009],cnt[100009];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&r[i]);
	sort(r+1,r+n+1);
	val[++m]=r[1];cnt[m]=1;
	for(ll i=2;i<=n;i++){
		if(r[i]!=val[m]){
			val[++m]=r[i];
			cnt[m]=1;
		}
		else cnt[m]++;
	}
	ll precnt=0;
	for(ll i=1;i<=m;i++){
		precnt-=cnt[i];
		precnt=max(precnt,0LL);
		precnt+=cnt[i];
	}
	printf("%lld\n",precnt);
	return 0;
}
