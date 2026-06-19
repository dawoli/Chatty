#include <bits/stdc++.h>

using namespace std;

struct map {
	int n;
	int m;
	int k;
}map_arr[11];

struct robot {
	int x;
	int y;
	int d;
}robot_arr[11];

string map1[1001];
int res[1001][1001] = {0};
int res1[11] = {0};

int main () {
	//freopen("explore.in", "r", stdin);
	//freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		cin >> map_arr[i].n >> map_arr[i].m >> map_arr[i].k;
		cin >> robot_arr[i].x >> robot_arr[i].y >> robot_arr[i].d;
 //....x 
 		for (int j = 1; j <= map_arr[i].n; j++) {
			cin >> map1[j];
		}
		for (int j = 1; j <= map_arr[i].k; j++) {
			//d == 0
			if (robot_arr[i].d == 0) {
				if (robot_arr[i].y + 1 >= 1 && robot_arr[i].y + 1 <= map_arr[i].m) {
					if (map1[robot_arr[i].x][robot_arr[i].y + 1] != 'x') {
						res[robot_arr[i].x][robot_arr[i].y + 1] = 1;
						robot_arr[i].y++;
					} else {
						robot_arr[i].d = (robot_arr[i].d + 1) % 4;
						res[robot_arr[i].x][robot_arr[i].y] = 1;
					}
					
				} else {
					robot_arr[i].d = (robot_arr[i].d + 1) % 4;
					res[robot_arr[i].x][robot_arr[i].y] = 1;
				}
			}
			//d == 1;
			if (robot_arr[i].d == 1) {
				if (robot_arr[i].x + 1 >= 1 && robot_arr[i].x + 1 <= map_arr[i].n) {
					if (map1[robot_arr[i].x + 1][robot_arr[i].y] != 'x') {
						res[robot_arr[i].x + 1][robot_arr[i].y] = 1;
						robot_arr[i].x++;
					} else {
						robot_arr[i].d = (robot_arr[i].d + 1) % 4;
						res[robot_arr[i].x][robot_arr[i].y] = 1;
					}
					
				} else {
					robot_arr[i].d = (robot_arr[i].d + 1) % 4;
					res[robot_arr[i].x][robot_arr[i].y] = 1;
				}
			}
			//d == 2
			if (robot_arr[i].d == 2) {
				if (robot_arr[i].y - 1 >= 1 && robot_arr[i].y - 1 <= map_arr[i].m) {
					if (map1[robot_arr[i].x][robot_arr[i].y - 1] != 'x') {
						res[robot_arr[i].x][robot_arr[i].y - 1] = 1;
						robot_arr[i].y--;
					} else {
						robot_arr[i].d = (robot_arr[i].d + 1) % 4;
						res[robot_arr[i].x][robot_arr[i].y] = 1;
					}
					
				} else {
					robot_arr[i].d = (robot_arr[i].d + 1) % 4;
					res[robot_arr[i].x][robot_arr[i].y] = 1;
				}
			}
			//d == 3
			if (robot_arr[i].d == 3) {
				if (robot_arr[i].x - 1 >= 1 && robot_arr[i].x - 1 <= map_arr[i].n) {
					if (map1[robot_arr[i].x - 1][robot_arr[i].y] != 'x') {
						res[robot_arr[i].x - 1][robot_arr[i].y] = 1;
						robot_arr[i].x--;
					} else {
						robot_arr[i].d = (robot_arr[i].d + 1) % 4;
						res[robot_arr[i].x][robot_arr[i].y] = 1;
					}
					
				} else {
					robot_arr[i].d = (robot_arr[i].d + 1) % 4;
					res[robot_arr[i].x][robot_arr[i].y] = 1;
				}
			}
		}
		
		int sum = 0;
		for (int j = 1; j <= map_arr[i].n; j++) {
			for (int k = 1; k <= map_arr[i].m; k++) {
				if (res[j][k] != 0)  {
					sum++;
				}
			}
		}
		res1[i] = sum;
		for (int j = 1; j <= map_arr[i].n; j++) {
			for (int k = 1; k <= map_arr[i].m; k++) {
				res[j][k] = 0;
			}
		}
	}
	
	for (int i = 1; i <= t; i++) {
		cout << res1[i] << endl;
	}
	return 0;
} 
