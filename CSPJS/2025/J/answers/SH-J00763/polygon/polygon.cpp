#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long ans = 0;
int a[5005];
bool vis[5005];
int n;
void dfs(int d,int c,int sum,int maxn,bool f){
	if(d == n+2) return;
	if(c>=3 && sum>2*maxn && f){
		ans++;
		ans%=mod;
	}
	dfs(d+1,c,sum,maxn,false);
	vis[d]=true;
	dfs(d+1,c+1,sum+a[d],max(maxn,a[d]),true);
	vis[d]=false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0,0);
	cout<<ans%mod;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
