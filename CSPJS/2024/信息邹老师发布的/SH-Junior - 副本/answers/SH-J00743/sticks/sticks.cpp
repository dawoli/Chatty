#include <bits/stdc++.h>
using namespace std;
int trans[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int sticks;
int num[(int)1e5];
unsigned long long c = 0, ans = 1e19, n = 0;

void dfs(int step){
	if (step > sticks) return;
	if (step == sticks){
		if (num[0] == 0) return;
		for (int i = 0; i < c; i++){
			n = n*10 + num[i];
		}
		if (n < ans){
			ans = n;
		}
		n = 0;
		return;
	}
	for (int i = 0; i < 9; ++i){
		num[c++] = i;
		dfs(step+trans[i]);
		num[c--] = 0;
	}
}
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);	
	int T;
	cin >> T;
	while (T--){
		cin >> sticks;
		if (sticks == 1) cout << -1 << endl;
		else if (sticks % 7 == 0) cout << string(sticks/7, '8');
		else if (sticks % 7 == 1) cout << 10<< string(sticks/7-1, '8');
		else{
			dfs(0);
			cout << ans << endl;
			ans = 1e9;
		}
	}
	return 0;
}
