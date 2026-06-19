#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N=1e5+10;
ll n;
ll a[N];
struct Fenwick{
	vector<ll> bit;
	Fenwick(ll n):bit(n+10) {}
	inline ll lowbit(ll x){
		return x&(-x);
	}
	inline void add(ll x,ll k){
		x++;
		for(ll i=x;i<bit.size();i+=lowbit(i))
			bit[i]+=k;
	}
	inline ll query(ll x){
		x++;
		ll ans=0;
		for(ll i=x;i;i-=lowbit(i))
			ans+=bit[i];
		return ans; 
	}
}t(N);
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	ll cnt=0;
	t.add(a[1],1);
	for(ll i=2;i<=n;i++){
		ll tmp=t.query(a[i]-1);
		if(tmp-cnt>0)
			cnt++;
		t.add(a[i],1);
	}
	cout<<n-cnt<<endl;
	return 0;
}
