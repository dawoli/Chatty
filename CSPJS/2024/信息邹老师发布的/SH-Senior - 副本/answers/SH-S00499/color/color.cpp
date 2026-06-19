#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define up(l,r,i) for(int i=(l);i<=(r);++i)

constexpr int N=2e5+7;

ll n,a[N],ans,dp[2008][2008];
bool vis[22];

void dfs(int p){
	if(p==n+1){
		ll ret=0;
		//for(int i=1;i<=n;++i)cout<<vis[i]<<" ";
		int pre1=-1,pre2=-1;
		for(int i=1;i<=n;++i){
			if(vis[i]){
				if(pre1!=-1){
					if(a[i]==a[pre1]){
						ret+=a[i];
					}
				}
				pre1=i;
			}
			else{
				if(pre2!=-1){
					if(a[i]==a[pre2]){
						ret+=a[i];
					}
				}
				pre2=i;
			}
		}
		ans=max(ans,ret);
		//cout<<pre1<<' '<<pre2<<' '<<ret<<'\n';
		return;
	}
	vis[p]=0;
	dfs(p+1);
	vis[p]=1;
	dfs(p+1);
	vis[p]=0;
}

void solve(){
	if(n<=20){
		cin>>n;ans=0;
		up(1,n,i)cin>>a[i];
		dfs(1);
		cout<<ans<<'\n';
	}
	else{
		cout<<"0\n";
	}
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int tc;cin>>tc;
	while(tc--){
		solve();
	}
	return 0;
}

