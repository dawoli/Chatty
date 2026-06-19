#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100009;
ll n,k,Q,l[N],r[N],c[N];
bool valid=0;
vector<ll> word[N];
void dfs(ll a,ll q,ll cnt,ll pre){
	if(cnt==r[q]){
		ll x=-1;
		for(ll j=0;j<l[a];j++){
			if(c[q]!=pre){
				if(word[a][j]==pre){
					x=j;
				}
				else if(word[a][j]==c[q]&&x!=-1){
					if(j-x+1<=k){
						valid=1;
						return;
					}
				}
			}
			else{
				if(word[a][j]==pre){
					if(x==-1){
						x=j;
					}
					else{
						if(j-x+1<=k){
							valid=1;
							return;
						}
						x=j;
					}
				}
			}
		}
		return;
	}
	for(ll i=1;i<=n;i++){
		if(i==a)
			continue;
		ll x=-1;
		for(ll j=0;j<l[a];j++){
			if(x!=-1&&j-x+1<=k)
				dfs(i,q,cnt+1,word[a][j]);
			if(valid)
				return;
			if(word[a][j]==pre)
				x=j;
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		cin>>n>>k>>Q;
		for(ll i=1;i<=n;i++){
			cin>>l[i];
			for(ll j=1;j<=l[i];j++){
				ll w;
				cin>>w;
				word[i].push_back(w);
			}
		}
		for(ll q=1;q<=Q;q++){
			cin>>r[q]>>c[q];
			if(r[q]==1){
				bool b=0;
				for(ll i=1;i<=n;i++){
					ll x=-1;
					for(ll j=0;j<l[i];j++){
						if(c[q]!=1){
							if(word[i][j]==1){
								x=j;
							}
							else if(word[i][j]==c[q]&&x!=-1){
								if(j-x+1<=k){
									b=1;
									break;
								}
							}
						}
						else{
							if(word[i][j]==1){
								if(x==-1){
									x=j;
								}
								else{
									if(j-x+1<=k){
										b=1;
										break;
									}
									x=j;
								}
							}
						}
					}
					if(b)
						break;
				}
				cout<<b<<endl;
			}
			else{
				for(ll i=1;i<=n;i++){
					valid=0;
					dfs(i,q,1,1);
					if(valid)
						cout<<1<<endl;
						break;
				}
			}
		}
		for(ll i=1;i<=n;i++)
			word[i].clear();
	}
	return 0;
}
