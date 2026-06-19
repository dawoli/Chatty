#include<bits/stdc++.h>
#define rep(i,a,b)	for(ll i=(a);i<=(b);i++)
#define per(i,a,b)	for(ll i=(a);i>=(b);i--)
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll maxn=200009;
const ll mod=998244353;
const ll inf=1e15;
ll n,m,s[maxn],c[maxn];
ll f[1<<19][20];
void solveBF(){
	f[0][0]=1;
	rep(p,0,(1<<n)-2){
		ll cnt=0;
		rep(i,0,n-1)	if((1<<i)&p)
			cnt++;
		rep(x,0,cnt){
			rep(i,0,n-1)	if(!((1<<i)&p)){
				if(cnt-x<c[i+1]&&s[cnt+1])
					(f[p^(1<<i)][x+1]+=f[p][x])%=mod;
				else (f[p^(1<<i)][x]+=f[p][x])%=mod;
			}
		}
	}
//	rep(p,0,(1<<n)-2)	rep(x,0,n){
//		rep(i,0,n-1)
//			cout<<(bool)((1<<i)&p);
//		cout<<' '<<x<<' '<<f[p][x]<<'\n';
//	}
	ll ans=0;
	rep(x,m,n)	(ans+=f[(1<<n)-1][x])%=mod;
	cout<<ans<<'\n';
}
ll p[maxn];
void solvem1(){
	p[0]=1;
	rep(i,1,n)	p[i]=p[i-1]*i%mod;
	sort(c+1,c+1+n);
	ll ans=0,hd=1,cnt=0,res=1;
	rep(i,1,n){
		while(i-1>=c[hd]&&hd<=n)	hd++;
		if(s[i]==0){
//			(res*=n-i+1)%=mod;
			continue;
		}
		cnt++;
		ans+=res*(n-hd+1)%mod*p[n-cnt]%mod;
		ans%=mod;
		if(hd-1<cnt)	break;
		(res*=hd-cnt)%=mod;
//		cout<<i<<' '<<ans<<' '<<res<<'\n';
	}
	cout<<ans<<'\n';
}
/*bool checkA(){
	rep(i,1,n)	if(!s[i])	return 0;
	return 1;
}
void solveA(){
	ll cnt=0;
	rep(i,1,n)	if(c)
}*/
void solvemn(){
	bool ok=1;
	rep(i,1,n)	ok&=s[i];
	rep(i,1,n)	ok&=(c[i]>0);
	if(!ok)	cout<<"0\n";
	else{
		ll res=1;
		rep(i,1,n)	(res*=i)%=mod;
		cout<<res<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n){
		char ch;
		cin>>ch;
		s[i]=ch=='1';
	}
	rep(i,1,n)	cin>>c[i];
	if(n<=18)	solveBF();
	else if(m==1)	solvem1();
	else if(m==n)
		solvemn();
//	if(checkA())	solveA();
	return 0;
}
