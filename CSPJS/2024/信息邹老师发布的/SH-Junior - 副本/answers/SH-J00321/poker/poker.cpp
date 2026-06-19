#include <bits/stdc++.h>

using namespace std;

const int maxn = 1001;
string poker[maxn];
int arr[maxn] = {0};

int main () {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> poker[i];
		int num1 = 0;
		int num2 = 0;
		if (poker[i][0] == 'D') {
			num1 = 1;
		} else if (poker[i][0] == 'C') {
			num1 = 2;
		} else if (poker[i][0] == 'H') {
			num1 = 3;
		} else {
			num1 = 4;
		}
		if (poker[i][1] == 'A') {
			num2 = 1;
		} else if (poker[i][1] == 'T') {
			num2 = 10;
		} else if (poker[i][1] == 'J') {
			num2 = 11;
		} else if (poker[i][1] == 'Q') {
			num2 = 12;
		} else if (poker[i][1] == 'K') {
			num2 = 13;
		} else {
			num2 = poker[i][1] - '0';
		}
		arr[(num1 - 1) * 13 + num2]++;
	}
	
	int sum = 52;
	for (int i = 1; i <= 52; i++) {
		if (arr[i] != 0)  sum--;
	}
	cout << sum;
	return 0;
} 
