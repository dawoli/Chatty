#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100001][4],m,num[4],f[100001][4];
ll ans;
void dfs(int u,ll sum){
	if(u>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;++i){
		if(!f[u][i]&&num[i]<m){
			if(u){
				f[u][i]=1;
				num[i]++;
			}
			dfs(u+1,sum+a[u][i]);
			if(u){
				f[u][i]=0;
				num[i]--;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(num,0,sizeof(num));
		memset(f,0,sizeof(f));
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				cin>>a[i][j];
			}
		}
		m=n/2;
		ans=0ll;
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}
