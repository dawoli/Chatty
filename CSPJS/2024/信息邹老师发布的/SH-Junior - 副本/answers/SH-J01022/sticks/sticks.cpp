#include<bits/stdc++.h>
using namespace std;


int T, n;

void pt8(int t) {
	for(int i=1; i<=t; i++) cout << 8;
}

void test() {
	cin >> n;
	if(n == 1) cout << -1;
	else if(n == 2) cout << 1;
	else if(n == 3) cout << 7;
	else if(n == 4) cout << 4;
	else if(n == 5) cout << 2;
	else if(n == 6) cout << 6; // n is a positive integer! (which means n can't be 0) 
	else {
		int m = n % 7;
		if(m == 0) pt8(n / 7);
		else if(m == 1) cout << 10, pt8(n / 7 - 1); 
		else if(m == 2) cout << 18, pt8(n / 7 - 1);
		else if(m == 3) cout << 22, pt8(n / 7 - 1);
		else if(m == 4) cout << 20, pt8(n / 7 - 1);
		else if(m == 5) cout << 28, pt8(n / 7 - 1);
		else if(m == 6) cout << 68, pt8(n / 7 - 1);
	}
	cout << endl;
} 

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> T;
	while(T--) test();
	return 0;
} 


/*
5
1
2
3
6
18

-1
1
7
6
208
*/


