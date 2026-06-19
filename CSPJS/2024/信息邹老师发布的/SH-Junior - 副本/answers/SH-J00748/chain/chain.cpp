#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
const ll maxn=2e5+9;
ll n,k,q,sl,r[maxn],c[maxn];
vector<ll> s[maxn];
map<ll,ll> mp;
bool b[maxn];
bool check1(){
	if(!(n<=1000&&sl<=2000&&q<=1000))	return 0;
	rep(i,1,q)	if(r[i]!=1)	return 0;
	return 1;
}
void solve1(){
	mp.clear();
	ll m=0;
//	rep(i,1,n){
//		for(ll j=0;j<s[i].size();j++){
//			ll x=s[i][j];
//			if(mp[x]==0)	mp[x]=++m;
//			s[i][j]=mp[x];
//		}
//	}
	memset(b,0,sizeof b);
	rep(i,1,n){
		ll l=s[i].size();
		rep(j,0,l-1){
			if(s[i][j]!=1)	continue;
			rep(p,1,k-1)	if(j+p<l)	b[s[i][j+p]]=1;
		}
	}
	b[0]=0;
	rep(i,1,q){
		cout<<b[c[i]]<<'\n';
	}
}
bool check2(){
	if(!(n<=10&&sl<=20&&q<=100))	return 0;
	rep(i,1,q)	if(r[i]>5)	return 0;
	return 1;
}
bool f[109][109][209];
ll g[109][209];
void solve2(){
	mp.clear();
	ll m=0;
	rep(i,1,n){
		for(ll j=0;j<s[i].size();j++){
			ll x=s[i][j];
			if(mp[x]==0)	mp[x]=++m;
			s[i][j]=mp[x];
		}
	}
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	rep(i,1,n)	f[0][i][1]=1;
	g[0][1]=n;
	ll mxr=0;
	rep(i,1,q)	mxr=max(r[i],mxr);
	rep(ri,1,mxr)
		rep(i,1,n)	rep(c,1,m){
			ll l=s[i].size();
			rep(j,0,l-1)	if(s[i][j]==c&&!f[ri][i][c]){
				rep(p,1,k-1){
					ll nj=j-p;
					if(nj<0)	continue;
					bool x=0;
					ll y=g[ri-1][s[i][nj]];
					if(y>=2||(y==1&&!f[ri-1][i][s[i][nj]]))	x=1;
					f[ri][i][c]|=x;
					if(f[ri][i][c])	break;
				}
			}
			g[ri][c]+=f[ri][i][c];
		}
	rep(qid,1,q){
		ll qr=r[qid],qc=c[qid];
		if(mp[qc]==0){
			cout<<0<<'\n';
			continue;
		}
		cout<<bool(g[qr][mp[qc]])<<'\n';
	}
}
void mymain(){
	cin>>n>>k>>q;
	sl=0;
	rep(i,1,n){
		s[i].clear();
		ll l,x;
		cin>>l;
		sl+=l;
		while(l-->0){
			cin>>x;
			s[i].push_back(x);
		}
	}
	rep(i,1,q)	cin>>r[i]>>c[i];
	if(check1())	solve1();
	else
//		if(check2())
			solve2();
	rep(i,1,n)	s[i].clear();
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ll T;
	cin>>T;
	while(T-->0){mymain();}
	return 0;
} 
