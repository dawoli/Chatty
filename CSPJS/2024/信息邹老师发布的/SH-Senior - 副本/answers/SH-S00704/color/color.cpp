#include <bits/stdc++.h>
using namespace std;

int q;
int n,ans;
int num[105];
int color[105];

void dfs(int depth) {
	if(depth == n + 1) {
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i - 1; j >= 1; j--) {
				if(color[i] == color[j]) {
					if(num[i] == num[j]) {
						cnt += num[j];
					}
					break;
				} 
			}
		}
		ans = max(ans,cnt);
		return;
	}
	color[depth] = 0;
	dfs(depth+1);
	color[depth] = 1;
	dfs(depth+1);
}

int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> q;
	while(q--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> num[i];
		}
		ans = 0;
		dfs(1);
		cout << ans << endl;
	}
	return 0; 
}
