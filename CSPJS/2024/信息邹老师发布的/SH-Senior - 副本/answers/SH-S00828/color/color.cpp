#include <bits/stdc++.h>
using namespace std;
int n, ans = -1;
vector<int> arr;
void dfs(int lr, int lb, int score, int pos) {
	if (pos == n) {
		ans = max(ans, score);
		return;
	}
	//染为红色
	dfs(pos, lb, score + ((lr != -1 && arr[lr] == arr[pos]) ? arr[pos] : 0), pos + 1) ;
	//染为蓝色 
	dfs(lr, pos, score + ((lb != -1 && arr[lb] == arr[pos]) ? arr[pos] : 0), pos + 1) ;
    return;
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		arr.clear();
		ans = -1;
		cin >> n;
		int tmp;
		for (int i = n; i >= 1; i--) {
			cin >> tmp;
			arr.push_back(tmp);
		} 
		dfs(-1, -1, 0, 0);
		cout << ans << endl;
	} 
	return 0;
} 
