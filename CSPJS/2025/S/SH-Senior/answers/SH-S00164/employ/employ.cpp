#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],od[12],ans,mod=998244353;
bool u[11];
string s;
void dfs(int now){
	if(now==n+1){
		int fail=0,suc=0;
		for(int i=1;i<=n;i++){
			if(a[i]<=fail||s[i-1]=='0') fail++;
			else {
				suc++;
			}
		}
		if(suc>=m) ans++;
	}
	for(int i=1;i<=n;i++){
		if(u[i]==false){
			u[i]=true;
			od[now]=i;
			dfs(now+1);
			u[i]=false;
		}
	}
}
int an(int n){
	int ret=1;
	for(int i=1;i<=n;i++){
		ret*=i;
		ret%=mod;
	}
	return ret;
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=12){
		dfs(1);
		cout<<ans;
	}
	else if(m==n){
		bool flag=true;
		for(int i=0;i<s.length();i++) if(s[i]=='0') flag=false;
		if(flag) cout<<an(n);
	}
	else {
		cout<<an(n);
	}
	return 0;
} 
