#include<iostream>
using namespace std;

int n, m, ans = 0;
bool sp = 1;
string s;
int c[550] = {0};
//dfs
int SeQ[550] = {0};
bool vis[550] = {0};

void dfs(int depth){
	if(depth > n){
		int failed = 0;
		for(int i = 1; i <= n; i++){
		    if(s[i - 1] == '0' || failed >= c[SeQ[i]]){
				failed++;
			}
		}
		if(n - failed >= m){
//			for(int i = 1; i <= n; i++){
//				cout << SeQ[i] << ' ';
//			}cout << endl;
			ans = (ans + 1) % 998244353;
		}
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		SeQ[depth] = i;
		vis[i] = 1;
		dfs(depth + 1);
		vis[i] = 0;
	}
	return;
} 

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '0'){
			sp = 0;
			break;
		}
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	if(sp){
		int cnt0_ = 0;
		for(int i = 1; i <= n; i++){
			if(c[i] == 0){
				cnt0_++;
			}
		}
		if(n - cnt0_ < m){
			cout << '0';
			return 0;
		}
		long long ooo = 1;
		for(int i = n; i >= 1; i--){
			ooo = (ooo * i) % 998244353;
		}
		cout << ooo;
		return 0;
	}

	dfs(1);
	cout << ans;
	
	return 0;
}
