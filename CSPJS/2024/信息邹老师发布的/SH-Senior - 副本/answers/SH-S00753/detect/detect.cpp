#include<bits/stdc++.h>
#define rep(i,a,b)	for(ll i=(a);i<=(b);i++)
#define per(i,a,b)	for(ll i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
typedef double ld;
const ll maxn=1e5+9;
const ll inf=1e18;
const ld esp=1e-6;
ll n,m,L,V,d[maxn],v[maxn],a[maxn],p[maxn];
bool over[maxn],nover[maxn];
ld get_v(ll v0,ll a,ll s){
	if(v0*v0+2*a*s<0)	return 0;
	return sqrt(v0*v0+2*a*s);
}
bool le(ld a,ld b){
	return b-a>esp;
}
bool check_is_over(ll v,ll a,ll s){
	if(a==0)	return v>V;
	ld x=(V*V-v*v)/(2*(ld)a);
	if(a>0)	return le(x,s);
	else return le(s,x);
}
void solveBF(){
	ll res=0;
	rep(i,1,n){
		over[i]=0;
		rep(j,1,m){
//			cout<<v[i]<<' '<<a[i]<<' '<<p[j]<<' '<<d[i]<<' ';
//			cout<<check_is_over(v[i],a[i],p[j]-d[i])<<'\n';
			if(d[i]>p[j])	continue;
			over[i]|=check_is_over(v[i],a[i],p[j]-d[i]);
		}
		if(over[i])	res++;
	}
	ll nPnt=(1<<m)-1,ans=0;
	rep(P,0,nPnt){
		rep(i,1,n)	nover[i]=0;
		rep(i,1,n)	rep(j,1,m)	if((1<<(j-1))&P){
			if(d[i]>p[j])	continue;
			nover[i]|=check_is_over(v[i],a[i],p[j]-d[i]);
		}
		bool ok=1;
		rep(i,1,n)	if(over[i]!=nover[i]){ok=0;break;}
		if(!ok)	continue;
		ll cnt=0;
		rep(i,0,m-1)	if((1<<i)&P)	cnt++;
		ans=max(ans,m-cnt);
	}
	printf("%lld %lld\n",res,ans);
}
ll l[maxn],r[maxn];
struct Car{
	ll l,r;
	bool operator<(const Car&x){
		return r<x.r||r==x.r&&l<x.l;
	}
}cars[maxn];
void solve(){
	ll k=0;
	rep(i,1,n){
		if(a[i]==0){
			if(v[i]>V)	l[i]=d[i],r[i]=L;
			else	l[i]=r[i]=0;
			continue;
		}
		ld x=d[i]+(V*V-v[i]*v[i])/(2*(ld)a[i]);
		if(a[i]>0){
			l[i]=max(d[i],ll(x+1));
			r[i]=L;
		}
		else{
			l[i]=d[i];
			r[i]=min(ll(x-esp),L);
		}
	}
	ll res=0;
	rep(i,1,n){
		over[i]=0;
		if(l[i]>r[i])	continue;
		ll x=lower_bound(p+1,p+1+m,l[i])-p;
		if(x>m)	continue;
		if(p[x]<=r[i])	over[i]=1,res++;
	}
	printf("%lld ",res);
	rep(i,1,n)	if(over[i])	++k,cars[k].l=l[i],cars[k].r=r[i];
	sort(cars+1,cars+1+k);
	rep(i,1,k)	l[i]=cars[i].l,r[i]=cars[i].r;
//	rep(i,1,k)	cout<<l[i]<<' '<<r[i]<<'\n';
	p[m+1]=inf;
	ll i=1,ans=0;
	rep(j,1,m){
		if(i>k)	break;
		if(p[j+1]>r[i]){
			ans++;
			while(i<=k&&l[i]<=p[j])	i++;
		}
	}
	printf("%lld\n",m-ans);
}
void mymain(){
	scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
	rep(i,1,n)	scanf("%lld%lld%lld",d+i,v+i,a+i);
	rep(i,1,m)	scanf("%lld",p+i);
	if(n<=20)
		solveBF();
	else
		solve();
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T-->0)	mymain();
	return 0;
}
