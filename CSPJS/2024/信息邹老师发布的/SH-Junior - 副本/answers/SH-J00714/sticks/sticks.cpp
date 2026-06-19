#include<iostream>
#include<algorithm>
using namespace std;

int num[10][2] = {{7, 8}, {6, 0}, {6, 6}, {5, 2}, {4, 4}, {3, 7}, {2, 1}}, n, map[10], x = 0;
bool flag = 0;

void dfs() {
	if (n == 0) {
		flag = 1;
		return;
	}
	for (int i = 0; i < 7; i++) {
		if (num[i][1] == 0 && x == 0) {
			continue;
		}
		if (n >= num[i][0]) {
			map[x] = num[i][1];
			n -= num[i][0];
			x++;
			dfs();
			if (flag) {
				return;
			}
			n += num[i][0];
			x--;
		}
	}
	return; 
}

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		flag = 0;
		x = 0;
		dfs();
		if (!flag) {
			cout << -1 << "\n";
			continue;
		}
		sort(map, map + x);
		bool flag1 = 0;
		for (int j = 0; j < x; j++) {
			if (map[j] != 0) {
				cout << map[j];
				if (!flag1) {
					flag1 = 1;
					for (int k = 0; k < j; k++) {
						cout << 0;
					}
				}
			}
		}
		cout << "\n";
	}
	
	return 0;
}
