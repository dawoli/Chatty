#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int peo[N];
string s;
long long f[N];//f[i][j]表示前i个，j个不过 
int n,m;
int all=0;
/*void solve(){
	long long ans=1;
	int fei=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'){
			for(int j=fei;j<i;j++){
				f[j+1]=f[j]*all;
				f[j+1]%=MOD;
				all--;
			}
			fei++;
		}
		else
			for(int j=fei;j<i;j++){
				f[j+1]=f[j+1]*(g[n]-g[j])+f[j]*g[j];
				f[j+1]%=MOD;
				all--;
			}
	}
	for(int j=0;j<=n-m;j++){
		ans+=f[j];
	}
	cout<<ans;
}*/
int dfs(int p){
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	
	cin>>s;
	all=n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		peo[x]++;
	}
	long long ans=1;
	for(int i=1;i<=n;i++)
		ans*=i;
		ans%=MOD;
	cout<<ans;
	//solve();
	return 0;
}
