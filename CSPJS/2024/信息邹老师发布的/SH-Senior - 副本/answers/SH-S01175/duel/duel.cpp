#include <bits/stdc++.h>
using namespace std;
int n;
int monster[100005];
int vis[100005];
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> monster[i];
	}
	int ans = n;
	sort(monster,monster + n + 1);//从小到大排序 
	for(int i = 2;i <= n;i++) {
		if(monster[i] == monster[1])
			continue;
		for(int j = 1;j < i;j++) {
			if(monster[i] > monster[j] && vis[i] == 0 && vis[j] == 0) {
				ans--;
				vis[j] = 1;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
