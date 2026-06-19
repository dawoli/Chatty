#include <bits/stdc++.h>
using namespace std;
struct Node {
	int x, id; //x为成绩，id为编号 
};
Node a[1000];
bool cmp(Node x, Node y) {
	return x.x > y.x;
}
int main() {
//	system("fc seat.out seat.ans");
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].x;
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	int nx = 1, ny = 1; //nx表示当前行数，ny表示当前列数 
	bool flag = true; //flag=true表示从上往下排,flag=false表示从下往上排 
	for (int i = 1; i <= n * m; i++) 
	{
		//找到了小R的位置 
		if (a[i].id == 1) {
			cout << ny << " " << nx << endl;
			return 0; 
		}
		//更新下一个人的位置 
		if (flag && nx == n) {
			flag = false;
			ny++;
		}
		else if ((!flag) && nx == 1) {
			flag = true;
			ny++;
		}
		else if (flag) {
			nx++;
		}
		else nx--;
	}
	return 0;
}
