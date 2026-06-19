#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
const ll maxn=1e5+9;
const ll num[]={6,2,5,5,4,5,6,3,7,6};
ll n,f[maxn],g[maxn];
void solve(){
	if(n==1){
		cout<<"-1\n";
		return;
	}
	f[1]=g[1]=-1;
	f[0]=g[0]=0;
	rep(s,2,n){
		rep(i,1,9){
			ll x=s-num[i];
			if(x<0||x==1)	continue;
			if(x>(s-1)/7*7)	continue;
			f[s]=i;
			break;
		}
		rep(i,0,9){
			ll x=s-num[i];
			if(x<0||x==1)	continue;
			if(x>(s-1)/7*7)	continue;
			g[s]=i;
			break;
		}
//		cout<<f[s]<<' '<<g[s]<<'\n';
	}
	ll s=n;
	cout<<f[s];
	s-=num[f[s]];
//	cout<<s<<'\n';
	while(s!=0)	cout<<g[s],s-=num[g[s]];
	cout<<'\n';
}
void mymain(){
	cin>>n;
	solve();
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ll T;
	cin>>T;
	while(T-->0){mymain();}
	return 0;
} 
