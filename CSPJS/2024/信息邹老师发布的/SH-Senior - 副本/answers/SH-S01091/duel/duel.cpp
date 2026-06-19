#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,a[N],sum; 
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=0;i<n;i++){
		ll tmp;
		scanf("%lld",&tmp);
		a[tmp]++;
	}
	for(ll i=1;i<=1e5;i++){
		sum=max(0ll,sum-a[i])+a[i];
	}
	printf("%lld",sum);
	return 0;
}
