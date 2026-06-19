#include<bits/stdc++.h>
#define N 100009
#define M 140001
using namespace std;
typedef long long ll;
ll n,m,aj[N],c[N],a[M],dee[M],K=0,T;
vector<ll> r[N];
set<ll> b[M],ce[M];
set<ll>::iterator it,it2;
void input(){
	ll x[4];
	for(ll i=0;i<4;i++) cin>>x[i];
	for(ll i=1;i<=n;i++) a[i]=(aj[i]^x[i%4]);
//	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
//	cout<<endl;
}
void solve(){
	ll ans=0;
	for(ll iQ=1;iQ<=m;iQ++){
		ll k=0,afres=1;
		while(afres<c[iQ]){
			afres*=2;
			k++;
		}
//		cout<<k<<" "<<afres<<endl;
		for(ll i=1;i<=afres;i++){
			b[i].clear(); ce[i].clear();
			b[i].insert(i);
			dee[i]=a[i];
			if(i>c[iQ]) dee[i]=-1;
		}
		for(ll iK=1;iK<=k;iK++){
			for(ll i=1;i<=afres/2;i++){
				ll x=i*2-1,y=i*2,d=r[iK][i-1];
				ll lz=(d==0?x:y),c_hl_e=(d==0?y:x);
				bool flag=1;
				for(it=b[lz].begin();it!=b[lz].end();it++){
					ll val=*it;
					if(dee[val]==-1){
						ce[i].insert(val);
						if(flag){
							flag=0;
							for(it2=b[c_hl_e].begin();it2!=b[c_hl_e].end();it2++) ce[i].insert(*it2);
						}
					}
					if(dee[val]>=iK) ce[i].insert(val);
					else if(flag){
						flag=0;
						for(it2=b[c_hl_e].begin();it2!=b[c_hl_e].end();it2++) ce[i].insert(*it2);
					}
				}
				b[lz].clear(); b[c_hl_e].clear();
				for(it=ce[i].begin();it!=ce[i].end();it++) b[i].insert(*it);//,printf("%lld ",*it);
				ce[i].clear();
//				printf("\n");
			}
			afres/=2;
		}
		ll sum=0;
		for(it=b[1].begin();it!=b[1].end();it++) sum+=*it;
		ans^=(iQ*sum);
//		cout<<sum<<"abababa"<<endl;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>aj[i];
	for(ll i=1;i<=m;i++) cin>>c[i];
	ll afres=1;
	while(afres<n){
		afres*=2;
		K++;
	}
//	cout<<K<<endl;
	for(ll i=1;i<=K;i++){
		string s;
		cin>>s;
//		cout<<s<<endl;
		for(ll j=0;j<s.size();j++) r[i].push_back(s[j]-'0');
	}
//	for(ll i=1;i<=K;i++,cout<<endl)
//		for(ll j=0;j<r[i].size();j++) cout<<r[i][j]<<" ";
	cin>>T;
	for(ll i=1;i<=T;i++){
		input();
		solve();
//		else
//			printf("132523761347\n");
	}
	return 0;
}


