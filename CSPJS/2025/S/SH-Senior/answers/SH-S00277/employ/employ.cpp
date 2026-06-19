#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M=998244353;
int n,m,p[505],cnt=0,chose[505],vis[505],ans=0;
bool s[505],flag=1;
int f(int x){
	if(x==1) return 1;
	return x*f(x-1);
}void dfs(int step){
	if(step==n+1){
		int cnt=0,m1=0;
		for(int i=1;i<=n;i++){
			if(cnt>=p[chose[i]]) cnt++;
			else if(s[i]==0) cnt++;
			else m1++;
		}
		if(m1>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			chose[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s[i]=c-'0';
		if(flag && !s[i]) flag=0;
	}for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]>0) cnt++;
	}
	if(flag){
		if(cnt<m) cout<<0;
		else cout<<f(m-cnt);
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
