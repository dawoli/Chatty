#include<bits/stdc++.h>
#define ERR 1e-13
#define N 100005
typedef long long ll;
typedef long double ld;
using namespace std;
struct CAR{ ll d,v,a; }c[N];
struct SCR{ ll upr,dwn; };
ll T,n,m,L,V,p[N];
ll lceil(ll x,ll y){ return (x+y-1)/y; }
ll lfloor(ll x,ll y){ return x/y; }
ll spd(ll i,ll dis){ return c[i].v*c[i].v+2*c[i].a*dis; }
SCR dis(ll i,ll spd){ return {(spd*spd-c[i].v*c[i].v),2*c[i].a}; }
void nm10(){
	ll kans=0;
	for(ll i=1,t;i<=n;i++){
		bool OK=false;
		if(c[i].d>p[m]||c[i].a<0&&c[i].v<=V) continue;
		for(ll j=1;j<=m;j++){
			if(c[i].d>p[j]) continue;
			ll t=spd(i,p[j]-c[i].d);
			if(t>V*V) OK=true;
		}
		if(OK) kans++;
	}
	ll b[11],tmp=0,tans=0,ans=0;
	fill(b,b+11,0);
	while(1){
		bool End=true;
		for(ll i=1;i<=m;i++) if(!b[i]) End=false;
		if(End) break;
		tmp=tans=0;
		for(ll i=1,t;i<=n;i++){
			bool OK=false;
			for(ll j=1;j<=m;j++) if(b[j]){
				if(c[i].d>p[j]) continue;
				ll t=spd(i,p[j]-c[i].d);
				if(t>V*V) OK=true;
			}
			if(OK) tans++;
		}
		for(ll i=1;i<=m;i++) tmp+=(!b[i]);
		if(tans==kans) ans=max(ans,tmp);
		ll ad=m;
		b[ad]++;
		while(b[ad]==2) b[ad--]=0,b[ad]++;
	}
	cout<<kans<<" "<<ans<<endl;
}
void nm20(){
	ll kans=0;
	for(ll i=1,t;i<=n;i++){
		bool OK=false;
		if(c[i].d>p[m]||c[i].a<0&&c[i].v<=V) continue;
		for(ll j=1;j<=m;j++){
			if(c[i].d>p[j]) continue;
			ll t=spd(i,p[j]-c[i].d);
			if(t>V*V) OK=true;
		}
		if(OK) kans++;
	}
	ll b[21],tmp=0,tans=0,ans=0;
	fill(b,b+21,1);
	for(ll i=m;i>=1;i--){
		b[i]=0;
		tmp=tans=0;
		for(ll i=1,t;i<=n;i++){
			bool OK=false;
			for(ll j=1;j<=m;j++) if(b[j]){
				if(c[i].d>p[j]) continue;
				ll t=spd(i,p[j]-c[i].d);
				if(t>V*V) OK=true;
			}
			if(OK) tans++;
		}
		for(ll i=1;i<=m;i++) tmp+=(!b[i]);
		if(tans==kans) ans++;
		else b[i]=1;
	}
	cout<<kans<<" "<<ans<<endl;
}
bool isA(){
	for(ll i=1;i<=n;i++) if(c[i].a!=0) return false;
	return true;
}
void GetA(){
	ll ans1=0;
	for(ll i=1;i<=n;i++) if(c[i].v>V&&p[m]>=c[i].d) ans1++;
	if(ans1>0) cout<<ans1<<" "<<m-1<<endl;
	else cout<<"0 "<<m<<endl;
}
bool isB(){
	for(ll i=1;i<=n;i++) if(c[i].a<=0) return false;
	return true;
}
void GetB(){
	ll ans1=0;
	for(ll i=1;i<=n;i++){
		if(c[i].d>p[m]) continue;
//		ll t=spd(i,p[m]-c[i].d);
		SCR t=dis(i,V);
//		if(t>V*V) ans1++;
		if(c[i].d*t.dwn+t.upr<p[m]*t.dwn) ans1++;
	}
	if(ans1>0) cout<<ans1<<" "<<m-1<<endl;
	else cout<<"0 "<<m<<endl;
}
bool isC(){
void nm3000(){
	ll kans=0;
	for(ll i=1,t;i<=n;i++){
		bool OK=false;
		if(c[i].d>p[m]||c[i].a<0&&c[i].v<=V) continue;
		for(ll j=1;j<=m;j++){
			if(c[i].d>p[j]) continue;
			ll t=spd(i,p[j]-c[i].d);
			if(t>V*V) OK=true;
		}
		if(OK) kans++;
	}
	ll b[3001],tmp=0,tans=0,ans=0,m_last=m;
	fill(b,b+3001,1);
	for(ll i=m;i>=1;i--){
		b[i]=0;
		tmp=tans=0;
		for(ll i=1,t;i<=n;i++){
			bool OK=false;
			if(c[i].a==0){
				ll kid=m_last;
				while(!b[kid]) kid--;
				if(c[i].v>V&&p[kid]>=c[i].d) tans++;
			}
			else if(c[i].a>0){
				ll kid=m_last;
				while(!b[kid]) kid--;
				ll t=spd(i,p[kid]-c[i].d);
				if(t>V*V) tans++;
			}
			else{
				ll kid=lower_bound(p+1,p+1+m,c[i].d)-p;
				while(!b[kid]) kid++;
				if(kid>m) continue;
				ll t=spd(i,p[kid]-c[i].d);
				if(t>V*V) tans++;
			}
		}
		for(ll i=1;i<=m;i++) tmp+=(!b[i]);
		if(tans==kans) ans++;
		else b[i]=1;
		if(tans==kans&&i==m_last) m_last--;
	}
	cout<<kans<<" "<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(ll i=1;i<=n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
		for(ll i=1;i<=m;i++) cin>>p[i];
		if(isA()) GetA();
		else if(isB()) GetB();
		else if(n<=10&&m<=10) nm10();
		else if(n<=20&&m<=20) nm20();
		else if(n<=3000&&m<=3000) nm3000();
//		else cout<<"qwq 做不出来\n";
	}
	return 0;
}
