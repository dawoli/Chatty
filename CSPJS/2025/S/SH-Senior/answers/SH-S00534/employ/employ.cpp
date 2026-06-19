#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MXN = 500;
int n, m;
string s;
int c[MXN];
int ans;
bool vis[MXN];

void dfs(int x, int giveup, int ok){
	if (x == n+1){
			if (ok >= m) ans = (ans + 1) % MOD;
			//cout<<ok;
		return;
	}
	for (int i = 1; i <= n; i++){
		if (!vis[i]){
			//cout<<i<<"\n";
			vis[i] = true;
			if (giveup >= c[i]){
				dfs(x+1, giveup+1, ok);
			}
			if (giveup < c[i]){
				if (s[x-1] == '0'){
					dfs(x+1, giveup+1, ok);
				}
				if (s[x-1] == '1'){
					dfs(x+1, giveup, ok+1);
				}
				
			}
			vis[i] = false;
		}
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>s;
	for (int i = 1; i <= n; i++){
		cin>>c[i];
	}
	dfs(1, 0, 0);
	cout<<ans;
	
	return 0;
}
