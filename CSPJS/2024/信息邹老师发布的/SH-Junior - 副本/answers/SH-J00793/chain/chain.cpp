#include<bits/stdc++.h>
using namespace std;
typedef int ll;
//为啥所有人词库都没有 1，还有答案是 1 啊？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？ 
const ll N=100009;
unordered_map<ll,ll> perscnt[N];
vector<ll> f[N],s[N];
vector<bool> ok[N],vis[N];
ll colorcnt[N*2];
ll ans[109][N*2]; 
ll n,k,q;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
    	cin>>n>>k>>q;
    	for(ll i=1;i<=n;i++) perscnt[i][1]=0,s[i].clear(),f[i].clear(),ok[i].clear(),vis[i].clear();
		colorcnt[1]=0;
    	for(ll i=1;i<=n;i++){
    		ll x; cin>>x;
    		s[i].push_back(x);
    		for(ll j=1;j<=s[i][0];j++){
    			ll x; cin>>x;
    			s[i].push_back(x);
    			if(s[i][j]==1){
    				perscnt[i][1]++;
    				colorcnt[1]++;
				}
			}
			f[i].resize(s[i][0]+1);
			ok[i].resize(s[i][0]+1);
			vis[i].resize(s[i][0]+1);
		}
		for(ll i=1;i<=100;i++) for(ll j=1;j<=200000;j++) ans[i][j]=0;
		for(ll r=1;r<=100;r++){
			for(ll i=1;i<=n;i++) for(ll j=1;j<=s[i][0];j++){
				ok[i][j]=(perscnt[i][s[i][j]]!=colorcnt[s[i][j]]);
				f[i][j]=f[i][j-1]+ok[i][j]; 
			}
			for(ll i=1;i<=n;i++) for(ll j=1;j<=s[i][0];j++){
				perscnt[i][s[i][j]]=0;
				colorcnt[s[i][j]]=0;
				if(f[i][j-1]-f[i][max(j-k,0)]!=0) vis[i][j]=1;
			}
			for(ll i=1;i<=n;i++) for(ll j=1;j<=s[i][0];j++){
				if(vis[i][j]){
					perscnt[i][s[i][j]]++;
					colorcnt[s[i][j]]++;
					ans[r][s[i][j]]=1;
					vis[i][j]=0;
				}
			} 
		}
		for(ll i=1;i<=n;i++) for(ll j=1;j<=s[i][0];j++) perscnt[i][s[i][j]]=0,colorcnt[s[i][j]]=0;
		while(q--){
			ll a,b;
			cin>>a>>b;
			cout<<ans[a][b]<<"\n";
		}
	}
    return 0;
}
