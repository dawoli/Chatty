#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100005;
ll T,n,k,q,l[N],r[N],c[N];
vector<ll> s[N];
ll x;
bool r1,r5,r10;
bool vst[2*N];
void solve1(){
	for(ll i=0;i<=200002;++i){
		vst[i]=0;
	}
	for(ll i=1;i<=n;++i){
		ll j=0;
		while(j<l[i]){
			while(j<l[i]-1&&s[i][j]!=1)j++;
			if(j>=l[i]-1)break;
			ll j2=j+1;
			while(j2<l[i]&&j2-j+1<=k){
				vst[s[i][j2]]=1;
				j2++;
			}
			j++;
		}
	}
	for(ll j=1;j<=q;++j){
		cout<<vst[c[j]]<<endl;
	}
}
ll top=0;
map<ll,ll> mp;
vector<ll> to[19][39];
void addnum23(ll num){
	top++;
	mp[num]=top;
}
void adde23(ll i,ll u,ll v){
	to[i][u].push_back(v);
}
bool ifcan=0;
void dfs(ll nr,ll np,ll nnum,ll gnum){
	if(ifcan)return;
	if(nr<0)return;
	if(nr==0){
		if(nnum==gnum)ifcan=1;
		return;
	}
	for(ll i=1;i<=n;++i)if(i!=np){
		for(ll j=0;j<to[i][nnum].size();++j){
			dfs(nr-1,i,to[i][nnum][j],gnum);
		}
	}
}
void solve23(){
	top=0;
	for(ll i=0;i<=N*2;++i)mp[i]=0;
	for(ll i=0;i<=12;++i){
		for(ll j=0;j<=29;++j){
			to[i][j].clear();
		}
	}
	for(ll i=1;i<=n;++i){
		for(ll j=0;j<l[i];++j){
			ll j2=j+1;
			while(j2<l[i]&&j2-j+1<=k){
				if(mp[s[i][j]]==0)addnum23(s[i][j]);
				if(mp[s[i][j2]]==0)addnum23(s[i][j2]);
				adde23(i,mp[s[i][j]],mp[s[i][j2]]);
				j2++;
			}
		}
	}
	for(ll j=1;j<=q;++j){
		ifcan=0;
		dfs(r[j],0,1,c[j]);
		cout<<ifcan<<endl;
	}
	
}
void solveguess(){
	for(ll j=1;j<=q;++j){
		cout<<1<<endl;
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(ll tt=1;tt<=T;++tt){
		r1=1;
		r5=1;
		r10=1;
		cin>>n>>k>>q;
		for(ll i=1;i<=n;++i){
			s[i].clear();
			cin>>l[i];
			for(ll j=1;j<=l[i];++j){
				cin>>x;
				s[i].push_back(x);
			}
		}
		for(ll j=1;j<=q;++j){
			cin>>r[j]>>c[j];
			if(r[j]>1){
				r1=0;
			}
			if(r[j]>5){
				r5=0;
			}
			if(r[j]>10){
				r10=0;
			}
		}
		if(r1){
			solve1();
		}
		else if(r5){
			solve23();
		}
		else{
			solveguess();
		}
	}
	return 0;
}
