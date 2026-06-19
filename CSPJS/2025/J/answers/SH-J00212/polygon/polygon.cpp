#include<bits/stdc++.h>
using namespace std;
const int N = 5050, M = 998244353;
int n, a[N];
bool vis[N];
int cnt = 0;
int biary_query(int x){
	int l = 1, r = n;
	while(l < r){
		int mid = (l + r) / 2;
		if(a[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return l - 1;
}
void dfs(int dep, int limit, int c, int maxn, int maxd){
	if(dep == limit){
		if(c > 2 * maxn) cnt = (cnt + 1) % M;
		//cout << c << " " << biary_query(c)<< endl;
		return ;
	}
	for(int i = maxd; i <= n; i++){
		if(!vis[i]){
			vis[i] = true;
			dfs(dep + 1, limit, c + a[i], a[i], i);
			vis[i] = false;
		}
	} 
}
int tim(int x){
	int res = 1; 
	for(int i = n; i >= x; i--){
		res *= x;
	}
	return res;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int maxm = -1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxm = max(maxm, a[i]);
	}
	if(maxm == 1){
		int cnt = 0;
		for(int i = n - 2; i >= 1; i++){
			cnt = cnt % M + tim(i) % M;
		}
		cout << cnt % M << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = 3; i <= n; i++){
		dfs(0, i, 0, -1, 1);
		//cout << "-----" << endl;
	}
	cout << cnt << endl;
	return 0;
} 
