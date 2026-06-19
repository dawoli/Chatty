#include <bits/stdc++.h>

using namespace std;

const bool red = true, blue = false;

int a[200002];
bool color[200002];

int dfs(int l, int d) {
	if (d == l) {
		int lastr = -1, lastb = -1;
		int c = 0;
		
		for (int i = 0; i < l; i++) {
			if (color[i] == red) {
				if (lastr == -1) {
					lastr = i;
					continue;
				}
				
				if (a[lastr] == a[i]) c += a[i];
				lastr = i;
			}
			
			if (color[i] == blue) {
				if (lastb == -1) {
					lastb = i;
					continue;
				}
				
				if (a[lastb] == a[i]) c += a[i];
				lastb = i;
			}
		}
		
		return c;
	}
	
	color[d] = red;
	int c1 = dfs(l, d + 1);
	color[d] = blue;
	int c2 = dfs(l, d + 1);
	
	return max(c1, c2);
}

using namespace std;

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		cout << dfs(n, 0) << endl;
	}
}
