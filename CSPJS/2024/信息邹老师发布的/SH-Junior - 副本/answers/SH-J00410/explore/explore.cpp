#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	int t = 0;
	while (t < T){
		int m, n, k, x, y, d;//d 0d 1n 2x 3b
		int dList[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		char map[1009][1009];
		cin>>m>>n>>k;
		cin>>y>>x>>d;
		x = x - 1;
		y = y - 1;
		for (int y = 0; y < m; y ++){
			for (int x = 0; x < n; x ++){
				cin >> map[y][x];
			}
		}
		long long cnt = 1;
		map[y][x] = 's';
		for (int i = 0; i < k; i++){
			if (map[y+dList[d][1]][x+dList[d][0]]=='x' ||  0>y+dList[d][1] || m<=y+dList[d][1] || 0>x+dList[d][0] || n<=x+dList[d][0]){
				d = (d + 1) % 4;
				//cout<<x<<y<<d<<endl;
			}
			else{
				x = x + dList[d][0];
				y = y + dList[d][1];
				if (map[y][x] == '.')cnt ++;
				map[y][x] = 's';
				//cout<<x<<y<<d<<endl;
			}
		}
		
		cout << cnt << endl;
		t += 1;
	}
	return 0;
}

