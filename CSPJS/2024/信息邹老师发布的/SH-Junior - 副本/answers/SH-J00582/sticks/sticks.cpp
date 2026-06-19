#include <bits/stdc++.h>
using namespace std;

int t, n;
int stin[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int tp[20] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88};
//            0  1   2  3  4  5  6  7  8   9   10  11  12  13  14

void solve_A() {
	int cnt = n / 7;
	for (int i = 1; i <= cnt; ++ i)
		cout << "8";
	cout << endl;
}

void solve_B() {
	if (n == 1) {
		cout << "-1" << endl;
		return;
	}
	int cnt = (n - 8) / 7;
	cout << "10";
	for (int i = 1; i <= cnt; ++ i)
		cout << "8";
	cout << endl;
}

int zhengjie(int n) { // 也有可能不是 
	int cnt = n % 7;
	int cnt_8 = n / 7;
	switch(cnt) {
		case 2:{
			cout << "1";
			break;
		}
		case 3:{
			cout << "22";
			cnt_8 --;
			break;
		}
		case 4:{
			cout << "20";
			cnt_8 --;
			break;
		}
		case_5:{
			cout << "2";
			break;
		}
		case 6:{
			cout << "6";
			break;
		}
	}
	for (int i = 1; i <= cnt_8; ++ i)
		cout << "8";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while (t --) {
		cin >> n;
		if (n % 7 == 0) solve_A();
		else if (n % 7 == 1) solve_B();
		else {
			if (n < 14) cout << tp[n] << endl;
			else zhengjie(n);
		}
	}
	return 0;
} 
/*
5
1
2
3
6
18
*/
