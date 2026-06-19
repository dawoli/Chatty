#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 505;
const int mod = 998244353;
int n, m;
int s[maxn];
int w[maxn];
inline void solvea(){
	int ji = 1;
	for(int i = 1; i <= n; i++) ji = ji * i % mod;
	cout << ji << '\n';
	exit(0);
}
int p[maxn], cnt = 0;
int vst[maxn];
void dfs(int x, int num){
	if(x == n + 1){
		if(num >= m) cnt++;
		return ;
	}
	
	for(int i = 1; i <= n; i++){
		if(!vst[i]){
			vst[i] = 1;
			if(x - num - 1 >= w[i] || s[x] == 0) dfs(x + 1, num);
			else dfs(x + 1, num + 1);
			vst[i] = 0;
		}
	}
}
inline void solveb(){
	dfs(1, 0);
	
	cout << cnt << '\n';
	exit(0);
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	bool flaga = true;
	for(int i = 1; i <= n; i++){
		char c;
		cin >> c;
		s[i] = c - '0';
		if(s[i] == 0) flaga = false;
	}
	
	for(int i = 1; i <= n; i++) cin >> w[i];
	
	if(flaga) solvea();
	
	if(n <= 18) solveb();
	
	if(m == n){
		if(flaga) solvea();
		else cout << "0\n";
		return 0;
	}
	return 0;
}
