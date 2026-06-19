#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int li[510];
bool vis[510];
ll cnt = 0;
int n, m; 
string s; 
int jujue = 0;
int luru = 0;
void dfs(int deep){
	if (deep == n && m == luru) {
		cnt++;
		return;
	}
	for (int i = 1; i <= n; i++){
		if (vis[i]) continue;
		if (li[i] >= jujue || s[deep] == '0'){
			jujue++;
		} else {
			luru++;
		}
		vis[i] = true;
		dfs(deep+1);
		vis[i] = false;
		if (li[i] >= jujue || s[deep] == '0'){
			jujue--;
		} else {
			luru--;
		}
	}
}
// Â¼ÈëÌõ¼ş£ºs[i] = 0 ÇÒ i < c
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++){
		cin >> li[i];
	}
	dfs(1);
	cout << cnt << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
