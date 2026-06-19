#include <bits/stdc++.h>
using namespace std;
long long ans, n, a[5001];

void dfs(long long sum, long long cur, long long maxx, long long cnt){
	if(sum + a[cur] > a[cur] * 2 && cnt + 1 >= 3){
		ans++;
		ans %= 988244353;
	}
	if(cur == n){
		return;
	}
	dfs(sum + a[cur], cur + 1, a[cur], cnt + 1);
	dfs(sum, cur + 1, maxx, cnt);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a + 1, a + n + 1);
	dfs(0, 1, 0, 0);
	cout<<ans;
} 
