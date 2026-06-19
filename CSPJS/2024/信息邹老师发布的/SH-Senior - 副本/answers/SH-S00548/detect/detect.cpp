#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100005;
ll T,n,m,L,V,d[N],v[N],a[N],p[N];
bool ifch[29];
vector<ll> pid[29];
bool ifg[29];
ll anss2=0;
void dfs(ll np,ll cnt){
	if(np>m){
		if(cnt<=anss2)return;
		bool ok=1;
		for(ll i=1;i<=n;++i){
			if(ifch[i]){
				bool b=0;
				for(ll j=0;j<pid[i].size();++j){
					if(ifg[pid[i][j]]){
						b=1;
						break;
					}
				}
				if(!b){
					ok=0;
					break;
				}
			}
		}
		if(ok){
			anss2=cnt;
		}
		return;
	}
	ifg[np]=1;
	dfs(np+1,cnt);
	ifg[np]=0;
	dfs(np+1,cnt+1);
}
void solve1(){
	ll ans=0;
	anss2=0;
	ll vshun=0;
	for(ll i=1;i<=n;++i){
		ifch[i]=0;
		pid[i].clear();
		for(ll j=1;j<=m;++j){
			if(p[j]<d[i])continue;
			vshun=v[i]*v[i]+2*a[i]*(p[j]-d[i]);
			if(vshun>V*V){
				ifch[i]=1;
				pid[i].push_back(j);
			}
		}
		if(ifch[i])ans++;
	}
	dfs(1,0);
	cout<<ans<<" "<<anss2<<endl;
}
void solveA(){
	ll ans=0;
	for(ll i=1;i<=n;++i){
		if(d[i]<=p[m]&&v[i]>V)ans++;
	}
	ll ans2=m;
	if(ans>0)ans2--;
	cout<<ans<<" "<<ans2<<endl;
}
void solveB(){
	ll ans=0;
	for(ll i=1;i<=n;++i){
		if(d[i]<=p[m]&&v[i]*v[i]+2*a[i]*(p[m]-d[i])>V*V)ans++;
	}
	ll ans2=m;
	if(ans>0)ans2--;
	cout<<ans<<" "<<ans2<<endl;
}
void solveC(){
	ll ans=0;
}
bool ifA=1,ifB=1,ifC=1;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(ll tt=1;tt<=T;++tt){
		cin>>n>>m>>L>>V;
		for(ll i=1;i<=n;++i){
			cin>>d[i];
			cin>>v[i];
			cin>>a[i];
			if(a[i]>0){
				ifA=0,ifC=0;
			}
			else if(a[i]<0){
				ifA=0,ifB=0;
			}
			else{
				ifB=0,ifC=0;
			}
		}
		for(ll i=1;i<=m;++i){
			cin>>p[i];
		}
		if(n<=20&&m<=20){
			solve1();
		}
		else if(ifA){
			solveA();
		}
		else if(ifB){
			solveB();
		}
		else if(ifC){
			solveC();
		}
	}
	return 0;
}
