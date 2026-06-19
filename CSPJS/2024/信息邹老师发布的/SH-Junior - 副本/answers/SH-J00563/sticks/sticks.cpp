#include <bits/stdc++.h>
using namespace std;
int t, n;
int cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
char ans[50005], cn[50005];
stack <int> sta;
void dfs(int dep, int num){
	if (num == 0){
		while (sta.size()){
			cn[dep - sta.size() + 1] = sta.top();
			sta.pop();
		}if (cnt[1] == 0) return;
		if (strlen(ans + 1) == 0 || strlen(cn + 1) < strlen(ans + 1)){
			if (min(ans + 1, cn + 1) == cn){
				for (int i = 1; i <= dep; i++){
					ans[i] = cn[i];
				}
			}
		}return;
	}for (int i = min(num, 9); i >= 0; i--){
		sta.push(i);
		dfs(dep + 1, num - i);
		sta.pop();
	}
}
int main(){
	cin >> t;
	while (t--){
		freopen("sticks.in", "r", stdin);
		freopen("sticks.out", "w", stdout);
		cin >> n;
		if (n == 1){
			cout << -1;
			continue;
		}if (n <= 7){
		    for (int i = 1; i <= 9; i++){
				if (cnt[i] == n){
					cout << i << endl;
					break;
				}
			}continue;
		}for (int i = 1; i <= 50004; i++) ans[i] = '\0';
		dfs(0, n);
		cout << ans + 1 << endl;
		return 0;
	}
}
