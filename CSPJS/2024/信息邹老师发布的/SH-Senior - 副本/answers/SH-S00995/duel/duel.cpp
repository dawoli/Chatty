#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
ll a[N],cnt[N],v[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ll n,ans=0;
	cin>>n;
	for(ll i = 1;i <= n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	sort(a+1,a+n+1);
	ll maxn=0;
	for(ll i = 1;i <= n;i++){
		maxn=max(maxn,cnt[a[i]]);
	}
	cout<<maxn;
	return 0;
} 

