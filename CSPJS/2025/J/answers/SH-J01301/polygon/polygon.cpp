#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
bool vis[5005];
void dfs(int step,int num,int maxa) {
	if(step>n) return ;
	if(step>=3&&num>maxa*2) ans++;
	for(int i=1;i<=n;i++) {
		if(vis[i]) continue;
		vis[i]=true;
		dfs(step+1,num+=a[i],max(maxa,a[i]));
		if(step>=3) dfs(step,num,maxa);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	dfs(1,0,0);
	printf("%lld",ans%998244353);
	return 0;
}
