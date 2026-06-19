#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll T,n,m,L,V,p[N];
struct CAR{
	ll d,v,a;
}c[N];
namespace BF{
	ll isspd[N],ans1,ans2;
	ll chs[N],tmpisspd[N];
	void dfs(ll x,ll cnt){
		if(x==m+1){
			for(ll i=1;i<=n;i++) tmpisspd[i]=0;
			for(ll i=1;i<=n;i++){
				ll d=c[i].d,a=c[i].a,v=c[i].v;
				for(ll j=1;j<=m;j++)if(chs[j]){
					if(d>p[j]) continue;
					ll sqvt=2*a*(p[j]-d)+v*v;
					if(sqvt>V*V) tmpisspd[i]=1;
				}
			}
//			for(ll i=1;i<=n;i++) cout<<chs[i]<<" "; cout<<endl;
//			for(ll i=1;i<=n;i++) cout<<tmpisspd[i]<<" "; cout<<endl;
//			cout<<endl;
			for(ll i=1;i<=n;i++)
				if(tmpisspd[i]!=isspd[i]) return;
			ans2=min(ans2,cnt); return;
		}
		dfs(x+1,cnt);
		chs[x]=1; dfs(x+1,cnt+1); chs[x]=0;
	}
	void solve(){
		for(ll i=1;i<=n;i++) isspd[i]=0;
		ans1=0,ans2=m+1;
		for(ll i=1;i<=n;i++){
			ll d=c[i].d,a=c[i].a,v=c[i].v;
			for(ll j=1;j<=m;j++){
				if(d>p[j]) continue;
				ll sqvt=2*a*(p[j]-d)+v*v;
				if(sqvt>V*V) isspd[i]=1;
			} ans1+=isspd[i];
		}
//		for(ll i=1;i<=n;i++) cout<<isspd[i]<<' '; cout<<endl;
		cout<<ans1<<' '; dfs(1,0);
		cout<<m-ans2<<endl;
	}
}
namespace A{
	bool check(){
		for(ll i=1;i<=n;i++)
			if(c[i].a) return 0;
		return 1;
	}
	ll tg;
	void solve(){
		tg=0;
		for(ll i=1;i<=n;i++)
			if(c[i].v>V&&c[i].d<=p[m]) tg++;
		cout<<tg<<" "<<m-(tg>0)<<endl;
	}
}
namespace B{
	bool check(){
		for(ll i=1;i<=n;i++)
			if(c[i].a<=0) return 0;
		return 1;
	}
	ll tg;
	void solve(){
		tg=0;
		for(ll i=1;i<=n;i++){
			ll d=c[i].d,a=c[i].a,v=c[i].v;
			if(d>p[m]) continue;
			ll sqvt=2*a*(p[m]-d)+v*v;
			if(sqvt>V*V) tg++;
		}
		cout<<tg<<" "<<m-(tg>0)<<endl;
	}
}
namespace STD{
	struct rng{ll l,r,tg;}spd[N];
	vector<ll>add[N*2],del[N*2];
	ll tot,x[N*2],totln,cnt,cntspd;
	struct line{
		ll pos,id,tg;
		bool operator<(const line &a) const{
			return pos<a.pos||pos==a.pos&&tg<a.tg;
		}
	}ln[2*N];
	set<ll>tmp;
	void init(){
		tot=totln=cnt=cntspd=0;
		for(ll i=1;i<=n;i++) spd[i]=(rng){0,0,0};
		tmp.clear();
	}
	void prewrk(){
		for(ll i=1;i<=n;i++){
			ll d=c[i].d,a=c[i].a,v=c[i].v;
			ll pos=lower_bound(p+1,p+m+1,d)-p;
			if(a==0&&v>V&&d<=p[m]) spd[i]=(rng){pos,m,1},cntspd++;
			else if(a>0){
				double tmp=(V*V-v*v)/(2.00*a);
				ll tmpp=ceil(tmp)+d;
				if(tmp==(V*V-v*v)/(2*a)) tmpp++;
				ll posp=lower_bound(p+1,p+m+1,tmpp)-p;
				pos=max(pos,posp);
				if(pos<=m) spd[i]=(rng){pos,m,1},cntspd++;
			}
			else if(a<0){
				if(V>=v) continue;
				double tmp=(V*V-v*v)/(2.00*a);
				ll tmpp=floor(tmp)+d;
				if(tmp==(V*V-v*v)/(2*a)) tmpp--;
				ll posp=upper_bound(p+1,p+m+1,tmpp)-p-1;
				if(posp>=pos) spd[i]=(rng){pos,posp,1},cntspd++;
			}
		}
	}
	void lsh(){
		for(ll i=1;i<=n;i++)if(spd[i].tg)
			x[2*i-1]=spd[i].l,x[2*i]=spd[i].r+1;
		sort(x+1,x+2*n+1);
		tot=unique(x+1,x+2*n+1)-(x+1);
	}
	ll gt(ll u){return lower_bound(x+1,x+tot+1,u)-x;}
	void solve(){
		init();
		prewrk(); lsh();
//		for(ll i=1;i<=n;i++)
//			cout<<"("<<spd[i].l<<","<<spd[i].r<<","<<spd[i].tg<<")"<<endl;
		for(ll i=1;i<=n;i++)if(spd[i].tg){
			ll l=gt(spd[i].l),r=gt(spd[i].r+1);
			ln[++totln]=(line){l,i,1};
			ln[++totln]=(line){r,i,-1};
		}
		sort(ln+1,ln+totln+1);
//		for(ll i=1;i<=totln;i++)
//			cout<<"--->"<<ln[i].pos<<" "<<ln[i].id<<" "<<ln[i].tg<<endl;
		for(ll i=1;i<=totln;i++){
			ll tg=ln[i].tg,id=ln[i].id;
			if(tg==1) tmp.insert(id);
			else if(tmp.find(id)!=tmp.end()) tmp.clear(),cnt++;
		}
		cout<<cntspd<<" "<<m-cnt<<endl;
	}
}
void ipt(){
	cin>>n>>m>>L>>V;
	for(ll i=1;i<=n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
	for(ll i=1;i<=m;i++) cin>>p[i];
}
void gendata(){
	n=rand()%20+1,m=rand()%20+1;
	L=rand()%10000+1,V=rand()%10000+1;
	cout<<n<<' '<<m<<' '<<L<<' '<<V<<endl;
	for(ll i=1;i<=n;i++){
		ll d=rand()%(L+1);
		ll v=rand()%100000;
		ll a=rand()%100000-100000;
		cout<<d<<' '<<v<<' '<<a<<endl;
		c[i]=(CAR){d,v,a};
	}
	for(ll i=1;i<=m;i++) p[i]=rand()%(L+1);
	sort(p+1,p+m+1);
	for(ll i=1;i<=m;i++) cout<<p[i]<<' '; cout<<endl;
	cout<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
//	srand(time(0));
	cin>>T;
	for(ll io=1;io<=T;io++){
		ipt();
//		gendata();
		if(A::check()) A::solve();
		else if(B::check()) B::solve();
		else if(n<=10&&m<=10) BF::solve();
		else STD::solve();
//		cout<<endl;
	}
	return 0;
}
