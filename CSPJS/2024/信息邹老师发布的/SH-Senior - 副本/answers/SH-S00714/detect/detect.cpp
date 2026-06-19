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
ll n,m,rd,lmt,d[N],spd[N],add[N],det[N];
void input(){
	scanf("%lld%lld%lld%lld",&n,&m,&rd,&lmt);
	rep(i,1,n)scanf("%lld%lld%lld",&d[i],&spd[i],&add[i]);
	rep(i,1,m)scanf("%lld",&det[i]);
}
bool testA(){rep(i,1,n)if(add[i]!=0)return 0;return 1;}
bool testB(){return *min_element(add+1,add+1+n)>0;} 
void solveA(){
	ll cnt=0;
	rep(i,1,n)if(spd[i]>lmt&&d[i]<=det[m])cnt++;
	printf("%lld ",cnt);
	if(cnt)printf("%lld\n",m-1);
	else printf("%lld\n",m);
}
void solveB(){
	ll cnt=0;
	rep(i,1,n){
		if(d[i]>det[m])continue;
		ll dst=det[m]-d[i];
		if(spd[i]*spd[i]+2*add[i]*dst>lmt*lmt)cnt++;
	}
	printf("%lld ",cnt);
	if(cnt)printf("%lld\n",m-1);
	else printf("%lld\n",m);
}
ll cnt(ll ptn,ll& btc){
	ll c=0;rep(j,0,m-1)if(ptn>>j&1)btc++;
	rep(i,1,n){
		rep(j,0,m-1)if(ptn>>j&1){
			if(d[i]>det[j+1])continue;
			ll dst=det[j+1]-d[i];
			if(spd[i]*spd[i]+2*add[i]*dst>lmt*lmt){c++;break;}
		}
	}
	return c;
}
void solveBF(){
	ll nPtn=(1<<m)-1,zifj; ll cr=cnt(nPtn,zifj);
	ll ans=0;
	rep(i,0,nPtn-1){
		ll btc=0; if(cnt(i,btc)==cr)ans=max(ans,m-btc);
	}
	printf("%lld %lld\n",cr,ans);
}
cll ML=1e6+9;
ll sum[ML];
struct Interval{ll l,r;bool ok;}it[N],x[N];
bool cmp(const Interval&x,const Interval&y){return x.l<y.l||x.l==y.l&&x.r<y.r;}
void solve(){
	rep(i,0,rd)sum[i]=0;
	rep(i,1,m)sum[det[i]]++;
	rep(i,1,rd)sum[i]+=sum[i-1];
	rep(i,1,n){
		if(add[i]==0){
			if(spd[i]>lmt)it[i].l=d[i],it[i].r=rd;
			else it[i].l=it[i].r=-1;
		}
		else{
			ll dst=lmt*lmt-spd[i]*spd[i];
			long double ospd=dst/2.0/add[i];
			if(add[i]<0){
				if(dst>=0)it[i].l=it[i].r=-1;
				else it[i].l=d[i],it[i].r=d[i]+ospd-0.000001;
				if(it[i].r>rd)it[i].r=rd;
			}else{
				it[i].r=rd;
				if(dst<=0)it[i].l=d[i];
				else it[i].l=d[i]+ospd+1;
			}
		}
	}
	ll cnt=0;
	rep(i,1,n){
		if(it[i].r<it[i].l)it[i].l=it[i].r=-1;
		if(it[i].r!=-1&&sum[it[i].r]-sum[it[i].l-1]>0){
			ll L=it[i].l,R=it[i].r;
			it[i].l=upper_bound(det+1,det+1+m,it[i].l-1)-det;
			it[i].r=upper_bound(det+1,det+1+m,it[i].r)-det-1;
			it[i].ok=1;
			++cnt;
		}else it[i].ok=0;
	}
	printf("%lld ",cnt);sort(it+1,it+1+n,cmp); cnt=0;
	rep(i,1,n)if(it[i].ok){
		while(cnt&&it[i].r<=x[cnt].r)cnt--;
		x[++cnt]=it[i];
	}
	ll now=0,ans=0;
	rep(i,1,cnt)if(now<x[i].l){now=x[i].r,ans++;}
	printf("%lld\n",m-ans);
}
void work(){
	input();
	if(m<=20&&n<=20)solveBF();
	else if(testA())solveA();
	else if(testB())solveB();
	else solve();
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ll t;scanf("%lld",&t);while(t--)work();
	return 0;
}
