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
ll n,m,a[maxn];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n*m)	cin>>a[i];
	ll cnt=0;
	rep(i,2,n*m)	if(a[i]>a[1])	cnt++;
	ll lie=cnt/n+1;
	ll hang=(lie%2==0?n-cnt%n:1+cnt%n);
	cout<<lie<<' '<<hang;
	return 0;
}
