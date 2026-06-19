#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[507];
bool f[507];
int mod=998244353;
long long dfs(int i,int num){
	if(i==n+1){
		if(num<=n-m) return 1;
		return 0;
	}
	long long ret=0;
	for(int j=1;j<=n;j++){
		if(f[j]) continue;
		f[j]=1;
		if(num>=a[j] || s[i-1]=='0') ret=(ret+dfs(i+1,num+1))%mod;
		else{
			ret=(ret+dfs(i+1,num))%mod;
		}
		f[j]=0;
	}
	return ret;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<dfs(1,0);
	return 0;
}

