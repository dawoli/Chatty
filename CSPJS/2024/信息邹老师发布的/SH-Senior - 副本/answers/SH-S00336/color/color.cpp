#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],stp[200005],fd[200005],vis[1000006],ans;
vector<ll>e[1000006];
void dfs(ll now,ll val,ll bk){
	if(now==n){
		ans=max(ans,val);
		return ;
	}
	if(stp[now]){
		ll res=0,nbk=0;
		for(ll i=now+2;i<stp[now];i++){
			if(a[i]==a[i-1]){
				res+=a[i];
			}
		}
		if(stp[now]!=now+1){
			nbk=1;
		}
		dfs(stp[now],val+res+a[now],nbk);
	}
	if(bk&&stp[now-1]){
		dfs(now-1,val,0);
	}
	if(stp[now]!=now+1){
		dfs(now+1,val,0);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		for(ll i=1;i<=fd[0];i++){
			vis[fd[i]]=0;
			while(!e[fd[i]].empty()){
				e[fd[i]].pop_back();
			}
			fd[i]=0;
		}
		fd[0]=0;
		ans=0;
		memset(stp,0,sizeof(stp));
		
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			if(vis[a[i]]==0){
				vis[a[i]]=1;
				fd[0]++;
				fd[fd[0]]=a[i];
			}
			e[a[i]].push_back(i);
		}
		for(ll i=1;i<=fd[0];i++){
			for(ll j=1;j<e[fd[i]].size();j++){
				stp[e[fd[i]][j-1]]=e[fd[i]][j];
			}
		}
//		
//		for(ll i=1;i<=n;i++){
//			cout<<stp[i]<<' ';
//		}
//		cout<<'\n';
		dfs(1,0,0);
		cout<<ans<<'\n';
	}
}
