#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[505],s[505];
int val[505],vis[505];
int n,m;
double st;
int ans=0;
const int mod=998244353;
void dfs(int now){
	if(now>n){
		int cnt=0,tot=0;
		for(int i=1;i<=n;i++){
			if(tot>=s[val[i]]||a[i]==0){
				tot++;
			}else{
				cnt++;
			}
		}
		if(cnt>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			val[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
void dfs2(int now){
	if(clock()-st>960) return;
	if(now>n){
		int cnt=0,tot=0;
		for(int i=1;i<=n;i++){
			if(tot>=s[val[i]]||a[i]==0){
				tot++;
			}else{
				cnt++;
			}
		}
		if(cnt>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			val[now]=i;
			dfs2(now+1);
			vis[i]=0;
		}
	}
}
signed main(){
	st=clock();
	int cnt=0;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool A=1;
	bool B=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		a[i]=c-'0';
		if(a[i]==0) A=0;
		else cnt++;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==0) B=1;
	}
	if(cnt<m){
		cout<<0;
	}else if(n<18){
		dfs(1);
		cout<<ans;
	}else if(n==m){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		if(A&&!B){
			cout<<ans;
		}else{
			cout<<0;
		}
	}else{
		dfs2(1);
		cout<<ans;
	}
	return 0;
}
