#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++) 
#define per(i,a,b) for(ll i=(a);i>=(b);i--) 
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull; 
typedef pair<ll,ll> pll; 
const ll maxn=1000009;
ll n,k,a[maxn],s[maxn];
set<ll> st;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	rep(i,1,n)	cin>>a[i];
	rep(i,1,n)	s[i]=s[i-1]^a[i];
	ll cnt=0;
	st.insert(0);
	rep(i,1,n){
		if(st.find(s[i]^k)!=st.end()){
			cnt++;
			st.clear();
		}
		st.insert(s[i]);
	}
	cout<<cnt;
	return 0;
}
