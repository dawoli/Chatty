#include <bits/stdc++.h>
using namespace std;
int n;
bool vis[128][128] = {false};
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		char c1, c2;
		cin >> c1 >> c2;
		if(!vis[c1][c2]){
			vis[c1][c2] = true;
			ans++;
		}
	}
	cout << 52-ans << endl;
	return 0;
}
