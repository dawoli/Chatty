#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int n, ans, duel[N], vis[N];
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> duel[i];
	}
	sort(duel, duel + n);
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			if (duel[j] > duel[i] && vis[i] != -1 && vis[j] != 1 && vis[j] != -1){
				vis[j] = 1;
				vis[i] = -1;
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (vis[i] != -1){
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
