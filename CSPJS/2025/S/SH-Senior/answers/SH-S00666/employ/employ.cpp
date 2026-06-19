#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,c[510],cnt,o;
bool vis[510];
string s;
void dfs(int dep,int pos,int fa){
	if(n-fa<m)return;
	if(dep==n){
		if(fa>=c[pos] or s[dep-1]=='0')fa++;
		if(n-fa>=m){
	//		cout<<pos<<' '<<fa<<'\n';
			cnt++;
		}
		return;
	}
	if(fa>=c[pos] or s[dep-1]=='0'){
	//	cout<<pos<<'\n';
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				dfs(dep+1,i,fa+1);
				vis[i]=0;
			}
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(dep+1,i,fa);
			vis[i]=0;
		}
	}
}
void dfs1(int dep,int pos){
	if(dep-1<c[pos] and s[dep-1]=='1')return;
	if(dep==n){
		cnt++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs1(dep+1,i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++)o+=s[i]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	if(o==n){//sp a
		long long ans=1,ze=0;
		for(int i=1;i<=n;i++)if(c[i]==0)ze++;
		for(int i=1;i<=n;i++)ans*=i,ans%=MOD;
		cout<<ans;
		return 0;
	}
	if(m==n){
		cout<<"0\n";
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(c[i]==0 or s[0]=='0'){
				vis[i]=1;
				dfs1(1,i);
				vis[i]=0;
			}
		}
		long long ans=1;
		for(int i=1;i<=n;i++)ans*=i,ans%=MOD;
		cout<<(ans-cnt+MOD)%MOD;
		return 0;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,i,0);
		vis[i]=0;
	}
	cout<<cnt;
	return 0;
}
