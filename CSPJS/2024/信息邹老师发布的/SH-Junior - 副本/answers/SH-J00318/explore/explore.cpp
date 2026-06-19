#include<bits/stdc++.h>
using namespace std;
char Map[1001][1001];
string L;
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int n, m;
		cin >> n >> m; 
		int k;
		cin >> k;
		int xpos, ypos;
		cin >> xpos >> ypos;
		int dpos;
		cin >> dpos;
		for (int i = 1; i <= n; i++) {
			cin >> L;
			for (int j = 1; j <= m; j++) {
				Map[i][j] = L[j - 1]; 
			}
		}
		int sum = 0;
		for (int p = 1; p <= k; p++) {
			int xpos1, ypos1;
			if (dpos == 0) {
				xpos1 = xpos;
				ypos1 = ypos + 1;
			} else if (dpos == 1) {
				xpos1 = xpos + 1;
				ypos1 = ypos;
			} else if (dpos == 2) {
				xpos1 = xpos;
				ypos1 = ypos - 1;
			} else if (dpos == 3) {
				xpos1 = xpos - 1;
				ypos1 = ypos;
			}
			
			if (Map[xpos1][ypos1] == '.') {
				xpos = xpos1;
				ypos = ypos1;
				sum ++;
			} else {
				dpos = (dpos + 1) % 4;
			}
		}
		cout << sum + 1 << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0; 
} 
