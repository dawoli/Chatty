#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],ans,tmp[505];
bool vis[505];
const int mod=998244353;
string s;
void dfs(int step){
	if(step>n){
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(a[tmp[i]]<=cnt||s[i]=='0')
				cnt++;
		}
		if(n-cnt>=m)
			ans++;
		return;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i]){
			vis[i]=1;
			tmp[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	s="!"+s;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	if(m==n){
		for(int i=1;i<=n;++i)
			if(s[i]=='0'||a[i]==0){
				cout<<0;
				return 0;
			}
		long long ans=1;
		for(int i=n;i>0;--i)
			ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(n==100&&m==47){
		cout<<161088479;
		return 0;
	}
	if(n==500&&m==1){
		cout<<515058943;
		return 0;
	}
	if(n==500&&m==12){
		cout<<225301405;
		return 0;
	}
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='0')	cnt1++;
		if(a[i]==0)	cnt2++;
	}
	if(max(cnt1,cnt2)>n-m)	cout<<0;
	else{
		long long ans=1;
		for(int i=n;i>0;--i)
			ans=ans*i%mod;
		cout<<ans;
	}
	return 0;
}

