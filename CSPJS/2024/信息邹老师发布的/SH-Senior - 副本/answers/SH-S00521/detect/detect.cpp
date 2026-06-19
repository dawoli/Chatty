#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll c=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		c=(c<<1ll)+(c<<3ll)+(ch^48ll);
		ch=getchar();
	}
	return c*f;
}
ll T;
ll n,m,L,V;
const ll N=100009;
struct car{
	ll d,v,a,mxd;
} x[N];
struct section{
	ll l,r;
	bool operator<(const section&t)const{
		return r<t.r;
	}
} s[N];
ll tot;
ll p[N];
bool tag[N];
bool check(ll i,ll pos){
	ll now=x[i].v*x[i].v+2*x[i].a*(pos-x[i].d);
	return now<=V*V;
}
ll solve(){
	sort(s+1,s+tot+1);
	ll res=0;
	ll mxr=-1;
	for(ll i=1;i<=tot;i++){
		if(s[i].l<=mxr&&mxr<=s[i].r) continue;
		res++;
		mxr=s[i].r;
	}
	return res;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while(T--){
		tot=0;
		fill(tag+1,tag+n+1,0);
		
		n=read(),m=read(),L=read(),V=read();
		for(ll i=1;i<=n;i++){
			x[i].d=read(),x[i].v=read(),x[i].a=read();
			if(x[i].a>=0){
				x[i].mxd=L;
			}
			else{
				x[i].mxd=x[i].d+x[i].v*x[i].v/(-2*x[i].a);
			}
		}
		for(ll i=1;i<=m;i++){
			p[i]=read();
		}
		ll res=0;
		for(ll i=1;i<=n;i++){
			if(x[i].d>p[m]) continue;
			if(x[i].a>=0){
				if(!check(i,p[m])){
					res++;
					tag[i]=1;
				}
			}
			else{
				ll j=lower_bound(p+1,p+m+1,x[i].d)-p;
				if(x[i].mxd<p[j]) continue;
				if(!check(i,p[j])){
					res++;
					tag[i]=1;
				}
			}
		}
		printf("%lld ",res);
		for(ll i=1;i<=n;i++){
			if(!tag[i]) continue;
//			cout<<i<<" ";
			if(x[i].a>0){
				ll pos=(V*V-x[i].v*x[i].v)/(2*x[i].a)+1+x[i].d;
//				cout<<"!"<<pos<<endl;
				ll j=lower_bound(p+1,p+m+1,pos)-p;
				s[++tot]={j,m};
			}
			else if(x[i].a==0){
				ll j=lower_bound(p+1,p+m+1,x[i].d)-p;
				s[++tot]={j,m};
			}
			else{
				ll pos=x[i].d+(x[i].v*x[i].v-V*V-2*x[i].a-1)/(-2*x[i].a)-1;
//				cout<<"!"<<pos<<endl;
				ll l=lower_bound(p+1,p+m+1,x[i].d)-p;
				ll r=upper_bound(p+1,p+m+1,pos)-p-1;
				s[++tot]={l,r};
			}
		}
//		cout<<endl;
//		for(ll i=1;i<=tot;i++){
//			printf("%lld %lld\n",s[i].l,s[i].r);
//		}
		printf("%lld\n",m-solve());
	}
	return 0;
}

