#include <bits/stdc++.h>
using namespace std;

const int maxn(5e3 + 5);
const int mod(998244353);
int a[maxn];
int ans = 0;
int n;

void dfs(int s, int r_, int sum){//枚举以a[i]为最长边的多边形情况 
	if(s == n){
		if(sum > r_){
			ans = (ans + 1) % mod;
		}
		return;
	}
	dfs(s + 1, r_, sum + a[s]);//选 
	dfs(s + 1, r_, sum);//不选 
	return;
}

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	for(int i = 0; i < n; i++){
		int r = 2 * a[i];//判断合理性
		//接下来的dfs选取木棍都在a[i]之后进行，其中a[i]为最长木棍
		dfs(i + 1, r, a[i]);//a[i]根木棍已经选好了 
	}
	cout << ans;
	return 0;
}
