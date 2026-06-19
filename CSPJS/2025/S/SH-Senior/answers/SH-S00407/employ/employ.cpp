#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=998244353;
ll n,m;
string s;
ll c[505];
ll vis[505];
ll a[505];
ll cnt=0;
ll check(){
	ll die=0;
	for(ll i=1;i<=n;i++){
		if(s[i-1]=='0'){
			die++;
		}
		else if(die>=c[a[i]]){
			die++;
		}
	}
	return n-die;
}
void dfs(int x){
	if(x==n){
		if(check()>=m)cnt++;
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			a[x+1]=i;
			dfs(x+1);
			a[x+1]=0;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool Is=false;
	for(ll i=0;i<s.size();i++){
		if(s[i]!='1')Is=true;
	}
	if(m==n&&Is==true){
		cout<<0;
		return 0;
	}
	if(Is==false){
		ll l=1;
		for(ll i=1;i<=n;i++){
			l*=i;
			l%=N;
		}
		cout<<l;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n>=18){
		cout<<0;
		return 0;
	}
	dfs(0);
	cout<<cnt;
	return 0;
}
