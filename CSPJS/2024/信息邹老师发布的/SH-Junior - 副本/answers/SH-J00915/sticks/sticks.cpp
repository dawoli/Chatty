#include <bits/stdc++.h>
using namespace std;
int T, n;
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> T;
	while(T--) {
		cin >> n;
		if(n % 7 == 0) {
			for(int i = 1; i <= n / 7; ++i) {
				cout << 8;
			}
		}
		if(n % 7 == 1) {
			if(n == 1) {
				cout << -1;
			}
			else {
				cout << 10;
				for(int i = 1; i <= n / 7 - 1; ++i) {
					cout << 8;
				}
			}
		}
		if(n % 7 == 2) {
			cout << 1;
			for(int i = 1; i <= n / 7; ++i) {
				cout << 8;
			}
		}
		if(n % 7 == 3) {
			if(n == 3) {
				cout << 7;
			}
			else {
				cout << 22;
				for(int i = 1; i <= n / 7 - 1; ++i) {
					cout << 8;
				}
			}
		}
		if(n % 7 == 4) {
			if(n == 4) {
				cout << 4;
			}
			else {
				cout << 20;
				for(int i = 1; i <= n / 7 - 1; ++i) {
					cout << 8;
				}
			}
		}
		if(n % 7 == 5) {
			cout << 2;
			for(int i = 1; i <= n / 7; ++i) {
				cout << 8;
			}
		}
		if(n % 7 == 6) {
			cout << 6;
			for(int i = 1; i <= n / 7; ++i) {
				cout << 8;
			}
		}
		cout << endl;
	} 
	return 0;
}
// LIST OF ACCOUNTS TO ORZ
// ORZ JXY2011 
// ORZ LITTLEACBG
// ORZ LIAOYANXU
// ORZ COMPOSITE_FUNCTION
// ORZ TIANTIAN2021

// luogu account : 
// input this string into nutrimatic.org : nA{1,}ification
// choose one among all the result, for example a string s
// then change s into all capital letters
// change all the 'I' in s to '1', 'O' to '0'
// then the username is __ s __, where the s represents the string s after all the above operations
// for example : s = notification
// then the username is __N0T1F1CAT10N__ but it's wrong
// some guesses may be required

// SOLUTION : 
// Obviously every J T3 shuold be easy.
// Easy to know that number with the least digit will be smaller, so as much 8s as possible will be used.
// If n is a multiple of 7 then 888... will be the only least digit number and it is the minimum number.
// If n - 1 is a multiple of 7 then there should be some 8s and two numbers with 8 matches. The best choice is 10. So the minimum number is 108....
//     Corner case : n = 1 -> output -1
// If n - 2 is a multiple of 7 then 188... is the smallest
// If n - 3 is a multiple of 7 then 228... is the smallest
//     Corner case : n = 3 -> output 7
// If n - 4 is a multiple of 7 then 208... is the smallest
//     Corner case : n = 4 -> output 4
// If n - 5 is a multiple of 7 then 288... is the smallest
// If n - 6 is a multiple of 7 then 688... is the smallest
// Above will be all the possible conditions.
