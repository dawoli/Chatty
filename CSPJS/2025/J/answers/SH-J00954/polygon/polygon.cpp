#include <bits/stdc++.h>
using namespace std;
long long ans=0;
int a[5005];
int n;
bool vis[5005];
bool check(){
	int sum=0;
	int maxx=-1;
	for(int i=1;i<=n;i++){
		if(a[i]>maxx) maxx=a[i];
		if(!vis[i]) sum+=a[i];
	}
	return sum>2*maxx;
}
void dfs(int x){
	if(x==n) return;
	vis[x+1]=0;
	dfs(x+1);
	if(check()) ans++;
	vis[x+1]=1;
	dfs(x+1);
	if(check()) ans++;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=1;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=a[i];
		}
		sort(a+1,a+n+1);
		if(cnt>2*a[n]){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	dfs(0);
	cout<<ans%998244353;
}
