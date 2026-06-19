#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000009;
ll n,cnt[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		cnt[x]++;
	} 
	ll res=0;
	for(ll i=1;i<=100000;i++){
		res-=min(res,cnt[i]);
		res+=cnt[i];
	}
	cout<<res<<endl;
	return 0;
}
