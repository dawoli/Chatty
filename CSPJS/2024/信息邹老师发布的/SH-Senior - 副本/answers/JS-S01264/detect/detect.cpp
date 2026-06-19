#include<bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define down(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll INF=1e15;
const ll ERR=0.000000000000001;
void file(){
	 freopen("detect.in","r",stdin);
	 freopen("detect.out","w",stdout);
}
//多测不清空，爆零两行泪
//输入速度即平方 
const ll N=200009;
ll T; 
ll n,m,L,V,contribution[N],d[N],v[N],a[N],p[N];
struct Node{
	ll l,r;
}q[N];
ll nCar=0;
ll bit[N],vst[N];//9 7
void init(){
	rep(i,1,max(n,m)+5)contribution[i]=d[i]=v[i]=a[i]=p[i]=0;
	rep(i,1,nCar)q[i]=(Node){0,0};
	nCar=0;
	rep(i,1,max(n,max(m,nCar))+5)bit[i]=0,vst[i]=0;
	n=m=L=V=0;
}
void input(){
	scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
	V=V*V; 
	rep(i,1,n)scanf("%lld%lld%lld",&d[i],&v[i],&a[i]),v[i]=v[i]*v[i];
	rep(i,1,m)scanf("%lld",&p[i]);
}
bool arrested_or_not(ll idcar,ll idmonitor){
	if(p[idmonitor]<d[idcar])return 0;
	if(a[idcar]<0){
		ld mxdx; mxdx=(-v[idcar])*1./2./a[idcar]+d[idcar];
		if(mxdx-p[idmonitor]<ERR)return 0;
	} 
	ll dx=p[idmonitor]-d[idcar];
	ll vt=2*a[idcar]*dx+v[idcar];
	return vt>V;
}
bool cmp(const Node&a,const Node&b){
	return a.l<b.l||(a.l==b.l&&a.r>b.r);
}
ll LSB(ll i){return i&(-i);}
void add(ll x,ll delta){
	for(int i=x;i<=m;i+=LSB(i))bit[i]+=delta;
}
ll psq(ll x){
	ll sum=0;
	for(int i=x;i>=1;i-=LSB(i))sum+=bit[i];
	return sum;
}
void solve(){
	sort(p+1,p+1+m);
	ll cnt=0;
	rep(i,1,n){
		if(a[i]==0&&v[i]<=V)continue;
		if(a[i]<0&&v[i]<=V)continue;
		if(a[i]>0){
			ll dx=L-d[i];
			ll vt=2*a[i]*dx+v[i];
			if(vt<=V)continue;
		}
		if(a[i]==0){
			ll st=lower_bound(p+1,p+1+m,d[i])-p;
			ll ed=m;
			if(st<=ed)cnt++,q[++nCar]=(Node){st,ed};
			continue;
		}
		ld dx=(V-v[i])*1./2/a[i]+d[i];
		if(a[i]>0){
			ll st,ed;
			if(v[i]>V){
				st=lower_bound(p+1,p+1+m,d[i])-p;
				ed=m;
			}else{
				st=upper_bound(p+1,p+1+m,dx)-p;
				ed=m;
			}
			if(st<=ed)cnt++,q[++nCar]=(Node){st,ed};
		}else{
			ll st,ed;
			ed=lower_bound(p+1,p+1+m,dx)-p-1;
			st=lower_bound(p+1,p+1+m,d[i])-p;
			if(st<=ed)cnt++,q[++nCar]=(Node){st,ed};
		}
	}
	printf("%lld ",cnt); 
	sort(q+1,q+1+nCar,cmp);
	rep(i,1,nCar)vst[i]=1;
	down(i,nCar,1){
		add(q[i].r,1);
		if(psq(q[i].r)>1)vst[i]=0;
	}
//	rep(i,1,nCar)cout<<q[i].l<<" "<<q[i].r<<endl<<vst[i]<<endl;
	ll cur=0,ans=0;
	rep(i,1,nCar){
		if(!vst[i])continue;
		if(q[i].l>cur)cur=q[i].r,ans++;
	}
//	cout<<ans<<endl;
	printf("%lld\n",m-ans);
}
int main(){
	file();
	scanf("%lld",&T);
	rep(i,1,T){
		init();
		input();
//		if(n<=3000)
//			solveBF();
//		else
			solve();
	}
	return 0;
}

