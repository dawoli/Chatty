#include<bits/stdc++.h>

using namespace std;
int ans,n,a[10005],s[10005];
void dfs(int k,int x,int l){
	if(k>2*l){
		ans+=pow(2,x-1)%998244353;
		return ;
	}
	for(int i=x-1; i>=1; i--){
		dfs(a[i]+k,i,l);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) s[i]=a[i]+s[i-1];
	for(int i=n; i>=3; i--) dfs(a[i],i,a[i]);
	cout << ans%998244353;
	return 0;
}
