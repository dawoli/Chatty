#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100100],sum=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		ll x;
		scanf("%lld",&x);
		a[x]++;
	}
	for(ll i=1;i<=100000;i++){
		sum=max(sum,a[i]);
	}
	printf("%lld",sum);
	return 0;
}