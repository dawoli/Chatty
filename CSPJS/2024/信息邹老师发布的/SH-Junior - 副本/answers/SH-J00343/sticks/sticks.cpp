#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
string dp[N];

void solve() {
	scanf("%d", &n);
	if (n < 2) {
		cout << "-1\n";
		return;
	} else if (n % 7 == 0) {
		for (int i = 1; i <= n / 7; i++)
			cout << 8;
		cout << "\n";
		return;
	} else if (n == 2) {
		cout << "1\n";
	} else if (n == 3) {
		cout << "7\n";
	} else if (n == 4) {
		cout << "4\n";
	} else if (n == 5) {
		cout << "2\n";
	} else if (n == 6) {
		cout << "6\n";
	} else if (n == 7) {
		cout << "8\n";
	} else if (n == 8) {
		cout << "10\n";
	} else if (n == 9) {
		cout << "18\n";
	} else if (n == 10) {
		cout << "23\n";
	} else if (n == 11) {
		cout << "20\n";
	} else if (n == 12) {
		cout << "28\n";
	} else if (n == 13) {
		cout << "68\n";
	} else if (n == 14) {
		cout << "88\n";
	} else if (n == 15) {
		cout << "108\n";
	} else if (n == 16) {
		cout << "202\n";
	} else if (n == 17) {
		cout << "200\n";
	} else if (n == 18) {
		cout << "208\n";
	} else if (n == 19) {
		cout << "288\n";
	} else if (n == 20) {
		cout << "688\n";
	} else if (n == 21) {
		cout << "888\n";
	} else if (n == 22) {
		cout << "1088\n";
	} else if (n == 23) {
		cout << "1888\n"; 
	} else if (n == 24) {
		cout << "2288\n"; 
	} else if (n == 25) {
		cout << "2088\n";
	} else if (n == 26) {
		cout << "2888\n"; 
	} else if (n == 27) {
		cout << "6888\n";
	} else if (n == 28) {
		cout << "8888\n"; 
	} else if (n == 29) {
		cout << "10888\n";
	} else if (n == 30) {
		cout << "18888\n";
	} else if (n == 31) {
		cout << "22888\n"; 
	} else if (n == 32) {
		cout << "20888\n"; 
	} else if (n == 33) {
		cout << "28888\n"; 
	} else if (n == 34) {
		cout << "68888\n";
	} else if (n == 36) {
		cout << "108888\n"; 
	} else if (n == 37) {
		cout << "188888\n"; 
	} else if (n == 38) {
		cout << "228888\n";
	} else if (n == 39) {
		cout << "628888\n"; 
	} else if (n == 40) {
		cout << "1228888\n"; 
	} else if (n == 41) {
		cout << "1028888\n"; 
	} else if (n == 42) {
		cout << "888888\n"; 
	} else if (n == 43) {
		cout << "2228888\n"; 
	} else if (n == 44) {
		cout << "2028888\n"; 
	} else if (n == 45) {
		cout << "6028888\n";
	}
}

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
