#include<bits/stdc++.h> //I fuck CCF 
#define int long long //我要上迷惑行为大赏 
using namespace std;
const int N=510,mod=998244353;
int n,m;
int a[N],c[N];
int t;
int ans;
bool f[N];
int dp[N][N];
string s;
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'||cnt>=c[i])cnt++;
	}if(n-cnt>=m)return true;
	return false;
}
void init(){
	for(int i=0;i<=500;i++){
		dp[i][0]=dp[i][i]=1;
	}for(int i=2;i<=500;i++){
		for(int j=1;j<i;j++){
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
			dp[i][j]%=mod; 
//			cout<<dp[i][j]<<' ';
		}
//		cout<<endl;
	}
}
void dfs(int u){
	if(u>n){
		if(check())ans++;
		ans%=mod;
		return ;
	}for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=true;
			c[u]=a[i];
			dfs(u+1);
			f[i]=false;
		}
	}
}
bool g(string s){
	for(int i=0;i<s.length();i++){
		if(s[i]!='1')return false;
	}return true;
} 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i])t++;
	}if(n<=11){
		dfs(1);
	}else if(g(s)){
		init();
		ans=dp[n][t];
//		cout<<ans<<' ';
		for(int i=n-t;i>=1;i--){
			ans*=i;
			ans%=mod;
		}if(n-t<m)ans=0;
	}cout<<ans;
	/* 
	10 5
	1101111011
 	6 0 4 2 1 2 5 4 3 3
	*/
	return 0;
} 
