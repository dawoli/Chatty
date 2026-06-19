#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
int a[N],now[N];
int n,m;
bool vis[N];
string b;
typedef long long ll;
ll mod=998244353;
ll ans=0;
bool check(){
	int sum=0;
	for(int i=1;i<b.size();i++){
		if(sum>=a[now[i]]){
			sum++;
			continue;
		}
		if(b[i]=='0')sum++;
	}
	int ns=n-sum;
	if(ns>=m){
		return 1;
	}
	else return 0;
}
void dfs(int x){
	if(x==n+1){
		if(check())ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			now[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>b;
	b='0'+b;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
