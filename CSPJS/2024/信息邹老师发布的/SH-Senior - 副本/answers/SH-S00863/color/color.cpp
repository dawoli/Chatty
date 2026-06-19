#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[200009],mxa;
namespace N1e2{
	int dp[109][109][109];
	bool ok[109][109][109];
	ll dfs(int x,int y,int z){
		if(ok[x][y][z]) return dp[x][y][z];
		ok[x][y][z]=1;
		if(x>n) return dp[x][y][z]=0;
		return dp[x][y][z]=max(dfs(x+1,y,a[x])+(a[x]==z?z:0),dfs(x+1,a[x],z)+(a[x]==y?y:0));
	}
	void solve(){
		memset(dp,0,sizeof(dp));
		memset(ok,0,sizeof(ok));
		cout<<dfs(1,0,0)<<endl;
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		mxa=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mxa=max(mxa,a[i]);
		} 
		N1e2::solve();
	}
	return 0;
}

