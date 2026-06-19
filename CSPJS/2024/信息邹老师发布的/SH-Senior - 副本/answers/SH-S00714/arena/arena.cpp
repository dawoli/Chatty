#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(b);i>=(a);--i)
#define all(x) x.begin(),x.end()
#define cll const ll
#define Set(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
using namespace std;
cll N=100009;
ll a[N],b[N],LOG2[N];
ll qwerr[N],asdfg[N],n,m,K,q[N];
vector<ll> G[N];
void calc(){rep(i,1,n)a[i]=b[i]=min((qwerr[i]^asdfg[i%4]),K);}
bool judge_2n(ll x){return (1<<LOG2[x])==x;}
namespace PartP{
	ll lmt=0,ans[N],pp=0; set<ll> s;
	ll ddd(ll x,ll l){
		if(x==K-1){
			if(G[x][l-1])return l*2-1+(b[l*2]>0);
			return l*2-(b[l*2-1]>0);
		}
		ll L=ddd(x+1,l*2-1),R=ddd(x+1,l*2);
		if(G[x][l-1])return b[R]>=K-x?R:L;
		return b[L]>=K-x?L:R;
	}
	void enumer(ll x){
		if(x==lmt+1){s.insert(ddd(K-pp,1)); return;}
		rep(i,0,K){
			b[x]=i;
			enumer(x+1);
		}
	}
	void solveBF(){
		ans[1]=1; b[1]=a[1];
		lmt=2; pp=1;
		rep(i,2,n){
			s.clear(); b[i]=a[i];
			enumer(i+1); ans[i]=0;
			for(set<ll>::iterator it=s.begin();it!=s.end();it++)ans[i]+=*it;
			if(i==lmt)lmt<<=1,pp++;
		}
		ll t=0;
		rep(i,1,m)t^=i*ans[q[i]];//,cout<<ans[i]<<endl;
		cout<<t<<endl;//<<endl;
	}
	void solve2n(){
		ans[1]=1; rep(i,1,n)b[i]=a[i];
		rep(i,1,LOG2[n])ans[1<<i]=ddd(K-i,1);
		ll t=0;
		rep(i,1,m)t^=i*ans[q[i]];
		cout<<t<<endl;
	}
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	rep(i,2,100000)LOG2[i]=LOG2[i>>1]+1;
	cin>>n>>m;rep(i,1,n)cin>>qwerr[i]; bool all_2n=1; rep(i,1,m)cin>>q[i],all_2n&=judge_2n(q[i]);
	K=1-judge_2n(n)+LOG2[n];
	rep(i,1,K){
		ll num=(1<<K-i);
		rep(j,1,num){char c;cin>>c; G[K-i].push_back(c-'0');}
	}
	ll T;cin>>T;
	while(T--){
		rep(i,0,3)cin>>asdfg[i]; calc();
		if(all_2n)PartP::solve2n();
		else PartP::solveBF();
	}
	return 0;
}

