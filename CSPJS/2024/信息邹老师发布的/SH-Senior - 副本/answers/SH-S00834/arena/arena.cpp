#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
const ll N=1e5+5;
const ll L=20;
ll T,K,n,m,a[N],c[N],x[N][4],ap[N];
bool d[L+5][(1<<L)+5];
ll ch[L*(1<<L)+5][2],fa[L*(1<<L)+5],hd[L],tot;
void bld(){
	ll req=(1<<K),tmp=0; tot=(1<<K);
	for(ll i=1;tmp<K;i+=2){
//		cout<<"i="<<i<<" tmp="<<tmp<<" req="<<req<<endl;
		++tot,ch[tot][0]=i,ch[tot][1]=i+1;
		fa[i]=fa[i+1]=tot;
//		cout<<tot<<"--->"<<i<<' '<<i+1<<endl;
		if(i==req-1) tmp++,req+=(1<<(K-tmp)),hd[tmp]=i+2;
	} hd[0]=1;
}
namespace BF{
	struct rng{ll l,r;}vl[(1<<L)+5];
	ll wn[L*(1<<L)+5],ans,fans,tg[1<<L];
	void dfs(ll u,ll trm,ll r,ll g){
//		cout<<"dfs("<<u<<","<<r<<','<<g<<")"<<endl;
//		for(ll i=1;i<=15;i++) cout<<wn[i]<<" "; cout<<endl;
		if(r==trm+1){tg[wn[hd[trm]]]=1; return;}
		ll lc=ch[u][0],rc=ch[u][1];
//		cout<<"--->"<<lc<<" "<<rc<<" "<<wn[lc]<<' '<<wn[rc]<<endl;
		ll nxtr=r,nxtg=g+1,nxtu=u+1;
		if(g==(1<<(trm-r))) nxtu=hd[r+1],nxtr=r+1,nxtg=1;
		if(d[r][g]==0){
//			cout<<"left court"<<endl;
			if(vl[wn[lc]].r>=r) wn[u]=wn[lc],dfs(nxtu,trm,nxtr,nxtg);
			if(vl[wn[lc]].l<r) wn[u]=wn[rc],dfs(nxtu,trm,nxtr,nxtg);
		}
		else{
//			cout<<"right court"<<endl;
			if(vl[wn[rc]].r>=r) wn[u]=wn[rc],dfs(nxtu,trm,nxtr,nxtg);
			if(vl[wn[rc]].l<r) wn[u]=wn[lc],dfs(nxtu,trm,nxtr,nxtg);
		}
	}
	void solve(){
		fans=0;
//		for(ll i=0;i<=tmp;i++) cout<<hd[i]<<" "; cout<<endl;
//		for(ll i=1;i<=tot;i++)
//			cout<<i<<' '<<ch[i][0]<<' '<<ch[i][1]<<endl;
		for(ll i=1;i<=m;i++){
			ll bnd=c[i];
			for(ll j=1;j<=bnd;j++) vl[j]=(rng){a[j],a[j]};
			ll k=1,cnt=0; while(k<bnd) k*=2,cnt++;
			for(ll j=bnd+1;j<=k;j++) vl[j]=(rng){0,INF};
//			for(ll j=1;j<=k;j++) cout<<vl[j].l<<" "<<vl[j].r<<endl;
			for(ll i=1;i<=tot;i++) wn[i]=tg[i]=0;
			for(ll i=1;i<=k;i++) wn[i]=i;
			ans=0,dfs(hd[1],cnt,1,1);
			for(ll i=1;i<=k;i++) ans+=tg[i]*i;
			fans=(fans xor (i*ans));
//			for(ll i=1;i<=k;i++) cout<<tg[i]<<' '; cout<<endl;
//			cout<<bnd<<":"<<ans<<endl;
		}
		cout<<fans<<endl;
	}
}
namespace A{
	bool check(){
		for(ll i=1;i<=m;i++){
			ll x=c[i];
			while(x){
				if(x%2!=0&&x!=1) return 0;
				x/=2;
			}
		}
		return 1;
	}
	ll wn[L*(1<<L)+5],ans;
	void dfs(ll u,ll trm,ll r,ll g){
		if(r==trm+1) return;
		ll lc=ch[u][0],rc=ch[u][1];
		ll nxtr=r,nxtg=g+1,nxtu=u+1;
		if(g==(1<<(trm-r))) nxtu=hd[r+1],nxtr=r+1,nxtg=1;
		if(d[r][g]==0){
			if(a[wn[lc]]>=r) wn[u]=wn[lc],dfs(nxtu,trm,nxtr,nxtg);
			else wn[u]=wn[rc],dfs(nxtu,trm,nxtr,nxtg);
		}
		else{
			if(a[wn[rc]]>=r) wn[u]=wn[rc],dfs(nxtu,trm,nxtr,nxtg);
			else wn[u]=wn[lc],dfs(nxtu,trm,nxtr,nxtg);
		}
	}
	ll fans;
	void solve(){
		for(ll i=1;i<=(1<<K);i++) wn[i]=i;
		dfs((1<<K)+1,K,1,1); fans=0;
		for(ll i=1;i<=m;i++){
			ll x=c[i],cnt=0;
			while(x%2==0) cnt++,x/=2;
			fans=(fans xor (i*wn[hd[cnt]]));
		}
		cout<<fans<<endl;
	}
}
void ipt(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>ap[i];
	for(ll i=1;i<=m;i++) cin>>c[i];
	while((1<<K)<n) K++;
	for(ll i=1;i<=K;i++)
		for(ll j=1;j<=(1<<(K-i));j++){
			char c; cin>>c;
			d[i][j]=(ll)(c-'0');
		}
	cin>>T;
	for(ll i=1;i<=T;i++)
		for(ll j=0;j<4;j++) cin>>x[i][j];
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ipt(); bld();
	for(ll io=1;io<=T;io++){
		for(ll i=1;i<=n;i++) a[i]=(ap[i] xor x[io][i%4]);
//		cout<<io<<":"; for(ll i=1;i<=n;i++) cout<<a[i]<<' '; cout<<endl;
		if(A::check()) A::solve();
		else BF::solve();
	}
	return 0;
}
