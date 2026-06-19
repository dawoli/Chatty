#include<bits/stdc++.h>
#define rep(i,a,b)	for(ll i=(a);i<=(b);i++)
#define per(i,a,b)	for(ll i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
const ll maxn=1e5+9;
ll n,r[maxn],p[maxn];
void solve(){
	sort(r+1,r+1+n);
	ll j=1;
	rep(i,1,n){
		if(r[i]>r[j])	j++;
	}
	cout<<n-j+1;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	rep(i,1,n)	cin>>r[i];
	solve();
	return 0;
}
