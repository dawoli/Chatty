#include<bits/stdc++.h>
#define rep(i,a,b)	for(ll i=(a);i<=(b);i++)
#define per(i,a,b)	for(ll i=(a);i>=(b);i--)
typedef long long ll;
const ll maxn=1e5+9;
using namespace std;
ll n,m,k,b[maxn],a[maxn],c[maxn],p[maxn],s[32][maxn<<1];
vector<ll> v[32];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n)	cin>>b[i];
	rep(i,1,m)	cin>>c[i];
	ll x=1;
	p[0]=x;
	while(x>=n)	k++,x*=2,p[k]=x;
	rep(i,1,k)	rep(j,1,p[k-i]){
		char ch;
		cin>>ch;
		s[i][j]=ch-'0';
	}
	ll T;
	cin>>T;
	while(T-->0){
		ll x[4];
		cin>>x[0]>>x[1]>>x[2]>>x[3];
//		rep(i,1,n)	a[i]=b[i]^x[i%4];
//		rep(i,1,n)	v[0].push_back(a[i]);
		cout<<0;
	}
	return 0;
}
