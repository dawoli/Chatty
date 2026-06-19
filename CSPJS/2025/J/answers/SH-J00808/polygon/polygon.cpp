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
const ll maxn=5009;
const ll mod=998244353;
ll n,mxa,a[maxn],f[maxn][maxn];
ll solveBF(){
	ll ans=0;
	ll nPnt=(1<<n);
	rep(p,0,nPnt-1){
		ll sum=0,mx=0;
		rep(i,0,n-1)	if((1<<i)&p)
			sum+=a[i+1],mx=max(mx,a[i+1]);
		if(sum>mx*2)	ans++;
	}
	cout<<ans<<'\n';
	return ans;
}
ll solve(){
	mxa=0;
	rep(i,1,n)	mxa=max(mxa,a[i]);
	mxa++;
	sort(a+1,a+1+n);
	rep(i,0,n)	rep(j,0,mxa)	f[i][j]=0;
	f[0][0]=1;
	rep(i,0,n-1){
		rep(j,0,mxa){
			(f[i+1][j]+=f[i][j])%=mod;
			(f[i+1][min(mxa,j+a[i+1])]+=f[i][j])%=mod;
		}
	}
	ll ans=0;
	rep(i,3,n){
		rep(j,a[i]+1,mxa)
			(ans+=f[i-1][j])%=mod;
	}
	cout<<ans<<'\n';
	return ans;
}
ll N,A[maxn];
void duipai(){
	ll T=5000;
	rep(Tid,1,T){
		N=rand()%5+16;
		rep(i,1,N)	A[i]=rand()%100+1;
		n=N;
		rep(i,1,n)	a[i]=A[i];
		ll ansBF=solveBF();
		n=N;
		rep(i,1,n)	a[i]=A[i];
		ll ans=solve();
		if(ans!=ansBF){
			cout<<"Wrong answer in "<<Tid<<":\n";
			cout<<N<<'\n';
			rep(i,1,N)	cout<<A[i]<<' ';
			cout<<'\n';
			return;
		}
	}
	cout<<"All correct!\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	duipai();
	cin>>n;
	rep(i,1,n)	cin>>a[i];
	solve();
	return 0;
}
