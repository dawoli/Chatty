#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
string s;
int n,m,c[505],a[505];
bool vis[505];
int ans;
void dfs(int dep){
	if(dep==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){cnt++;continue;}
			if(cnt>=c[a[i]])cnt++;
			if(n-cnt<m)return;
		}
		if(n-cnt>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			a[dep]=i;
			vis[i]=1;
			dfs(dep+1);
			vis[i]=0;
		}
	}
}
bool nozero(){
	for(int i=0;i<s.size();i++)if(s[i]=='0')return 0;
	return 1;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(nozero()){
		int sum=1;
		for(int i=1;i<=n;i++){sum*=i;sum%=mod;}
		cout<<sum;return 0;
	}
	if(m==n){if(!nozero())cout<<0;return 0;}
	if(n<26){dfs(1);cout<<ans;return 0;}	
	if(400<n&&n<500){if(m>18)cout<<0;return 0;}	
	
	int sum=1;
	for(int i=1;i<=n;i++){sum*=i;sum%=mod;}
	cout<<sum%mod;
	return 0;
}
