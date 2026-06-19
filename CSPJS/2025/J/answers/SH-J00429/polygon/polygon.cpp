#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N = 5e3+10, mod = 998244353;
int n;
int a[N];
int ans;
void dfs(int now, int sum, int mx, int cnt){
	if(cnt>=3 && sum>2*mx){
		ans = ((ans+1)%mod+mod)%mod;
	}
	for(int i=now+1; i<=n; ++i){
		dfs(i, sum+a[i], a[i], cnt+1);
	}
	return;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int sum = 0;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	dfs(0, 0, 0, 0);
	cout <<ans;
	return 0;
}
