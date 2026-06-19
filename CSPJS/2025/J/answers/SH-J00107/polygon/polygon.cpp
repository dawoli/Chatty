#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N=5e3+10,mod=998244353;
int n;
int a[N];
int ans;
int dp[510][510];
bool f=true;
void init(){
	for(int i=1;i<=50;i++){
		dp[i][0]=dp[i][i]=1;
	}for(int i=2;i<=50;i++){
		for(int j=1;j<i;j++){
			dp[i][j]+=dp[i-1][j]+dp[i-1][j-1];
			dp[i][j]%=mod;
//			cout<<dp[i][j]<<' ';
		}
//		cout<<endl;
	}
} 
void dfs(int i,int cnt,int mx){
	if(i>n){
		if(cnt>mx*2)ans++;
		ans%=mod;
		return ;
	}dfs(i+1,cnt,mx);
	dfs(i+1,cnt+a[i],a[i]);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=false;
	}sort(a+1,a+n+1);
	if(n<=20){
		dfs(1,0,0);
	}else if(f){
		init();
		for(int i=3;i<=n;i++){
			ans+=dp[n][i];
			ans%=mod;
		} 
	}else{
		dfs(1,0,0);
	}cout<<ans;
	return 0;
}
