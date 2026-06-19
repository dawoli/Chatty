#include<bits/stdc++.h>
using namespace std;
int ans,n,a[114514];
void dfs(int k,int sum,int maxn) {
	if(k>n) {
		if(sum>maxn*2)ans++;
		return;
	}
	dfs(k+1,sum+a[k],a[k]);
	dfs(k+1,sum,maxn);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans;
}
