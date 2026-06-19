#include <bits/stdc++.h>
using namespace std;
char c[100001];
int a[10001],b[10001],vis[10001],n,m;
long long ans;
bool ck(){
	long long cnt=0,k=n;
	for(int i = 1;i <= n;i++){
		if(cnt>=a[b[i]]||c[i]=='0') k--,cnt++;
	}
	return k>=m;
}
void dfs(int x){
	if(x==n+1){
		if(ck()){
			ans++;
			//cout << b[1] << ' ' << b[2] << ' ' << b[3] << '\n';
		}
		return;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		b[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> c+1;
	int cnt=0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(c[i]=='1') cnt++;
	}
	if(cnt==n){
		long long sum=1;
		for(int i = 1;i <= n;i++){
			sum*=i;
		}
		cout << sum%998244353 << '\n';
		return 0;
	}
	dfs(1);
	cout << ans%998244353;
	return 0;
}
