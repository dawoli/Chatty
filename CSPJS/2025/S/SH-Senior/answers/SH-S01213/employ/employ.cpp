#include<bits/stdc++.h>
using namespace std;
int n,m,p[505],c[505],a[505],ans,mod=998244353,re;
string s;
bool vis[505],f=false;
void dfs(int x){
	if (x == n+1){
		int cnt=0,res=0;
		for (int i=1;i<=n;i++){
			if (cnt >= c[a[i]]){
				cnt++;
				continue;
			}
			if (p[i] == 0) cnt++; 
			else res++;
		}
		if (res >= m) ans++;
		ans%=mod;
		return;
	}
	for (int i=1;i<=n;i++){
		if (vis[i]) continue;
		a[x] = i;
		vis[i] = true;
		dfs(x+1);
		vis[i] = false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i=0;i<n;i++){
		p[i+1] = s[i]-'0';
		if (p[i+1] == 0) f = true;
	}
	for (int i=1;i<=n;i++){
		cin >> c[i];
		if (c[i] != 0) re++;	
	}
	if (f) dfs(1);
	else {
		ans = 1;
		for (int i=1;i<=re;i++){
			ans *= i;
			ans %= mod;
		}
	}
	cout << ans%mod << endl;
	return 0;
}
