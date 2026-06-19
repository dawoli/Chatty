#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e5+9;

ll T, n, m, L, V;
ll a[N], v[N], d[N], p[N];

bool a_0(){
	for(ll i=1; i<=n; i++)
		if(a[i]<0) return 0;
	return 1;
}

void solve0(){
	ll mxp=-1;
	for(ll i=1; i<=m; i++) mxp = max(mxp, p[i]);
	for(ll i=1; i<=n; i++){
		if(v[i]>V) continue;
		if(a[i]==0){
			d[i] = 1e13;
			continue;
		} 
		ll dst=(V*V-v[i]*v[i])/(2*a[i])+1;
		d[i]+=dst;
	}
	ll ans1=0;
	for(ll i=1; i<=n; i++) if(d[i]<=mxp) ans1++;
	if(ans1>0) cout<<ans1<<' '<<m-1<<endl;
	else cout<<0<<' '<<m<<endl;
}
ll ok[N];
ll cr[109][109], crs[N];
bool ok_i(ll id, ll w){
	for(ll i=0; i<crs[id]; i++){
		ll ct = cr[id][i];
		if(w&(1<<ct-1)) return 1; 
	}
	return 0;
}
ll cnt(ll w){
	ll res=0;
	while(w){
		if(w%2==1) res++;
		w/=2;
	}
	return res;
}
void solveBF(){
	for(ll i=1; i<=20; i++) ok[i] = crs[i] = 0;
	for(ll i=0; i<=20; i++)
	for(ll j=0; j<=20; j++) cr[i][j] = 0;
	ll ans1=0;
	for(ll i=1; i<=n; i++)
		for(ll j=1; j<=m; j++){
			if(p[j]<d[i]) continue;
			long double vt = sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
			if(vt>V*1.0){
				if(ok[i]==0) ans1++, ok[i]=1;
				cr[i][crs[i]++] = j;
			} 
		}
	cout<<ans1<<' ';
	ll ans2=1e18;
	for(ll w=0; w<=(1<<m)-1; w++){
		ll i=1; 
		for(; i<=n; i++)
			if(ok[i]>0&&!ok_i(i, w)) break;
		if(i<=n) continue;
		ans2 = min(ans2, cnt(w));
	}
	cout<<m-ans2<<endl;
}
void solve(){
	cout<<"wo bu hui hhh";
}

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	cin>>T;
	for(ll t=1; t<=T; t++){
		cin>>n>>m>>L>>V;
		for(ll i=1; i<=n; i++) cin>>d[i]>>v[i]>>a[i];
		for(ll i=1; i<=m; i++) cin>>p[i];
		if(a_0()){
			solve0();
			continue;
		}
		else if(n<=20) solveBF();
		else solve();
	}
	
	return 0;
}
