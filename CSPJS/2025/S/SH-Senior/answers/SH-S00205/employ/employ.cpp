#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
#define pb push_back
#define mod 998244353
long long n,m,a[509],c[509],flag=1,ans;
string s;
void dfs(long long cnt,long long now,long long du){
	//cout<<cnt<<' '<<now<<' '<<du<<'\n';
	if(now==n){
		if(cnt>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(du&(1<<i)) continue;
		else{
			if(now-cnt>=c[i]||a[now+1]==0) dfs(cnt,now+1,du^(1<<i));
			else dfs(cnt+1,now+1,du^(1<<i));
		}
	}
}
void solve1(){
	dfs(0,0,0);
	cout<<ans%mod;
}
void solveA(){
	long long cnt=0;
	for(int i=1;i<=n;i++) if(c[i]==0) cnt++;
	if(n-cnt<m) cout<<0;
	else{
		long long ans=1;
		for(int i=1;i<=n;i++) ans*=i,ans%=mod;
		cout<<ans;
	}
}
void solve(){
	cin>>n>>m>>s;s=' '+s;
	for(int i=1;i<=n;i++) a[i]=(s[i]-'0'),flag=flag&&a[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18) solve1();
	if(flag) solveA();
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long T=1;//cin>>T;
	while(T--) solve(); 
}
//subscribe tasho11y(uid=1385732) in bilibili(in luogu)!!!
//at 3:40