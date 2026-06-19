#include<bits/stdc++.h>
using namespace std;
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int x[60], y[60];
int book[100010];

int calculate(int s) {
	int cnt = 0;
	int num;
	while(s) {
		num = s % 10;
		cnt += a[num];
		s /= 10;
	}
	return cnt;
}

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
		if(x[i] <= 1) {
			y[i] = -1;
			cnt++;
		}	
	}
	for(int i = 1; ; i++) {
		book[i] = calculate(i);
		for(int j = 1; j <= n; j++) {
			if(x[j] == book[i] && !y[j]) {
				y[j] = i;
				cnt++;
			}
		}
		if(cnt == n) {
			break;
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << y[i] << "\n";
	}
	return 0;
}

