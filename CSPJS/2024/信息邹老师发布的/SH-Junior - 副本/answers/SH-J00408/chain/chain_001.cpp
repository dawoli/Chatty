#include<bits/stdc++.h>
#define N 200010 
using namespace std;
typedef long long ll;
ll _,nP,k,Q,l1[N];
vector<ll> p[N];
bool ok[N];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>_;
	while(_--){
		cin>>nP>>k>>Q;ll n0;
		memset(ok,0,sizeof(ok));
		for(int i=1;i<=nP;++i){
			cin>>n0;p[i].push_back(0);
			for(int j=1;j<=n0;++j){
				ll u;cin>>u;
				p[i].push_back(u);
			}
		}
		for(int i=1;i<=nP;++i){
			for(int j=1;j<(int)p[i].size();++j)
				l1[i]=0;
			for(int j=1;j<(int)p[i].size();++j)
				if(p[i][j]==1) l1[j]=j;
				else l1[j]=l1[j-1];
			for(int j=1;j<(int)p[i].size();++j)
				ok[p[i][j]]|=(j-l1[j]+1<=k&&j-l1[j]+1>=2);
		}
		while(Q--){
			ll r,c;
			cin>>r>>c;
			cout<<ok[c]<<endl;
		}
	}
	return 0;
}

