#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, m, p;
int a[1024];
string s;
int ans;

int vis[1024];
int c[1024];

void dfs(int ind){
	if(ind > n){
		/*for(int i = 1; i <= n; i ++){
			cout << c[i] << " ";
		}cout << endl;*/
		int cnt = 0;
		for(int i = 1; i <= n; i ++){
			if(cnt >= c[i])cnt ++;
			else if(s[i - 1] == '0')cnt ++;
		}
		//ans ++;
		if(n - cnt >= p)ans ++;
		return ;
	}
	for(int i = 1; i <= n; i ++){
		if(vis[i] == 0){
			vis[i] = 1;
			c[ind] = a[i];
			dfs(ind + 1);
			vis[i] = 0;
		}
	}
}


int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> p;
	cin >> s;
	for(int i = 1; i <= n; i ++){
		cin >>a[i];
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
