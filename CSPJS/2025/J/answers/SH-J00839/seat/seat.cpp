#include <bits/stdc++.h>
using namespace std;
int room[15][15] = {0};
int stu[110];
int d[4][2] = {{0,1},{1,0},{0,-1},{1,0}};
bool cmp(int x,int y) {
	return x > y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n * m;i++) {
		cin >> stu[i];
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			room[i][j] = 1;
		}
	}
	int p = stu[0];
	sort(stu,stu + n * m,cmp);
	int now = 0;
	int di = 0;
	bool flag = 0;
	for(int i = 1;i <= n;) {
		for(int j = 1;j <= m;) {
			room[i][j] = stu[now];
			if(di == 1) {
				di = 2;
			}
			if(di == 3) {
				di = 0;
			}
			if(room[i + d[di][0]][j + d[di][1]] != 0) {
				i += d[di][0];
				j += d[di][1];
			}
			else {
				di++;
				i += d[di][0];
				j += d[di][1];
			}
			now++;
			if(now == n * m) {
				flag = 1;
				break;
			}
		}
		if(flag) {
			break;
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(room[i][j] == p) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
