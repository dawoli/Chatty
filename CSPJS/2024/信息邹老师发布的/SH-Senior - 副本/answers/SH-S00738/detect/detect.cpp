#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-8;
const ll N=1e5+9;
const ll MX=1e6+9;
const ll LG=29;
ll n,m,L,V,stt[N],ndd[N],f[MX],s[MX],l[MX],ST[MX][LG];
ld d,v,a,st,nd;
bool used[MX];
void buildST(ll x){
	ST[x][0]=f[x];
	for(ll i=1;(1LL<<i)<=x;i++)
		ST[x][i]=min(ST[x][i-1],ST[x-(1LL<<(i-1))][i-1]);
}
ll mn(ll l,ll r){
	ll lg=log(r-l+1)/log(2);
	return min(ST[l+(1LL<<lg)-1][lg],ST[r][lg]);
}
void solve(){
	cin>>n>>m>>L>>V;
	for(ll i=1;i<=n;i++){
		stt[i]=-1,ndd[i]=-1;
		cin>>d>>v>>a;
		if(fabsl(a)<eps){
			if(ll(v)<=V) continue;
			stt[i]=d,ndd[i]=L;
		}else if(a<-eps){
			if(ll(v)<=V) continue;
			st=d,nd=d+(V*V-v*v)/(a*2);
			stt[i]=d,ndd[i]=floorl(min(nd-eps,ld(L)));
		}else{
			if((ll)sqrtl(v*v+a*(L-d)*2)<=V) continue;
			st=d+(V*V-v*v)/(a*2),nd=L;
			stt[i]=ceill(max(st+eps,d)),ndd[i]=L;
		}
	}
	for(ll i=0;i<=L;i++) used[i]=0,l[i]=0;
	for(ll i=1,p;i<=m;i++) cin>>p,used[p]=1;
	for(ll i=0;i<=L;i++) s[i]=(i?s[i-1]:0)+used[i];
	ll ans1=0;
	for(ll i=1;i<=n;i++){
		if(stt[i]==-1) continue;
		if(s[ndd[i]]-(stt[i]?s[stt[i]-1]:0)==0) continue;
		ans1++;
		l[ndd[i]]=max(l[ndd[i]],stt[i]);
	}
	cout<<ans1<<' ';
	ll sstt=-1;
	for(ll i=0;i<=L;i++){
		if(used[i]){
			if(i==0) f[i]=1;
			else if(sstt==-1) f[i]=1;
			else f[i]=mn(sstt,i-1)+1;
		}else f[i]=m*4;
		buildST(i);
		sstt=max(sstt,l[i]);
	}
	cout<<m-mn(sstt,L)<<endl;
	//for(ll i=0;i<=L;i++)
	//	if(f[i]>=m*2) cout<<"inf ";
	//	else cout<<f[i]<<' ';
	//cout<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}
