#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
string s;
int a[505];
bool vis[505];
ll ans;
ll mod=998244353;
void dfs(int t,int num,int cnt){
	if(num>=m&&t>n){
		ans++;
		ans%=mod;
	}
	if(n-cnt<m||t>n){
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[t]=='1'&&a[i]>cnt){
				dfs(t+1,num+1,cnt);
			}
			else{
				dfs(t+1,num,cnt+1);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s='?'+s;
	bool isa=1;
	int cnt0=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) cnt0--;
		if(s[i]!='1') isa=0;
	}
	if(cnt0<m){
		cout<<0<<endl;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
